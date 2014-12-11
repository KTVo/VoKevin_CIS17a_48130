#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

#include "Timing.h"

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
