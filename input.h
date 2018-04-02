/*
 * input.h
 *
 *  Created on: 2018年4月1日
 *      Author: Administrator
 */

#ifndef INPUT_H_
#define INPUT_H_

const int maxBuf = 100;

// 符号为 tokNumber, tokError, +, -, *, /

const int tokNumber = 1;
const int tokError = 2;

// 从stdin获得输入，转换成符号

class Input
{
public:
	Input();
	int Token() const {return _token;}
	int Number() const;
private:
	int _token;
	char _buf [maxBuf];
};

#endif /* INPUT_H_ */
