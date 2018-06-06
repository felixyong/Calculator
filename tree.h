/*
 * tree.h
 *
 *  Created on: 2018Äê4ÔÂ15ÈÕ
 *      Author: Administrator
 */

#ifndef TREE_H_
#define TREE_H_

#include <cassert>
#include "funTab.h"
class Store;

class Node
{
public:
	virtual ~Node () {}
	virtual double Calc () const = 0;
	virtual bool IsLvalue () const {return false;}
	virtual void Assign (double)
	{
		assert (!"Assign called incorrectly");
	}
};

class NumNode: public Node
{
public:
	NumNode(double num): _num(num) {}
	double Calc () const;
private:
	const double _num;
};

class VarNode: public Node
{
public:
	VarNode (int id, Store & store)
		: _id(id), _store(store) {}
	double Calc() const;
	bool IsLvalue () const;
	void Assign (double val);
private:
	const int _id;
	Store & _store;
};

class UniNode: public Node
{
public:
	UniNode (Node * pChild)
	: _pChild (pChild) {}
	~UniNode ();
protected:
	Node * const _pChild;
};

class BinNode: public Node
{
public:
	BinNode(Node * pLeft, Node * pRight)
		: _pLeft(pLeft), _pRight(pRight) {}
	~BinNode();
protected:
	Node * const _pLeft;
	Node * const _pRight;
};

class AddNode: public BinNode
{
public:
	AddNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight) {}
	double Calc() const;
};

class SubNode: public BinNode
{
public:
	SubNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight) {}
	double Calc() const;
};

class MultNode: public BinNode
{
public:
	MultNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight) {}
	double Calc () const;
};

class DivideNode: public BinNode
{
public:
	DivideNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight) {}
	double Calc () const;
};

class AssignNode: public BinNode
{
public:
	AssignNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight)
	{
		assert(pLeft->IsLvalue());
	}
	double Calc () const;
};

class FunNode: public UniNode
{
public:
	FunNode(PtrFun pFun, Node * pNode)
		: UniNode(pNode), _pFun(pFun)
	{}
	double Calc () const;
private:
	PtrFun _pFun;
};

class UMinusNode: public UniNode
{
public:
	UMinusNode (Node * pNode)
		: UniNode(pNode) {}
	double Calc () const;
};

#endif /* TREE_H_ */
