/*
 * calc_pro.cpp
 *
 *  Created on: 2018��4��16��
 *      Author: Administrator
 */

#include <iostream>
#include "symTab.h"
#include "scanner.h"
#include "parser.h"

const int maxBuf = 100;

int main()
{
	char buf[maxBuf];
	Status status;
	SymbolTable symTab;
	do
	{
		std::cout << "> ";		// ��ʾ
		std::cin.getline(buf, maxBuf);
		Scanner scanner(buf);
		Parser parser(scanner, symTab);
		status = parser.Parse();
	} while(status != stQuit);

}


