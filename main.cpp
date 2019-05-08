#include <iostream>

#include "Math.h"
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
	
	AtomPtr expr = std::make_shared<Times>(std::make_shared <Times>(std::make_shared<X>(), std::make_shared<X>()), std::make_shared<X>());
	MathContainer mtc;

	mtc.setExpr(expr);
	mtc.print();
	std::cout << " f(1) = " << mtc.getExpr()->eq(1) << std::endl;
	mtc.derivate();
	mtc.print();
	std::cout << " f(1) = " << mtc.getExpr()->eq(1) << std::endl;
	

	return 0;
}
