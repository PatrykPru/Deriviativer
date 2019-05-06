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
Const::Const(double a) : val(a)
{

}
void Const::setValue(double a)
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
Add::Add(const AtomPtr& a, const AtomPtr& b) : left(a) , right(b)
{

}
void Add::setLeft(const AtomPtr& a)
{
	left = a;
}
void Add::setRight(const AtomPtr& a)
{
	right = a;
}
void Add::Accept(Visitor* v){
	v->VisitAdd(this);
}
Add::~Add(){
	
}

// Minus
Minus::Minus(){
	
}
Minus::Minus(const AtomPtr& a, const AtomPtr& b) : left(a), right(b)
{

}
void Minus::setLeft(const AtomPtr& a)
{
	left = a;
}
void Minus::setRight(const AtomPtr& a)
{
	right = a;
}
void Minus::Accept(Visitor* v){
	v->VisitMinus(this);
}
Minus::~Minus(){
	
}

// Times
Times::Times(){
	
}
Times::Times(const AtomPtr& a, const  AtomPtr& b) : left(a), right(b)
{

}
void Times::setLeft(const AtomPtr& a)
{
	left = a;
}
void Times::setRight(const AtomPtr& a)
{
	right = a;
}
void Times::Accept(Visitor* v){
	v->VisitTimes(this);
}
Times::~Times(){
	
}

// Divide
Divide::Divide(){

}
Divide::Divide(const AtomPtr& a, const AtomPtr& b) : left(a), right(b)
{
}
void Divide::setLeft(const AtomPtr& a)
{
	left = a;
}
void Divide::setRight(const AtomPtr&a)
{
	right = a;
}
void Divide::Accept(Visitor* v){
	v->VisitDivide(this);
}
Divide::~Divide(){
	
}

// Exp
Exp::Exp(){
	
}
Exp::Exp(const AtomPtr& a, const AtomPtr& b) : base(a) , power(b)
{

}
void Exp::setBase(const AtomPtr& a)
{
	base = a;
}
void Exp::setPower(const AtomPtr& a)
{
	power = a;
}
void Exp::Accept(Visitor* v){
	v->VisitExp(this);
}
Exp::~Exp(){
	
}
