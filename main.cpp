#include <iostream>

#include "Math.h"
#include "Visitor.h"
#include "InfixPrinterVisitor.h"
#include "DerivativeVisitor.h"


typedef InfixPrinterVisitor Printer;
typedef DerivativeVisitor Derivativer;

class MathContainer {
protected:
	AtomPtr tree, last;
	std::shared_ptr<Printer> printer;
	std::shared_ptr<Derivativer> derivativer;
public:
	MathContainer() : printer(std::make_shared<Printer>()) , derivativer(std::make_shared<Derivativer>()) {
	
	}
	void setTree(AtomPtr t) {
		tree = t;
	}
	AtomPtr getTree() {
		return tree;
	}
	AtomPtr derivate() {
		last = tree;
		tree.get()->Accept(derivativer.get());
		tree = derivativer.get()->get();
		return tree;
	}
	void print() {
		tree.get()->Accept(printer.get());
		std::cout << printer.get()->get() << std::endl;
	}
	void reset() {
		tree.reset();
		tree = last;
		last.reset();
	}
};

int main() {
	
	AtomPtr root = std::make_shared<Times>(std::make_shared <Times>(std::make_shared<X>(), std::make_shared<X>()), std::make_shared<X>());
	//AtomPtr root = std::make_shared <Exp>(std::make_shared<X>(), std::make_shared<Const>(5));
	MathContainer mtc;

	mtc.setTree(root);
	std::cout << mtc.getTree().get()->eq(2) << std::endl;
	mtc.print();
	std::cout << mtc.derivate().get()->eq(2) << std::endl;
	mtc.print();

	return 0;
}
