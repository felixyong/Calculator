/*
 * calc.h
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */

#ifndef CALC_H_
#define CALC_H_

#include "input.h"
#include "stack.h"

class Calculator
{
public:
	bool Execute(Input const & input);
	// 让stack可以访问
	Istack const & GetStack() const {return _stack;}
private:
	int Calculate(int n1, int n2, int token) const;
	Istack _stack;
};

#endif /* CALC_H_ */

