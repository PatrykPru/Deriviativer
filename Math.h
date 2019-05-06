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
	protected:
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
	protected:
		AtomPtr left;
		AtomPtr right;
	public:
		Add();
		Add(AtomPtr&, AtomPtr&);
		setLeft(AtomPtr&);
		setRight(AtomPtr&);
		void Accept(Visitor*);
		~Add();
};

class Minus : public Atom {
	protected:
		AtomPtr left;
		AtomPtr right;
	public:
		Minus();
		Minus(AtomPtr&, AtomPtr&);
		setLeft(AtomPtr&);
		setRight(AtomPtr&);
		void Accept(Visitor*);
		~Minus();
};

class Times : public Atom {
	protected:
		AtomPtr left;
		AtomPtr right;
	public:
		Times();
		Times(AtomPtr&, AtomPtr&);
		setLeft(AtomPtr&);
		setRight(AtomPtr&);
		void Accept(Visitor*);
		~Times();
};

class Divide : public Atom {
	protected:
		AtomPtr left;
		AtomPtr right;
	public:
		Divide();
		Divide(AtomPtr&, AtomPtr&);
		setLeft(AtomPtr&);
		setRight(AtomPtr&);
		void Accept(Visitor*);
		~Divide();
};

class Exp : public Atom {
	protected:
		AtomPtr base;
		AtomPtr power;
	public:
		Exp();
		Exp(AtomPtr&, AtomPtr&);
		setBase(AtomPtr&);
		setPower(AtomPtr&);
		void Accept(Visitor*);
		~Exp();
};

