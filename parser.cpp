/*
 * parser.cpp
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "symTab.h"

Parser::Parser(Scanner & scanner, SymbolTable & symTab)
	: _scanner(scanner), _symTab(symTab)
{
	std::cout << "Parser created\n";
}

Parser::~Parser()
{
	std::cout << "Destroying parser\n";
}

Status Parser::Parse()
{
	for(EToken token = _scanner.Token();
			token != tEnd;
			_scanner.Accept())
	{
		token = _scanner.Token();
		switch(token)
		{
		case tMult:
			std::cout << "Times\n";
			break;
		case tPlus:
			std::cout << "Plus\n";
			break;
		case tMinus:
			std::cout << "Minus\n";
			break;
		case tDivide:
			std::cout << "Divide\n";
			break;
		case tLParen:
			std::cout << "Left parenthesis\n";
			break;
		case tRParen:
			std::cout << "Right parenthesis\n";
			break;
		case tNumber:
			std::cout << "Number: " << _scanner.Number()
					<< std::endl;
			break;
		case tIdent:
			{
				std::cout << "Identifier: ";
				char buf [20];
				int len = 20;
				_scanner.GetSymbolName(buf, len);
				std::cout << "Symbol ( " << buf << " )" << std::endl;
			}
		break;
		case tEnd:
			std::cout << "End\n";
			return stQuit;
		case tError:
			std::cout << "Error\n";
			return stQuit;
		default:
			std::cout << "Error: bad token\n";
			return stQuit;
		}
	}
	return stOk;
}

Status Parser::Eval()
{
	std::cout << "Parser eval\n";
	return stQuit;
}


