/*
 * list.h
 *
 *  Created on: Apr 8, 2018
 *      Author: CNFELUO1
 */

#ifndef LIST_H_
#define LIST_H_

class Link
{
public:
	Link (Link * pNext, int id)
	: _pNext (pNext), _id (id) {}
	Link * Next () const {return _pNext;}
	int Id () const {return _id;}
private:
	int _id;
	Link * _pNext;
};

class List
{
public:
	List (): _pHead (0) {}
	~List ();
	void Add(int id);
	Link const * GetHead () const {return _pHead;}
private:
	Link * _pHead;
};



#endif /* LIST_H_ */
