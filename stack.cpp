/*
 * stack.cpp
 *
 *  Created on: 2018��3��31��
 *      Author: Administrator
 */
/*
#include "stack.h"
#include <cassert>
#include <iostream>

//ͨ��NDEBUG=1����ȥ������
void Istack::Push(int i)
{
	assert(_top < maxStack);
	_arr[_top] = i;
	++_top;
}

int Istack::Pop()
{
	assert(_top > 0);
	--_top;
	return _arr[_top];
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
*/
