#include "Parser.h"

#include "Math.h"

#include <stack>


Parser::Parser()
{
}

void Parser::partString(std::string expr)
{
	int l_ = 0;
	StrType lt_ = SPACE;
	if (expr.empty()) return;
	for (int i = 0; i <= expr.size(); i++) {
		if (getType(expr[i]) != lt_ || lt_ == OPERATOR) {
			std::string temp = expr.substr(l_, i - l_);
			if (!stringEmpty(temp)) partedString.push_back(temp);
			l_ = i;
			lt_ = getType(expr[i]);
		}
	}
}

void Parser::printPartedString()
{
	for (auto e : partedString) {
		std::cout << e << ",";
	}
	std::cout << "\n";
}

bool Parser::stringEmpty(std::string s)
{
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ')
			return false;
	}
	return true;
}

StrType Parser::getType(const char& a)
{
	switch (a) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
		case ',':
			return NUMBER;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return OPERATOR;
		case 'x':
		case 'X':
			return VAR;
		case ' ': 
			return SPACE;
		case '[':
		case '(':
			return OPEN_BRACKET;
		case ']':
		case ')':
			return CLOSE_BRACKET;
		default:
			return OTHER;
	}
}

int Parser::getPriority(const char& a)
{
	switch (a) {
	case '(':
	case ')':
	case '[':
	case ']':
		return 4;
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	}
	return 0;
}

void Parser::convertToAtomTree()
{
	std::stack<AtomPtr> st;
	for (auto e : partedString) {
		switch (getType(e[0])) {
		case NUMBER :
			st.push(std::make_shared<Const>(atoi(e.c_str())));
			break;
		case VAR :
			st.push(std::make_shared<X>());
			break;
		case OPERATOR:
			if (st.size() < 2) {
				expr = st.top();
				return;
			};
			switch (e[0]) {
			case '+': {
					auto temp = std::make_shared<Add>();
					temp.get()->setRight(st.top()); st.pop();
					temp.get()->setLeft(st.top()); st.pop();
					st.push(temp);
				}
				break;
			case '-': {
				auto temp = std::make_shared<Minus>();
				temp.get()->setRight(st.top()); st.pop();
				temp.get()->setLeft(st.top()); st.pop();
				st.push(temp);
				}
				break;
			case '*': {
				auto temp = std::make_shared<Times>();
				temp.get()->setRight(st.top()); st.pop();
				temp.get()->setLeft(st.top()); st.pop();
				st.push(temp);
				}
				break;
			case '/': {
				auto temp = std::make_shared<Divide>();
				temp.get()->setRight(st.top()); st.pop();
				temp.get()->setLeft(st.top()); st.pop();
				st.push(temp);
				}
				break;
			case '^': {
				auto temp = std::make_shared<Exp>();
				temp.get()->setPower(st.top()); st.pop();
				temp.get()->setBase(st.top()); st.pop();
				st.push(temp);
				}
				break;
			default:
				break;
			}
			break;
		}
	}
	expr = st.top();
}

void Parser::convertFromInfix(std::string expr)
{
	partedString.clear();
	partString(expr);
	std::vector <std::string> temp;
	std::stack <std::string> st;
	for (int i = 0; i < partedString.size(); i++) {
		switch (getType(partedString[i][0])) {
		case NUMBER:
		case VAR:
			temp.push_back(partedString[i]);
			break;
		case OPEN_BRACKET:
			st.push(partedString[i]);
			break;
		case CLOSE_BRACKET:
			while (!st.empty() && getType(st.top()[0]) != OPEN_BRACKET) {
				temp.push_back(st.top());
				st.pop();
			 } 
			if (getType(st.top()[0]) == OPEN_BRACKET) st.pop();
			break;
		case OPERATOR:
			while (!st.empty() && getType(st.top()[0]) != OPEN_BRACKET && getPriority(st.top()[0]) >= getPriority(partedString[i][0])) {
				if (getPriority(st.top()[0]) != 4) temp.push_back(st.top());
				st.pop();
			}
			st.push(partedString[i]);
			break;
		}
	}
	while (!st.empty()){
		temp.push_back(st.top()); st.pop();
	}
	partedString = temp;
	convertToAtomTree();
	printPartedString();
}

void Parser::convertFromRPN(std::string expr)
{
	partedString.clear();
	partString(expr);
	convertToAtomTree();
	printPartedString();
}

AtomPtr Parser::getExpr()
{
	return expr;
}


Parser::~Parser()
{
}
