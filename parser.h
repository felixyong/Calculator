/*
 * parser.h
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#ifndef PARSER_H_
#define PARSER_H_

class Node;
class Scanner;
class Store;
class FunctionTable;
class SymbolTable;

enum Status
{
	stOk,
	stQuit,
	stError
};

class Parser
{
public:
	Parser(Scanner & scanner,
			Store & store,
			FunctionTable & funTab,
			SymbolTable & symTab);
	~Parser();
	Status Eval();
private:
	void Parse ();
	Node * Expr ();
	Node * Term ();
	Node * Factor ();
	void Execute ();
	Scanner & _scanner;
	Node * _pTree;
	Status _status;
	Store & _store;
	FunctionTable & _funTab;
	SymbolTable & _symTab;
};



#endif /* PARSER_H_ */
