/*
 * stack.cpp
 *
 *  Created on: 2018��3��31��
 *      Author: Administrator
 */

#include "stack.h"
#include <cassert>
#include <iostream>

Istack::Istack()
: _top(0), _capacity(initStack)
{
	_arr = new int [initStack];		// �����ڴ�
}

Istack::~Istack()
{
	delete []_arr;		// �ͷ��ڴ�
}
//ͨ��NDEBUG=1����ȥ������
void Istack::Push(int i)
{
	assert(_top <= _capacity);
	if(_top == _capacity)
		Grow();
	_arr[_top] = i;
	++_top;
}

void Istack::Grow()
{
	std::cout << "Doubling stack from "
			<< _capacity << ".\n";
	// ����������
	int * arrNew = new int [2 * _capacity];
	// ��������������
	for(int i = 0; i < _capacity; ++i)
		arrNew[i] = _arr[i];
	_capacity = 2 * _capacity;
	delete [] _arr;
	_arr = arrNew;
}

int Istack::Pop()
{
	assert(_top > 0);
	--_top;
	int top_temp = _arr[_top];
	if((_top == (_capacity / 2)) && (_capacity > 1))
		Reduce();
	return top_temp;
}

void Istack::Reduce()
{
	std::cout << "Reducing stack from "
			<< _capacity << ".\n";
	// ����������
	int * arrNew = new int [_capacity / 2];
	// ��������������
	for(int i = 0; i < _capacity / 2; ++i)
		arrNew[i] = _arr[i];
	_capacity = _capacity / 2;
	delete [] _arr;
	_arr = arrNew;
}

int Istack::Top() const
{
	// ���Կ�����ʹ��
	assert(_top > 0);
	return _arr[_top - 1];
}

bool Istack::IsEmpty() const
{
	assert(_top >= 0);
	return _top == 0;
}

StackSeq::StackSeq(Istack const & stack)
: _iCur(0), _stack(stack)		// ��ʼ����
{}

bool StackSeq::AtEnd() const
{
	return _iCur == _stack._top;		// ��Ԫ�����Է���_top
}

void StackSeq::Advance()
{
	assert(!AtEnd());		// �ǽ�β
	++_iCur;
}

int StackSeq::GetNum() const
{
	assert(!AtEnd());
	return _stack._arr[_iCur];		// ��Ԫ�����Է���_arr
}

