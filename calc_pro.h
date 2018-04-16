/*
 * calc_pro.h
 *
 *  Created on: 2018Äê4ÔÂ16ÈÕ
 *      Author: Administrator
 */

#ifndef CALC_PRO_H_
#define CALC_PRO_H_

#include <iostream>

class Scanner
{
public:
	Scanner(char const * buf);
private:
	char const * const _buf;
};

Scanner::Scanner(char const * buf)
	: _buf(buf)
{
	std::cout << "Scanner with \"" << buf << "\""
			<< std::endl;
}

class SymbolTable
{
public:
	SymbolTable(){}
};

enum Status
{
	stOk,
	stQuit,
	stError
};

class Parser
{
public:
	Parser(Scanner & scanner, SymbolTable & symTab);
	~Parser();
	Status Eval();
private:
	Scanner & _scanner;
	SymbolTable & _symTab;
};

Parser::Parser(Scanner & scanner, SymbolTable & symTab)
	: _scanner(scanner), _symTab(symTab)
{
	std::cout << "Parser created\n";
}

Parser::~Parser()
{
	std::cout << "Destroying parser\n";
}

Status Parser::Eval()
{
	std::cout << "Parser eval\n";
	return stQuit;
}

#endif /* CALC_PRO_H_ */
