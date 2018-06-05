/*
 * Date.h
 *
 *  Created on: 2018Äê6ÔÂ5ÈÕ
 *      Author: Administrator
 */

#ifndef DATE_H_
#define DATE_H_
#include <iostream>

const int daysPerMonth = 30;
const int monthPerYear = 12;

class Date
{
public:
	Date(int yy, int mm, int dd);
	Date();
	~Date();
	void Display() const;
	bool IsLeapYear() const;
	Date operator + (int const days);
	bool operator > (Date const& date) const;

private:
	int _yy;
	int _mm;
	int _dd;
};

#endif /* DATE_H_ */
