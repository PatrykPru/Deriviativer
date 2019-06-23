# Derivative 3.0

Project was created for programing class at Warsaw University of Technology.

### To make a driffrent matematical function you need to create one of the smart pointers:
+ To create a Math **Constant** with number inside brackets
```cpp
std::make_shared <Const>(1);
```
+ To create a Math **Variable X** 
```cpp
std::make_shared <X>();
```
+ To create a Math **Addition**
```cpp
std::make_shared <Add>(std::make_shared<X>(), std::make_shared<X> ());
```
+ To create a Math **Subtraciton**
```cpp
std::make_shared <Minus>(std::make_shared<X>(), std::make_shared<X> ());
```
+ To create a Math **Multipliaction**
```cpp
std::make_shared <Times>(std::make_shared<X>(), std::make_shared<X> ());
```
+ To create a Math **Division**
```cpp
std::make_shared <Divide>(std::make_shared<X>(), std::make_shared<X> ());
```
+ To create a Math **Exponential** 
```cpp
std::make_shared <Exp>(std::make_shared<X>(), std::make_shared<Const> (2));
```


#### If you want to get a derivatived function you have to use a special Math Container which simplify usage of objects.
```cpp
AtomPtr root = std::make_shared<Times>(std::make_shared <Times>(std::make_shared<X>(), 
std::make_shared<X>()), std::make_shared<X>());
	
MathContainer mtc;
mtc.setTree(root);
std::cout << mtc.getTree().get()->get() << std::endl;
mtc.print();
std::cout << mtc.derivate().get()->get() << std::endl;
mtc.print();
```
