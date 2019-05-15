#pragma once

#include "Visitor.h"
#include <vector>

class Atom;
typedef std::shared_ptr<Atom> AtomPtr;

enum StrType { SPACE, NUMBER, VAR, OPERATOR, OTHER };

class Parser
{
protected:
	AtomPtr expr;
	std::vector<std::string> partedString;
	void partStringRPN(std::string);
	void printPartedString();
	bool stringEmpty(std::string);
	StrType getType(const char&);
	void convertToAtomTree();
public:
	Parser();
	void convertFromRPN(std::string);
	AtomPtr getExpr();
	~Parser();
};

