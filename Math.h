#pragma once

#include "Visitor.h"

class Atom;

typedef std::shared_ptr<Atom> AtomPtr;

class Atom {
	public:
		Atom();
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
		void Accept(Visitor*);
		~Const();
};

class X : public Atom {
	public:
		X();
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
		void Accept(Visitor*);
		~Divide();
};

class Exp : public Atom {
	public:
		AtomPtr base;
		AtomPtr power;
	public:
		Exp();
		Exp(const AtomPtr&, const  AtomPtr&);
		void setBase(const AtomPtr&);
		void setPower(const AtomPtr&);
		void Accept(Visitor*);
		~Exp();
};

