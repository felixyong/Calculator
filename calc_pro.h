/*
 * calc_pro.h
 *
 *  Created on: 2018年4月16日
 *      Author: Administrator
 */

#ifndef CALC_PRO_H_
#define CALC_PRO_H_

#include <iostream>
#include <cassert>
#include <cstdlib>

enum Status
{
	stOk,
	stQuit,
	stError
};

enum EToken
{
	tEnd,
	tError,
	tNumber,
	tPlus,
	tMult
};

class Scanner
{
public:
	Scanner(char const * buf);
	EToken Token() const {return _token;}
	void Accept();
	double Number()
	{
		assert(_token == tNumber);
		return _number;
	}
private:
	char const * const _buf;
	void EatWhite();
	int _iLook;
	EToken _token;
	double _number;
};

Scanner::Scanner(char const * buf)
	: _buf(buf), _iLook(0)
{
	std::cout << "Scanner with \"" << buf << "\""
			<< std::endl;
	Accept();
}

void Scanner::EatWhite()
{
	while(std::isspace(_buf[_iLook]))
		++_iLook;
}

void Scanner::Accept()
{
	EatWhite();
	switch(_buf[_iLook])
	{
	case '+':
		_token = tPlus;
		++_iLook;
		break;
	case '*':
		_token = tMult;
		++_iLook;
		break;
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		_token = tNumber;
		_number = std::atoi(&_buf[_iLook]);
		while(std::isdigit(_buf[_iLook]))
			++_iLook;
		break;
	case '\0': // 输入结尾
		_token = tEnd;
		break;
	default:
		_token = tError;
		break;
	}

}

class SymbolTable
{
public:
	SymbolTable(){}
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
		case tNumber:
			std::cout << "Number: " << _scanner.Number()
					<< std::endl;
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

#endif /* CALC_PRO_H_ */
