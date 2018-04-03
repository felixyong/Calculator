/*
 * calc.cpp
 *
 *  Created on: 2018��4��1��
 *      Author: Administrator
 */
#include "calc.h"
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
		if(_stack.IsFull())
		{
			std::cout << "Stack is full\n";
		}
		else
		{
			_stack.Push(input.Number());
			status = true;		// �ɹ�
		}
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

