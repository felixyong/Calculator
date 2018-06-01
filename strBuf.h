/*
 * strBuf.h
 *
 *  Created on: Jun 1, 2018
 *      Author: CNFELUO1
 */

#ifndef STRBUF_H_
#define STRBUF_H_

#include "HTab.h"
#include <cstring>

const int maxBufsize = 500;

class StringBuffer
{
public:
	explicit StringBuffer(int size)
		: _curOffset(0), _bufSize(size)
	{
		_buf = new char[size];
	}
	~StringBuffer()
	{
		delete []_buf;
	}
	bool WillFit(int len) const
	{
		return _curOffset + len + 1 < _bufSize;
	}
	void Add(char const * str)
	{
		std::strcpy(&_buf[_curOffset], str);
		_curOffset += std::strlen(str) + 1;
	}
	int GetOffset() const
	{
		return _curOffset;
	}
	bool IsEqual(int offStr, char const * str) const
	{
		char const * strStored = &_buf[offStr];
		return std::strcmp(str, strStored) == 0;
	}
	char const * GetString(int offStr) const
	{
		return &_buf[offStr];
	}
private:
	int _bufSize;
	char * _buf;
	int _curOffset;
};



#endif /* STRBUF_H_ */
