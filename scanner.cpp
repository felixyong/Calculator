/*
 * scanner.cpp
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "scanner.h"

Scanner::Scanner(char const * buf)
	: _buf(buf), _iLook(0)
{
	std::cout << "Scanner with \"" << buf << "\""
			<< std::endl;
	Accept();
}

void Scanner::EatWhite()
{
	while(isspace(_buf[_iLook]))
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
		_number = strtod(&_buf[_iLook], &p);
		_iLook = p - _buf;	// 指针 减
		break;
	}
	case '\0': // 输入结尾
		_token = tEnd;
		break;
	default:
		if(isalpha(_buf[_iLook])
			|| _buf[_iLook] == '_')
		{
			_token = tIdent;
			_iSymbol = _iLook;

			int cLook;	// 在do循环中初始化
			do{
				++_iLook;
				cLook = _buf[_iLook];
			} while(isalnum(cLook) || cLook == '_');

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


