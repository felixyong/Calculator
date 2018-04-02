/*
 * stack.h
 *
 *  Created on: 2018年3月31日
 *      Author: Administrator
 */

#ifndef STACK_H_
#define STACK_H_

const int maxStack = 100;

class Istack
{
	// 让StackSeq可以访问IStack的私有数据成员
	friend class StackSeq;
public:
	Istack():_top(0){}
	void Push(int i);
	int Pop();
private:
	int _arr [maxStack];
	int _top;
};

class StackSeq
{
public:
	// 常量引用，不能更改引用的对象，例如不能调用_stack.Push()这样的非常量方法
	StackSeq(Istack const & stack);
	bool AtEnd() const;		// 是否完成
	void Advance();		// 移到下一项
	int GetNum() const;		// 读取当前项
private:
	Istack const & _stack;		// 引用stack
	int	_iCur;		// stack当前索引
};


#endif /* STACK_H_ */
