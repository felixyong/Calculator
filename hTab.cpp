/*

 * hTab.cpp
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#include "hTab.h"
#include <cassert>

// Find the list in the hash table that may contain
// the id of the string we are looking for

List const & HTable::Find(char const * str) const
{
	int i = hash(str);
	return _aList[i];
}

void HTable::Add(char const * str, int id)
{
	int i = hash(str);
	_aList[i].Add(id);
}

int HTable::hash(char const * str) const
{
	// no empty strings
	assert(str != 0 && str[0] != 0);
	unsigned h = str[0];
	for(int i = 1; str[i] !=0; ++i)
		h = (h << 4) +str[i];
	return h % _size; //remainder
}


