/*
 * input.h
 *
 *  Created on: 2018��4��1��
 *      Author: Administrator
 */

#ifndef INPUT_H_
#define INPUT_H_

const int maxBuf = 100;

// ����Ϊ tokNumber, tokError, +, -, *, /

const int tokNumber = 1;
const int tokError = 2;

// ��stdin������룬ת���ɷ���

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
