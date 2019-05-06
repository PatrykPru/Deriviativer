#include <iostream>

#include "Math.h"
#include "Visitor.h"
#include "InfixPrinterVisitor.h"
#include "DerivativeVisitor.h"

int main() {
	
	auto printer = std::make_shared<InfixPrinterVisitor>();
	auto deriv = std::make_shared<DerivativeVisitor>();
	//AtomPtr root = std::make_shared <Times>(std::make_shared<X>(), std::make_shared<Const>(5));
	AtomPtr root = std::make_shared <Divide>(std::make_shared<X>(), std::make_shared<Const>(5));
	root.get()->Accept(deriv.get());
	AtomPtr rootDerived = deriv.get()->get();
	rootDerived.get()->Accept(printer.get());
	std::cout << printer.get()->get() << std::endl;
	//root = std::make_shared <Exp>(std::make_shared<X>(), std::make_shared<Const>(5));
	//root.get()->Accept(printer.get());
	//std::cout << printer.get()->get() << std::endl;

	return 0;
}
