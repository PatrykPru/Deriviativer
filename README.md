# Derivative 3.0

```
AtomPtr root = std::make_shared<Times>(std::make_shared <Times>(std::make_shared<X>(), std::make_shared<X>()), std::make_shared<X>());
AtomPtr roots = std::make_shared <Exp>(std::make_shared<X>(), std::make_shared<Const>(5));
	
MathContainer mtc;
mtc.setTree(root);
std::cout << mtc.getTree().get()->eq(2) << std::endl;
mtc.print();
std::cout << mtc.derivate().get()->eq(2) << std::endl;
mtc.print();
```