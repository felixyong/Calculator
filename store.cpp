/*
 * store.cpp
 *
 *  Created on: Jun 3, 2018
 *      Author: CNFELUO1
 */
#include "store.h"
#include "symTab.h"
#include <iostream>
#include <cassert>
#include <math.h>

Store::Store(int size, SymbolTable & symTab)
	: _size(size)
{
	_cell = new double [size];
	_status = new unsigned char [size];
	for(int i = 0; i < size; ++i)
	{
		_status [i] = stNotInit;
	}

	// add predefined constants
	// Note: if more needed, do a more general job
	std::cout << "e = " << exp(1) << std::endl;
	int id = symTab.ForceAdd("e", 1);
	SetValue(id, exp(1));
	std::cout << "pi = " << 2 * acos (0.0) << std::endl;
	id = symTab.ForceAdd("pi", 2);
	SetValue(id, 2.0 * acos(0.0));
}



