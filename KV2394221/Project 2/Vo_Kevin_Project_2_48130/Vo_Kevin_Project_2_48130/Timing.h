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

//Example of inheritence where class ForeignTime is inheriting from class Time
class ForeignTime:public Time{
private:
	int foreignHr;//Contains 24hr format
        int ForSeconds;//Contains secs in standard form
public:
	ForeignTime(int h,int s):Time(0, 0, 0)
		{ setTime(h, s); }
	void setTime(int h,int s)
	{ 
                foreignHr = h;
                ForSeconds = s;
        	Time::setTime(ForeToStandHr(h), ForToStandMin(h),s);
	}

        //converts hours
	int ForeToStandHr(int fore)
	{
		fore /= 100;
		if(fore > 12){
                    return fore - 12;
                }        
		else{
                    return fore;
                }
	}

        //converts mins
	int ForToStandMin(int fore){
		fore %= 100; 
		fore *= 0.6; 
        return fore;}

        //Displays the time used foreign countries
	void getHour(){ 
            cout<<"24-hr Time: "<<foreignHr<<" hours.\n"; 
        }

        //Displays the time format used in the U.S.
	void getStandHr(){ 

            cout<<setfill('0')<<"12-hr Standard Time: "<<setw(2)<<Time::getHour()
                <<":"<<setw(2)<<getMin()<<endl; 
        }

};

class TimeClock:public ForeignTime{
    private:
	int start; 
        int stop;
    public:
	TimeClock(int time1,int time2):ForeignTime(abs(time1 - time2), 0)
		{ start = time1; stop = time2;}
	void display(){
            getHour();
            getStandHr();
	}

};


#endif	/* TIMING_H */