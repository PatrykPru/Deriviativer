#pragma once

#include "Visitor.h"

class Atom;

typedef std::shared_ptr<Atom> AtomPtr;
typedef std::shared_ptr<Const> ConstPtr;

class Atom {
	public:
		Atom();
		virtual double eq(double) = 0;
		virtual void Accept(Visitor* ) = 0;
		virtual ~Atom();
};

class Const : public Atom {
	public:
		bool isFraction;
		double val;
	public:
		Const();
		Const(double);
		void setValue(double);
		double eq(double);
		void Accept(Visitor*);
		~Const();
};

class X : public Atom {
	public:
		X();
		double eq(double);
		void Accept(Visitor*);
		~X();
};

class Add : public Atom {
	public:
		AtomPtr left;
		AtomPtr right;
	public:
		Add();
		Add(const AtomPtr&, const  AtomPtr&);
		void setLeft(const AtomPtr&);
		void setRight(const AtomPtr&);
		double eq(double a);
		void Accept(Visitor*);
		~Add();
};

class Minus : public Atom {
	public:
		AtomPtr left;
		AtomPtr right;
	public:
		Minus();
		Minus(const AtomPtr&, const  AtomPtr&);
		void setLeft(const AtomPtr&);
		void setRight(const AtomPtr&);
		double eq(double);
		void Accept(Visitor*);
		~Minus();
};

class Times : public Atom {
	public:
		AtomPtr left;
		AtomPtr right;
	public:
		Times();
		Times(const AtomPtr&, const AtomPtr&);
		void setLeft(const AtomPtr&);
		void setRight(const AtomPtr&);
		double eq(double);
		void Accept(Visitor*);
		~Times();
};

class Divide : public Atom {
	public:
		AtomPtr left;
		AtomPtr right;
	public:
		Divide();
		Divide(const AtomPtr&, const AtomPtr&);
		void setLeft(const AtomPtr&);
		void setRight(const AtomPtr&);
		double eq(double);
		void Accept(Visitor*);
		~Divide();
};

class Exp : public Atom {
	public:
		AtomPtr base;
		ConstPtr power;
	public:
		Exp();
		Exp(const AtomPtr&, const ConstPtr&);
		void setBase(const AtomPtr&);
		void setPower(const ConstPtr&); // Only Const Value
		double eq(double);
		void Accept(Visitor*);
		~Exp();
};

