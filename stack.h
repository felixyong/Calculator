/*
 * stack.h
 *
 *  Created on: 2018��3��31��
 *      Author: Administrator
 */

#ifndef STACK_H_
#define STACK_H_

const int maxStack = 100;

class Istack
{
	// ��StackSeq���Է���IStack��˽�����ݳ�Ա
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
	// �������ã����ܸ������õĶ������粻�ܵ���_stack.Push()�����ķǳ�������
	StackSeq(Istack const & stack);
	bool AtEnd() const;		// �Ƿ����
	void Advance();		// �Ƶ���һ��
	int GetNum() const;		// ��ȡ��ǰ��
private:
	Istack const & _stack;		// ����stack
	int	_iCur;		// stack��ǰ����
};


#endif /* STACK_H_ */
