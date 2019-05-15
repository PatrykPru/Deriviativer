#include "Parser.h"

#include "Math.h"

#include <stack>


Parser::Parser()
{
}

void Parser::partStringRPN(std::string expr)
{
	int l_ = 0;
	StrType lt_ = SPACE;
	if (expr.empty()) return;
	for (int i = 0; i < expr.size(); i++) {
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
		case ' ': 
			return SPACE;
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
		case 'x':
		case 'X':
			return VAR;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return OPERATOR;
		default:
			return OTHER;
	}
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
				auto temp = std::make_shared<Times>();
				temp.get()->setRight(st.top()); st.pop();
				temp.get()->setLeft(st.top()); st.pop();
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

void Parser::convertFromRPN(std::string expr)
{
	partedString.clear();
	partStringRPN(expr);
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
