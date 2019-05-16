#include <iostream>

#include "Math.h"
#include "Parser.h"
#include "Visitor.h"
#include "InfixPrinterVisitor.h"
#include "DerivativeVisitor.h"


typedef InfixPrinterVisitor Printer;
typedef DerivativeVisitor Derivativer;

class MathContainer {
protected:
	AtomPtr expr, last;
	std::shared_ptr<Printer> printer;
	std::shared_ptr<Derivativer> derivativer;
public:
	MathContainer() : printer(std::make_shared<Printer>()) , derivativer(std::make_shared<Derivativer>()) {
	
	}
	void setExpr(AtomPtr t) {
		expr = t;
	}
	Atom* getExpr() {
		return expr.get();
	}
	Atom* derivate() {
		last = expr;
		expr.get()->Accept(derivativer.get());
		expr = derivativer.get()->get();
		return expr.get();
	}
	void print() {
		expr.get()->Accept(printer.get());
		std::cout << printer.get()->get() << std::endl;
	}
	void reset() {
		expr.reset();
		expr = last;
		last.reset();
	}
};



int main() {

	MathContainer mtc;
	Parser p;

	p.convertFromRPN("5x2^+");
	std::cout << "===============" << std::endl;
	p.convertFromInfix("(5 + x + 2*x)/(5*5) - 55 + 28.32 * x / x");
	std::cout << "===============" << std::endl;
	AtomPtr expr = p.getExpr();
	AtomPtr expr2 = std::make_shared<Add>(std::make_shared <Times>(std::make_shared<X>(), std::make_shared<X>()), std::make_shared<X>());

	mtc.setExpr(expr);
	mtc.print();
	std::cout << " f(1) = " << mtc.getExpr()->eq(1) << std::endl;
	mtc.derivate();
	mtc.print();
	std::cout << " f(1) = " << mtc.getExpr()->eq(1) << std::endl;

	return 0;
}
