/*
 * calc.cpp
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */
#include "calc.h"
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
		if(_stack.IsFull())
		{
			std::cout << "Stack is full\n";
		}
		else
		{
			_stack.Push(input.Number());
			status = true;		// 成功
		}
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

int main()
{
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

