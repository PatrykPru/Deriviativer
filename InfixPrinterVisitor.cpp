#include "InfixPrinterVisitor.h"

#include "Math.h"

#include <string>

template <typename T>
void InfixPrinterVisitor::VisitBinary(T* n, const char& a)
{
	if (n != nullptr) {
		auto printer = std::make_shared <InfixPrinterVisitor>();
		if (n->left != nullptr && n->right != nullptr) {
			n->left->Accept(printer.get());
			output = printer.get()->get();
			output += " ";
			output += a;
			output += " ";
			n->right->Accept(printer.get());
			output += printer.get()->get();
			return;
		}
		if (n->left != nullptr) {
			n->left->Accept(printer.get());
			output = printer.get()->get();
			return;
		}
		if (n->right != nullptr) {
			n->right->Accept(printer.get());
			output = printer.get()->get();
			return;
		}
		output = "";
		return;
	}
}

std::string InfixPrinterVisitor::wrapper(const std::string& word)
{
	return "("+word+")";
}

InfixPrinterVisitor::InfixPrinterVisitor() : output("")
{

}

void InfixPrinterVisitor::VisitConst(Const* n)
{
	if (n != nullptr) {
		output = std::to_string(n->val); 
	}
}

void InfixPrinterVisitor::VisitX(X* n)
{
	if (n != nullptr) output = "x";
}

void InfixPrinterVisitor::VisitAdd(Add* n)
{
	VisitBinary<Add>(n, '+');
}

void InfixPrinterVisitor::VisitMinus(Minus* n)
{
	VisitBinary<Minus>(n, '-');
}

void InfixPrinterVisitor::VisitTimes(Times* n)
{
	VisitBinary<Times>(n, '*');
}

void InfixPrinterVisitor::VisitDivide(Divide* n)
{
	VisitBinary<Divide>(n, '/');
}

void InfixPrinterVisitor::VisitExp(Exp* n)
{
	if (n != nullptr) {
		auto printer = std::make_shared <InfixPrinterVisitor>();
		if (n->base != nullptr && n->power != nullptr) {
			n->base->Accept(printer.get());
			output = printer.get()->get();
			output += "^";
			n->power->Accept(printer.get());
			output += printer.get()->get();
			return;
		}
		if (n->base != nullptr) {
			n->base->Accept(printer.get());
			output = printer.get()->get();
			return;
		}
		output = "";
		return;
	}
}

std::string InfixPrinterVisitor::get()
{
	return wrapper(output);
}


InfixPrinterVisitor::~InfixPrinterVisitor()
{

}
