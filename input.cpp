/*
 * input.cpp
 *
 *  Created on: 2018��4��1��
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

	// ����ĵ�һ���ַ�ͨ�������ж���ʲô����

	int c = _buf [0];

	if(std::isdigit(c))
		_token = tokNumber;
	else if(c == '+'  || c == '*' || c == '/')
		_token = c;
	else if(c =='-')	// �������븺��
	{
		if(std::isdigit(_buf[1]))		// ������һ���ַ�
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
	return std::atoi(_buf);		// ���ַ���ת��������
}



