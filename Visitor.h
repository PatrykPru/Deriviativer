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
	virtual void VisitX(X*) = 0;
	virtual void VisitAdd(Add*) = 0;
	virtual void VisitMinus(Minus*) = 0;
	virtual void VisitTimes(Times*) = 0;
	virtual void VisitDivide(Divide*) = 0;
	virtual void VisitExp(Exp*) = 0;
	virtual ~Visitor();
};

