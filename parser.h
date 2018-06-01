/*
 * parser.h
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "scanner.h"
#include "symTab.h"

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
	Status Parse();
private:
	Scanner & _scanner;
	SymbolTable & _symTab;
};



#endif /* PARSER_H_ */
