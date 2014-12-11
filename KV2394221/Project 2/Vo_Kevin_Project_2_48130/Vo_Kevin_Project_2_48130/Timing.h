/* 
 * File:   Timing.h
 * Author: Kevin Vo
 *
 * Created on December 6, 2014, 11:12 AM
 */

#ifndef TIMING_H
#define	TIMING_H
using namespace std;
//******************************************************************************
//Inheritance Example
//Gets protected members from Time to convert it and display it
//******************************************************************************

class Time{ 
    protected:
	int hour;
	int min;
	int sec;
    public:
	Time(int h, int m, int s)
		{ hour = h; min = m; sec = s; }
	void setTime(int h, int m, int s)
		{ hour = h; min = m; sec = s; }
	int getHour()
		{ return hour; }
	int getMin()
		{ return min; }
	int getSec()
		{ return sec; }
};
#endif	/* TIMING_H */