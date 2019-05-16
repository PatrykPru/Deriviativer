#pragma once

#include "Visitor.h"
#include <vector>

class Atom;
typedef std::shared_ptr<Atom> AtomPtr;

enum StrType { SPACE, NUMBER, VAR, OPERATOR, OPEN_BRACKET, CLOSE_BRACKET, OTHER };

class Parser
{
protected:
	AtomPtr expr;
	std::vector<std::string> partedString;
	void partString(std::string);
	void printPartedString();
	bool stringEmpty(std::string);
	StrType getType(const char&);
	int getPriority(const char&);
	void convertToAtomTree();
public:
	Parser();
	void convertFromInfix(std::string);
	void convertFromRPN(std::string);
	AtomPtr getExpr();
	~Parser();
};

