/*
 * stack.h
 *
 *  Created on: 2018��3��31��
 *      Author: Administrator
 */

#ifndef STACK_H_
#define STACK_H_

const int initStack = 1;

class Istack
{
	// ��StackSeq���Է���IStack��˽�����ݳ�Ա
	friend class StackSeq;
public:
	Istack();
	~Istack();
	void Push(int i);
	int Pop();
	bool IsEmpty() const;
private:
	void Grow();
	int *_arr;
	int _capacity;		// �����С
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
