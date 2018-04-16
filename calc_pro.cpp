/*
 * calc_pro.cpp
 *
 *  Created on: 2018��4��16��
 *      Author: Administrator
 */

#include "calc_pro.h"

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
		status = parser.Eval();
	} while(status != stQuit);

}


