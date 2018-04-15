/*
 * tree.h
 *
 *  Created on: 2018Äê4ÔÂ15ÈÕ
 *      Author: Administrator
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>

class Node
{
public:
	virtual ~Node () {}
	virtual double Calc () const = 0;
};

class NumNode: public Node
{
public:
	NumNode(double num): _num(num) {}
	double Calc () const;
private:
	const double _num;
};
double NumNode::Calc () const
{
	std::cout << "Numeric node " << _num << std::endl;
	return _num;
}

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
BinNode::~BinNode()
{
	delete _pLeft;
	delete _pRight;
}

class AddNode: public BinNode
{
public:
	AddNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight) {}
	double Calc() const;
};

double AddNode::Calc() const
{
	std::cout << "Adding\n";
	return _pLeft->Calc() + _pRight->Calc();
}

class MultNode: public BinNode
{
public:
	MultNode(Node * pLeft, Node * pRight)
		: BinNode(pLeft, pRight) {}
	double Calc () const;
};
double MultNode::Calc() const
{
	std::cout << "Multiplying\n";
	return _pLeft->Calc() * _pRight->Calc();
}

#endif /* TREE_H_ */
