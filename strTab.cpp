/*
 * strTab.cpp
 *
 *  Created on: Apr 8, 2018
 *      Author: CNFELUO1
 */
#include "strTab.h"

#include <cassert>
#include <iostream>

// Find the list in the hash table that may contain
// the id of the string we are looking for
/*
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
	// no empty string
	assert(str != 0 && str[0] != 0);
	unsigned h = str[0];
	for(int i = 1; str[i] != 0; ++i)
		h = (h << 4) + str[i];
	return h % sizeHTable;		// remainder
}
*/

// String table
StringTable::StringTable()
: _curId(0),
  _htab(maxBufSize)
{

}

int StringTable::ForceAdd(char const * str)
{
	int len = std::strlen(str);
	// is there enough space?
	if(_curId == maxStrings || !_strBuf.WillFit(len))
	{
		return idNotFound;
	}
	// point to the place where the string will be stored
	_offStr[_curId] = _strBuf.GetOffset();
	_strBuf.Add(str);
	// add mapping to hash table
	_htab.Add(str, _curId);
	++_curId;
	return _curId - 1;
}

int StringTable::Find(char const * str) const
{
	// Get a short list from hash table
	List const & list = _htab.Find(str);
	// Iterate over this list
	for(Link const * pLink = list.GetHead();
			pLink != 0;
			pLink = pLink->Next())
	{
		int id = pLink->Id();
		int offStr = _offStr[id];
		if(_strBuf.IsEqual(offStr, str))
			return id;
	}
	return idNotFound;
}

// map integer into string. Must be valid id
char const * StringTable::GetString(int id) const
{
	assert(id >= 0);
	assert(id < _curId);
	int offStr = _offStr[id];
	return _strBuf.GetString(offStr);
}
