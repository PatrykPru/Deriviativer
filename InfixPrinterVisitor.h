#pragma once

#include "Visitor.h";

class InfixPrinterVisitor : public Visitor
{
protected:
	std::string output;
	template <typename T>
	void VisitBinary(T*, const char&);
	std::string wrapper(const std::string&);
public:
	InfixPrinterVisitor();
	void VisitConst(Const*);
	void VisitX(X*);
	void VisitAdd(Add*);
	void VisitMinus(Minus*);
	void VisitTimes(Times*);
	void VisitDivide(Divide*);
	void VisitExp(Exp*);
	std::string get();
	~InfixPrinterVisitor();
};

