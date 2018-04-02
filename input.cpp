/*
 * input.cpp
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */
#include "input.h"
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <iostream>

Input::Input()
{
	std::cin >> _buf;

	// 输入的第一个字符通常容易判断是什么符号

	int c = _buf [0];

	if(std::isdigit(c))
		_token = tokNumber;
	else if(c == '+'  || c == '*' || c == '/')
		_token = c;
	else if(c =='-')	// 允许输入负数
	{
		if(std::isdigit(_buf[1]))		// 参照下一个字符
			_token = tokNumber;
		else
			_token = c;
	}
	else
		_token = tokError;
}

int Input::Number() const
{
	assert(_token == tokNumber);
	return std::atoi(_buf);		// 将字符串转换成整数
}



