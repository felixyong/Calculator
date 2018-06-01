/*
 * scanner.h
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <cassert>

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

const int maxSymLen = 10;

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



#endif /* SCANNER_H_ */
