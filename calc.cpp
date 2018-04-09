/*
 * calc.cpp
 *
 *  Created on: 2018��4��1��
 *      Author: Administrator
 */
#include "calc.h"
#include "list.h"
#include "strTab.h"
#include <iostream>
#include <cassert>

bool Calculator::Execute(Input const & input)
{
	int token = input.Token();
	bool status  = false;		// �ٶ�ʧ��

	if(token == tokError)
	{
		std::cout << "Unknown token\n";
	}
	else if(token == tokNumber)
	{
		_stack.Push(input.Number());
		status = true;		// �ɹ�

	}
	else
	{
		// ��Լ��Input���ܲ����κ���������
		assert(token == '+'|| token == '-' || token == '*' || token == '/');
		if(_stack.IsEmpty())
		{
			std::cout << "Stack is empty\n";
		}
		else
		{
			int num2 = _stack.Pop();
			int num1;
			// ������������ջ����һ������������������ʹ�������
			if(_stack.IsEmpty())
				num1 = num2;
			else
				num1 = _stack.Pop();

			_stack.Push(Calculate(num1, num2, token));
			status = true;
		}
	}
	return status;
}

int Calculator::Calculate(int num1,
		int num2, int token) const
{
	int result;

	if(token == '+')
		result = num1 + num2;
	else if(token == '-')
		result = num1 - num2;
	else if(token == '*')
		result  = num1 * num2;
	else if(token == '/')
	{
		if(num2 == 0)
		{
			std::cout << "Division by zero\n";
			result = 0;
		}
		else
			result  = num1 / num2;		// ������
	}
	return result;
}

int main()
{
	// Example for List
	List list;
	list.Add(1);
	list.Add(2);
	std::cout << "List contents:\n";
	for(Link const * pLink = list.GetHead();
			pLink != 0;
			pLink = pLink->Next())
	{
		std::cout << pLink->Id() << ", ";
	}
	std::cout << std::endl;

	// Example for string table
	StringTable strTable;
	strTable.ForceAdd("One");
	strTable.ForceAdd("Two");
	strTable.ForceAdd("Three");

	int id = strTable.Find("One");
	std::cout << "One at " << id << std::endl;
	id = strTable.Find("Two");
	std::cout << "Two at " << id << std::endl;
	id = strTable.Find("Three");
	std::cout << "Three at " << id << std::endl;
	id = strTable.Find("Minus one");
	std::cout << "Minus one at " << id << std::endl;

	std::cout << "String 0 is "
			<< strTable.GetString(0) << std::endl;
	std::cout << "String 1 is "
			<< strTable.GetString(1) << std::endl;
	std::cout << "String 2 is "
			<< strTable.GetString(2) << std::endl;

	// calculator
	Calculator TheCalculator;
	bool status;
	do
	{
		// ������ʾ
		std::cout << "> ";
		Input input;
		status = TheCalculator.Execute(input);
		if(status)
		{
			for(StackSeq seq(TheCalculator.GetStack());
					!seq.AtEnd();
					seq.Advance())
			{
				std::cout << " " << seq.GetNum() << std::endl;
			}
		}

	}while(status);


}
