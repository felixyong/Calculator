/*
 * calc.cpp
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */
#include <iostream>
//#include "calc.h"
//#include "Input.h"
//#include "stack.h"

class Istack{};

class StackSeq
{
public:
	StackSeq(Istack const & stack)
	:_stack(stack), _done(false)
	{
		std::cout << "Stack sequence created\n";
	}
	bool AtEnd() const {return _done;}
	void Advance() {_done = true;}
	int GetNum() const {return 13;}
private:
	Istack const & _stack;
	bool _done;
};

class Input
{
public:
	Input()
	{
		std::cout << "Input created\n";
	}
};

class Calculator
{
public:
	Calculator():_done(false)
	{
		std::cout << "Calculator created\n";
	}
	bool Execute(Input & input)
	{
		std::cout << "Calculator::Execute\n";
		return !_done;
	}
	Istack const & GetStack()	// 常量
	{
		_done = true;
		return _stack;
	}
private:
	Istack _stack;
	bool _done;
};


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

