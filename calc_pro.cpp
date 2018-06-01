/*
 * calc_pro.cpp
 *
 *  Created on: 2018年4月16日
 *      Author: Administrator
 */

#include <iostream>
#include "symTab.h"
#include "scanner.h"
#include "parser.h"

const int maxBuf = 100;
const int maxSymbols = 40;

int main()
{
	char buf[maxBuf];
	Status status;
	SymbolTable symTab(maxSymbols);
	do
	{
		std::cout << "> ";		// 提示
		std::cin.getline(buf, maxBuf);
		Scanner scanner(buf);
		Parser parser(scanner, symTab);
		status = parser.Parse();
	} while(status != stQuit);

}


