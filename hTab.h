/*
 * hTab.h
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#ifndef HTAB_H_
#define HTAB_H_

#include "list.h"

class HTable
{
public:
	explicit HTable(int size) : _size(size)
	{
		_aList = new List[size];
	}
	~HTable()
	{
		delete []_aList;
	}
	// return a short list of candidates
	List const & Find(char const * str) const;
	// add another string->id mapping
	void Add(char const * str, int id);
private:
	// the hashing function
	int hash(char const * str) const;
	List * _aList;	// an array of (short) lists
	int _size;
};



#endif /* HTAB_H_ */
