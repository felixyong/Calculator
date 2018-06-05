/*
 * Date.cpp
 *
 *  Created on: Jun 5, 2018
 *      Author: CNFELUO1
 */
#include "Date.h"

Date::Date(int yy, int mm, int dd)
	:_yy(yy), _mm(mm), _dd(dd)
{
}

Date::Date()
	:_yy(0), _mm(0), _dd(0)
{
}

Date::~Date()
{
}

void Date::Display() const
{
	std::cout << _yy << "-" << _mm << "-" << _dd << std::endl;
	if (IsLeapYear())
		std::cout << "It's a leap year.\n";
	else
		std::cout << "It's not a leap year.\n";
}

bool Date::IsLeapYear() const
{
	if (_yy % 4 != 0)
		return false;
	else if (_yy % 100 != 0)
		return true;
	else if ( _yy % 400 != 0)
		return false;
	else
		return true;
}

Date Date::operator + (int const days)
{
	Date temp;
	int mAdd, yAdd;
	mAdd = (this->_dd + days) / daysPerMonth;
	temp._dd = (this->_dd + days) % daysPerMonth;
	yAdd = (this->_mm + mAdd) / monthPerYear;
	temp._mm = (this->_mm + mAdd) % monthPerYear;
	temp._yy =this->_yy + yAdd;
	return temp;
}

bool Date::operator > (Date const& date) const
{
	if(this->_yy > date._yy)
		return true;
	else if (this->_mm > date._mm)
		return true;
	else if (this->_dd > date._dd)
		return true;
	else
		return false;
}
