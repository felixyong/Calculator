/*
 * symTab.h
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#ifndef SYMTAB_H_
#define SYMTAB_H_

#include "strBuf.h"
#include "hTab.h"

const int idNotFound = -1;

class SymbolTable
{
public:
	explicit SymbolTable(int size);
	~SymbolTable();
	int ForceAdd(char const * str, int len);
	int Find(char const * str) const;
	char const * GetString(int id) const;
private:
	HTable	_htab;	// string -> ids
	int _maxId;
	int * _offStr;	// id -> offset
	int _curId;
	StringBuffer _strBuf;	// offset -> string
};

#endif /* SYMTAB_H_ */
