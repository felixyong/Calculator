/*
 * symTab.cpp
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#include "symTab.h"
#include <cassert>
#include <iostream>

SymbolTable::SymbolTable(int size)
	: _curId(0),
	  _maxId(size),
	  _htab(size + 1),
	  _strBuf(size * 10)
{
	_offStr = new int[size];
}

SymbolTable::~SymbolTable()
{
	delete []_offStr;
}

int SymbolTable::ForceAdd(char const * str, int len)
{
	// Is there enough space:
	if(_curId == _maxId || !_strBuf.WillFit(len))
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

int SymbolTable::Find(char const * str) const
{
	// Get a short list from hash table
	List const & list = _htab.Find(str);
	// Iterate over this lit
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
char const * SymbolTable::GetString(int id) const
{
	assert(id >= 0);
	assert(id < _curId);
	int offStr = _offStr[id];
	return _strBuf.GetString(offStr);
}
