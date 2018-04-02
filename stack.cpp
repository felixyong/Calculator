/*
 * stack.cpp
 *
 *  Created on: 2018年3月31日
 *      Author: Administrator
 */
/*
#include "stack.h"
#include <cassert>
#include <iostream>

//通过NDEBUG=1编译去掉断言
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
: _iCur(0), _stack(stack)		// 初始引用
{}

bool StackSeq::AtEnd() const
{
	return _iCur == _stack._top;		// 友元，可以访问_top
}

void StackSeq::Advance()
{
	assert(!AtEnd());		// 非结尾
	++_iCur;
}

int StackSeq::GetNum() const
{
	assert(!AtEnd());
	return _stack._arr[_iCur];		// 友元，可以访问_arr
}
*/
