#pragma once

#include <iostream>

class Const;
class X;
class Add;
class Minus;
class Times;
class Divide;
class Exp;

class Visitor
{
public:
	Visitor();
	virtual void VisitConst(Const*) = 0;
	virtual void VisitX(X* n) = 0;
	virtual void VisitAdd(Add* n) = 0;
	virtual void VisitMinus(Minus* n) = 0;
	virtual void VisitTimes(Times* n) = 0;
	virtual void VisitDivide(Divide* n) = 0;
	virtual void VisitExp(Exp* n) = 0;
	~Visitor();
};

