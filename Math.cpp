#include "Math.h"


// Atom
Atom::Atom(){

}
Atom::~Atom(){
	
}

// Const
Const::Const(){
	val = 1e-10;
}
Const::Const(double a)
{
	val = a;
}
void Const::Accept(Visitor* v){
	v->VisitConst(this);
}
Const::~Const(){

}

// X
X::X(){

}
void X::Accept(Visitor* v){
	v->VisitX(this);
}
X::~X(){
	
}

// Add
Add::Add(){
	
}
Add::Add(AtomPtr& a, AtomPtr& b)
{
	left = a;
	right = b;
}
void Add::Accept(Visitor* v){
	v->VisitAdd(this);
}
Add::~Add(){
	
}

// Minus
Minus::Minus(){
	
}
Minus::Minus(AtomPtr& a, AtomPtr& b)
{
	left = a;
	right = b;
}
void Minus::Accept(Visitor* v){
	v->VisitMinus(this);
}
Minus::~Minus(){
	
}

// Times
Times::Times(){
	
}
Times::Times(AtomPtr& a, AtomPtr& b)
{
	left = a;
	right = b;
}
void Times::Accept(Visitor* v){
	v->VisitTimes(this);
}
Times::~Times(){
	
}

	// Divide
Divide::Divide(){

}
Divide::Divide(AtomPtr& a, AtomPtr& b)
{
	left = a;
	right = b;
}
void Divide::Accept(Visitor* v){
	v->VisitDivide(this);
}
Divide::~Divide(){
	
}

	// Exp
Exp::Exp(){
	
}
Exp::Exp(AtomPtr& a, AtomPtr& b)
{
	base = a;
	power = b;
}
void Exp::Accept(Visitor* v){
	v->VisitExp(this);
}
Exp::~Exp(){
	
}
