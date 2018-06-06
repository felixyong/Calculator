/*
 * funTab.h
 *
 *  Created on: Jun 3, 2018
 *      Author: CNFELUO1
 */

#ifndef FUNTAB_H_
#define FUNTAB_H_

class SymbolTable;

const int maxIdFun = 16;

typedef double (*PtrFun) (double);

class FunctionEntry
{
public:
	PtrFun pFun;
	char * strFun;
};

class FunctionTable
{
public:
	FunctionTable (SymbolTable & symTab, FunctionEntry funArr[]);
	int Size() const {return _size;}
	PtrFun GetFun(int id) {return _pFun[id];}
private:
	PtrFun _pFun[maxIdFun];
	int _size;
};

extern FunctionEntry funArr [];

#endif /* FUNTAB_H_ */
