#pragma once

#include "Visitor.h"
#include "Math.h"

#include <memory>

typedef std::shared_ptr<Atom> AtomPtr;

class DerivativeVisitor : public Visitor
{
public:
	AtomPtr root;
	template <typename T>
	void VisitAddHelper(T*);
	template<typename T, typename B>
	void VisitTimesHelper(T*);
public:
	DerivativeVisitor();
	void VisitConst(Const*);
	void VisitX(X*);
	void VisitAdd(Add*);
	void VisitMinus(Minus*);
	void VisitTimes(Times*);
	void VisitDivide(Divide*);
	void VisitExp(Exp*);
	AtomPtr get();
	~DerivativeVisitor();
};
