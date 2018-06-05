/*
 * calc.cpp
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */
#include "calc.h"
#include "list.h"
#include "strTab.h"
#include "tree.h"
#include <iostream>
#include <cassert>

bool Calculator::Execute(Input const & input)
{
	int token = input.Token();
	bool status  = false;		// 假定失败

	if(token == tokError)
	{
		std::cout << "Unknown token\n";
	}
	else if(token == tokNumber)
	{
		_stack.Push(input.Number());
		status = true;		// 成功

	}
	else
	{
		// 契约：Input不能产生任何其他符号
		assert(token == '+'|| token == '-' || token == '*' || token == '/');
		if(_stack.IsEmpty())
		{
			std::cout << "Stack is empty\n";
		}
		else
		{
			int num2 = _stack.Pop();
			int num1;
			// 特例：仅当堆栈中有一个数，对两个操作数使用这个数
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
			result  = num1 / num2;		// 整数除
	}
	return result;
}

/*
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

	// example of tree
	// (20.0 + (-10.0)) * 0.1
	Node * pNode1 = new NumNode(20.0);
	Node * pNode2 = new NumNode(-10.0);
	Node * pNode3 = new AddNode(pNode1, pNode2);
	Node * pNode4 = new NumNode(0.1);
	Node * pNode5 = new MultNode(pNode3, pNode4);
	std::cout << "Calculating the tree\n";
	double x = pNode5->Calc();
	std::cout << "Result: " << x << std::endl;
	delete pNode5;

	// calculator
	Calculator TheCalculator;
	bool status;
	do
	{
		// 输入提示
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
*/

// for date exercise
/*
#include "Date.h"

int main ()
{
	Date date1(2000, 10, 1);
	date1.Display();
	Date date2 = date1 + 391;
	date2.Display();
	std::cout << "date2 > date1? " << (date2 > date1) << std::endl;
}
*/
