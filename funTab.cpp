/*
 * funTab.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: CNFELUO1
 */
#include "funTab.h"
#include "symTab.h"
#include <cassert>
#include <iostream>
#include <math.h>

double CoTan(double x);	// function prototype

FunctionEntry funArr[maxIdFun] =
{
		log,		"log",
		log10, 		"log10",
		exp,		"exp",
		sqrt,		"sqrt",
		sin,		"sin",
		cos,		"cos",
		tan,		"tan",
		CoTan,		"cotan",
		sinh,		"sinh",
		cosh,		"cosh",
		tanh,		"tanh",
		asin,		"asin",
		acos,		"acos",
		atan,		"atan",
		0,			""

};

FunctionTable::FunctionTable(SymbolTable & symTab, FunctionEntry funArr[])
	: _size(0)
{
	for(int i = 0; i < maxIdFun; ++i)
	{
		int len = std::strlen(funArr[i].strFun);
		if(len == 0)
			break;
		_pFun[i] = funArr[i].pFun;
		std::cout << funArr[i].strFun << std::endl;
		int j = symTab.ForceAdd(funArr[i].strFun, len);
		assert(i == j);
		++_size;
	}
}

double CoTan(double x)
{
	double y = std::tan(x);
	if(y == 0)
	{
		std::cout << "cotan of " << x << " undefined\n";
		return HUGE_VAL;
	}
	return 1.0 / y;
}
