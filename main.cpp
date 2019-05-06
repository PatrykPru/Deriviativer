#include <iostream>

#include "Math.h"
#include "Visitor.h"
#include "InfixPrinterVisitor.h"

int main() {
	
	auto printer = std::make_shared<InfixPrinterVisitor>();
	AtomPtr root = std::make_shared <Add>(std::make_shared<X>(), std::make_shared<Const>(5));
	root.get()->Accept(printer.get());
	std::cout << printer.get()->get() << std::endl;
	root = std::make_shared <Exp>(std::make_shared<X>(), std::make_shared<Const>(5));
	root.get()->Accept(printer.get());
	std::cout << printer.get()->get() << std::endl;

	return 0;
}
