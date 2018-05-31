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
#include <string.h>

const int maxSymLen = 10;

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
	tMult,
	tMinus,
	tDivide,
	tLParen,
	tRParen,
	tAssign,
	tIdent
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
	void GetSymbolName(char * strOut, int & len);
private:
	char const * const _buf;
	void EatWhite();
	int _iLook;
	EToken _token;
	double _number;
	int _lenSymbol;
	int _iSymbol;
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
	case '-':
		_token = tMinus;
		++_iLook;
		break;
	case '/':
		_token = tDivide;
		++_iLook;
		break;
	case '(':
		_token = tLParen;
		++_iLook;
		break;
	case ')':
		_token = tRParen;
		++_iLook;
		break;
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
	{
		_token = tNumber;
		/*
		_number = std::atoi(&_buf[_iLook]);
		while(std::isdigit(_buf[_iLook]))
			++_iLook;
		*/
		char *p;
		_number = std::strtod(&_buf[_iLook], &p);
		_iLook = p - _buf;	// 指针 减
		break;
	}
	case '\0': // 输入结尾
		_token = tEnd;
		break;
	default:
		if(std::isalpha(_buf[_iLook])
			|| _buf[_iLook] == '_')
		{
			_token = tIdent;
			_iSymbol = _iLook;

			int cLook;	// 在do循环中初始化
			do{
				++_iLook;
				cLook = _buf[_iLook];
			} while(std::isalnum(cLook) || cLook == '_');

			_lenSymbol = _iLook - _iSymbol;
			if(_lenSymbol >= maxSymLen)
				_lenSymbol = maxSymLen - 1;
		}
		else
			_token = tError;
		break;
	}

}

void Scanner::GetSymbolName(char * strOut, int & len)
{
	assert(len >= maxSymLen);
	assert(_lenSymbol <= maxSymLen);
	strncpy(strOut, &_buf[_iSymbol], _lenSymbol);
	strOut[_lenSymbol] = '\0';
	len = _lenSymbol;

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
			std::cout << "Identifier: \n";
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
