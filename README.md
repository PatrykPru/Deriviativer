# Derivative 3.0

To make a driffrent matematical function you need to create one of the inteligent pointer:
> To create a Math Constant with number inside
```
std::make_shared <Const>(1);
```
> To create a Math Variable X 
```
std::make_shared <X>();
```
>
>
> If you want to get a derivatived function you have to use a special Math Container which simplify usage of objects.
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