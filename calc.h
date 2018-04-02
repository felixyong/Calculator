/*
 * calc.h
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */
/*
#ifndef CALC_H_
#define CALC_H_



class Calculator
{
public:
	Claculator():_done(false)
	{
		std::cout << "Claculator created\n";
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

#endif /* CALC_H_ */
*/
