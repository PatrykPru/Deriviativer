#include "DerivativeVisitor.h"




DerivativeVisitor::DerivativeVisitor()
{
}

template<typename T>
void DerivativeVisitor::VisitAddHelper(T* n)
{
	if (n != nullptr) {
		auto derivative = std::make_shared<DerivativeVisitor>();
		if (n->left.get() != nullptr && n->right.get() != nullptr) {
			n->left->Accept(derivative.get());
			AtomPtr a = derivative.get()->get();
			n->right->Accept(derivative.get());
			AtomPtr b = derivative.get()->get();
			root = std::make_shared<T>(a, b);
			return;
		}
		if (n->left.get() != nullptr) {
			n->left->Accept(derivative.get());
			root = derivative.get()->get();
			return;
		}
		if (n->right.get() != nullptr) {
			n->right->Accept(derivative.get());
			root = derivative.get()->get();
			return;
		}
	}
}

template<typename T, typename B>
void DerivativeVisitor::VisitTimesHelper(T* n)
{
	// a'b + ab' = apb + abp
	if (n != nullptr) {
		auto derivative = std::make_shared<DerivativeVisitor>();
		if (n->left.get() != nullptr && n->right.get() != nullptr) {
			n->left->Accept(derivative.get());
			AtomPtr ap = derivative.get()->get();
			AtomPtr b = n->right;
			n->right->Accept(derivative.get());
			AtomPtr a = n->left;
			AtomPtr bp = derivative.get()->get();
			root = std::make_shared<B>(std::make_shared<Times>(ap, b), std::make_shared<Times>(a, bp));
			return;
		}
		if (n->left.get() != nullptr) {
			n->left->Accept(derivative.get());
			root = derivative.get()->get();
			return;
		}
		if (n->right.get() != nullptr) {
			n->right->Accept(derivative.get());
			root = derivative.get()->get();
			return;
		}
	}
}

void DerivativeVisitor::VisitConst(Const* n)
{
	if(n != nullptr) root = std::make_shared<Const>(0);
}

void DerivativeVisitor::VisitX(X* n)
{
	if(n != nullptr) root = std::make_shared<Const>(1);
}

void DerivativeVisitor::VisitAdd(Add* n)
{
	VisitAddHelper<Add>(n);
}

void DerivativeVisitor::VisitMinus(Minus* n)
{
	VisitAddHelper<Minus>(n);
}

void DerivativeVisitor::VisitTimes(Times* n)
{
	VisitTimesHelper<Times, Add>(n);
}

void DerivativeVisitor::VisitDivide(Divide* n)
{
	VisitTimesHelper<Divide, Minus>(n);
	root = std::make_shared<Divide>(root, std::make_shared<Times>(n->right,n->right));
}

void DerivativeVisitor::VisitExp(Exp* n)
{
	auto poly = std::make_shared<Exp>(std::make_shared<X>(), std::make_shared<Add>(n->power, std::make_shared<Const>(-1)));
	root = std::make_shared<Times>(n->power, poly);
}


AtomPtr DerivativeVisitor::get()
{
	return root;
}

DerivativeVisitor::~DerivativeVisitor()
{
}
