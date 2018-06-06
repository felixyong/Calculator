/*
 * calc_pro.cpp
 *
 *  Created on: 2018年4月16日
 *      Author: Administrator
 */

#include "parser.h"
#include "symTab.h"
#include "funTab.h"
#include "store.h"
#include "scanner.h"
#include <iostream>

const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	char buf[maxBuf];
	Status status;
	SymbolTable symTab(maxSymbols);
	FunctionTable funTab(symTab, funArr);
	Store store(maxSymbols, symTab);
	do
	{
		std::cout << "> ";		// 提示
		std::cin.getline(buf, maxBuf);
		Scanner scanner(buf);
		Parser parser(scanner, store, funTab, symTab);
		status = parser.Eval();
	} while(status != stQuit);

}


