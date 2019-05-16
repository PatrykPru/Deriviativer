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
double Const::eq(double a)
{
	return val;
}
void Const::Accept(Visitor* v){
	v->VisitConst(this);
}
Const::~Const(){

}

// X
X::X(){

}
double X::eq(double a)
{
	return a;
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
double Add::eq(double a)
{
	if (left.get() != nullptr && right.get() != nullptr) {
		return left.get()->eq(a) + right.get()->eq(a);
	}
	if (left.get() != nullptr) {
		return left.get()->eq(a);
	}
	if (right.get() != nullptr) {
		return left.get()->eq(a);
	}
	return 0.0;
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
double Minus::eq(double a)
{
	if (left.get() != nullptr && right.get() != nullptr) {
		return left.get()->eq(a) - right.get()->eq(a);
	}
	if (left.get() != nullptr) {
		return left.get()->eq(a);
	}
	if (right.get() != nullptr) {
		return left.get()->eq(a);
	}
	return 0.0;
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
double Times::eq(double a)
{
	if (left.get() != nullptr && right.get() != nullptr) {
		return left.get()->eq(a) * right.get()->eq(a);
	}
	if (left.get() != nullptr) {
		return left.get()->eq(a);
	}
	if (right.get() != nullptr) {
		return left.get()->eq(a);
	}
	return 0.0;
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
double Divide::eq(double a)
{
	if (left.get() != nullptr && right.get() != nullptr) {
		return left.get()->eq(a) / right.get()->eq(a);
	}
	if (left.get() != nullptr) {
		return left.get()->eq(a);
	}
	if (right.get() != nullptr) {
		return left.get()->eq(a);
	}
	return 0.0;
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
double Exp::eq(double a)
{
	return std::pow(base->eq(a), power->eq(a));
}
void Exp::Accept(Visitor* v){
	v->VisitExp(this);
}
Exp::~Exp(){
	
}
