/* 
 * File:   header
 * Author: Kevin Vo
 *
 * Created on November 30, 2014, 1:13 PM
 */

#ifndef header
#define	header
using namespace std;

//Prob 15.1
class Employee{
    private:
        string name;
        int num;
        string hireDate;
    public:
        Employee(){};
        Employee(string, int, string);
        //Accessor + mutator functions
        void setName(string);
        string getName() const;
        void setNum(int);
        int getNum() const;
        void setDate(string);
        string getDate() const;
};

class ProductionWorker:public Employee{
        private:
            int shift;//represents shift where empolyee works day = 1 night = 2
            float hrPay;
        public:
            ProductionWorker(){};
            ProductionWorker(int, float);
            //Accessor + mutator functions
            void setShift(int);
            int getShift()const;
            void sethrPay(float);
            float gethrPay() const;
};



Employee::Employee(string empName, int empNum, string empDate){
    name = empName;
    num = empNum;
    hireDate = empDate;
};

//Mutators
void Employee::setName(string mutName){
    name = mutName;
}

void Employee::setNum(int mutNum){
    num = mutNum;
}

void Employee::setDate(string mutDate){
    hireDate = mutDate;
}

//Accessors
string Employee::getName() const{
    return name;
}

int Employee::getNum() const{
    return num;
}

string Employee::getDate() const{
    return hireDate;
}

ProductionWorker::ProductionWorker(int SHIFT, float payRate){
    shift = SHIFT;
    hrPay = payRate;
}

void ProductionWorker::setShift(int mutShift){
    shift = mutShift;
}

int ProductionWorker::getShift()const{
    return shift;
}

void ProductionWorker::sethrPay(float mutPay){
    hrPay = mutPay;
}

float ProductionWorker::gethrPay() const{
    return hrPay;
}

//Problem 15.2
class EmployeeProb2{
    private:
        string name;
        int number;
        string date;
    
    public:
        EmployeeProb2(){};
        EmployeeProb2(string, int, string);
        //Accessor Functions
        string getName() const;
        int getNum() const;
        string getDate() const;
        //Mutator Functions
        void setName(string);
        void setNum(int);
        void setDate(string);
};

class ShiftSupervisor: public EmployeeProb2{
    private:
        float salary;
        float bonus;
    
    public:
        ShiftSupervisor(){};
        ShiftSupervisor(float, float);
        //Accessor + mutator
        float getSalary() const;
        void setSalary(float);
        float getBonus() const;
        void setBonus(float);
};


EmployeeProb2::EmployeeProb2(string nam, int num, string dat){
    name = nam;
    number = num;
    date = dat;
}

//Accessor for class EmployeeProb2
string EmployeeProb2::getName() const{
    return name;
}

int EmployeeProb2::getNum() const{
    return number;
}

string EmployeeProb2::getDate() const{
    return date;
}

//Mutator for class EmployeeProb2
void EmployeeProb2::setName(string mutName){
    name = mutName;
}
void EmployeeProb2::setNum( int mutNum){
    number = mutNum;
}

void EmployeeProb2::setDate(string mutDate){
    date = mutDate;
}

ShiftSupervisor::ShiftSupervisor(float sal, float bon){
    salary = sal;
    bonus = bon;
}

//Accessor for ShiftSupervisor
float ShiftSupervisor::getSalary() const{
    return salary;
}

float ShiftSupervisor::getBonus() const{
    return bonus;
}

//Mutator for ShiftSupervisor
void ShiftSupervisor::setSalary(float mutSal){
    salary = mutSal;
}

void ShiftSupervisor::setBonus(float mutBonus){
    bonus = mutBonus;
}

//Prob 15.3
class TeamLeader: public ProductionWorker{
    private:
        float mBonus;
        int hrNeed;
        int hrDone;
    public:
        TeamLeader(){};
        TeamLeader(float, int, int);
        float getBonus() const;
        int getHrNeed() const;
        int getHrDone() const;
        void setBonus(float);
        void setHrNeed(int);
        void setHrDone(int);
};


TeamLeader::TeamLeader(float bon, int hrsN, int hrsD){
    mBonus = bon;
    hrNeed = hrsN;
    hrDone = hrsD;
}

//Accessor
float TeamLeader::getBonus() const{
    return mBonus;
}

int TeamLeader::getHrNeed() const{
    return hrNeed;
}

int TeamLeader::getHrDone() const{
    return hrDone;
}

//Mutators
void TeamLeader::setBonus(float mutBonus){
    mBonus = mutBonus;
}

void TeamLeader::setHrNeed(int mutNeed){
    hrNeed = mutNeed;
}

void TeamLeader::setHrDone(int mutDone){
    hrDone = mutDone;
}


//Problem 15.4 & 15.5
//Time.h from Program 15-18 in book
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

class MilTime:public Time{
private:
	int milHours;//Contains 24hr format
        int milSeconds;//Contains secs in standard form
public:
	MilTime(int h,int s):Time(0, 0, 0)
		{ setTime(h, s); }
	void setTime(int h,int s)
	{ 
                milHours = h;
                milSeconds = s;
        	Time::setTime(MilToStandHr(h),MilToStandMin(h),s);
	}

        //converts hours
	int MilToStandHr(int mil)
	{
		mil /= 100;
		if(mil>12){
                    return mil - 12;
                }        
		else{
                    return mil;
                }
	}

        //converts mins
	int MilToStandMin(int mil){
		mil %= 100; 
		mil *= 0.6; 
        return mil;}


	void getHour(){ 
            cout<<"Millitary Time: "<<milHours<<" hours & "
                <<milSeconds<<" seconds\n"; 
        }
        //cout standard time for problem 15.4
	void getStandHr(){ 
            cout<<setfill('0')<<"Standard Time: "<<setw(2)<<Time::getHour()
                <<":"<<setw(2)<<getMin()<<":"<<setw(2)<<getSec(); 
        }
        //cout time elapsed for problem 15.5
        void getStandHr2(){ 
            cout<<setfill('0')<<"Time Elapsed (HR:MIN:SEC): "<<setw(2)
                <<Time::getHour()<<":"<<setw(2)<<getMin()<<":"<<setw(2)
                <<getSec()<<endl; 
        }

};

class TimeClock:public MilTime{
    private:
	int start; 
        int stop;
    public:
	TimeClock(int time1,int time2):MilTime(abs(time1 - time2), 0)
		{ start = time1; stop = time2;}
	void display(){
		cout<<"\nTime Converted:\n";
                cout<<"-----------------\n";
		getHour();
		getStandHr();
	}

};


//Problem 16.1

//Blueprint for objects dealing with Date
class Date{
    private://Members that can only be used by this class
        int month;
        int day;
        int year;
    public://Members that can be used elsewhere too
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        //Exception Classes
        class InvalidDay{};
        class InvalidMonth{};
};

//Problem 16.4
template <class T>
    T e(T value){ return abs(value); }

//Problem 16.5
template <typename T>
T total(T numValues){
    T total = 0;
    T value = 0;

    for(int count = 1; count <= numValues; count++){
        cout<<"Enter Digit #"<<count<<": ";
        cin>>value;
    total+=value;	
    }
return total;}

//Assigns the private members the inputted values
void Date::setDay(int iDay){
    if (iDay >= 1 && iDay <= 31)
        day = iDay;
    else
    throw InvalidDay();
}

void Date::setMonth(int iMonth){
    if (iMonth >= 1 && iMonth <= 12)
        month = iMonth;
    else
    throw InvalidMonth();
}

void Date::setYear(int iYear){
   year = iYear;
}

//Calls for value private members to be displayed in the main function
int Date::getDay()const{    
    return day;
}

int Date::getMonth()const{
    return month;
}

int Date::getYear()const{
    return year;
}



//Problem 16_7
class TestScores{
    private:
        float *ptrScores;//pointer to test score
        int arrSize; //holds the size of the array
    public: 
        //Constructor accepting array and int and assigns it to private members
        TestScores(int numOfTest, float Score[]){
            ptrScores = Score;
            arrSize = numOfTest;
        };
        float getAvg() const;//calculates and returns the average
        class InvalidInput{};//Exception class that checks for input errors
};

float TestScores::getAvg()const{
    float totalSum = 0.0;
    float checker;

    //Loop checks for valid input then calculates avg
    for (int count = 0; count < arrSize; count++){
        checker = ptrScores[count];
        
        if(checker >= 0 && checker <= 100){
            totalSum = totalSum + ptrScores[count];
        }
        else{ throw InvalidInput();}
    }

return (totalSum/arrSize);}

//Problem 16_10
template <class T>
class SortableVector{
    private:
        T *ptrArray;//Points to the array
        int arraySize;
        void memError();//Handles memory allocation errors
        void subError();//Handles subscripts that are out of range
        void quickSort(T *, int, int);//Uses quicksort algorithm to sort
        //Obtains mid. value so that # can be sorted around it
        int partition(T *, int, int);
    public:
        SortableVector(){ptrArray = 0; arraySize = 0;}
        SortableVector(int);
        SortableVector(const SortableVector &);
        ~SortableVector();
        int size() const{return arraySize;}
        T getValue(int position);
        void sorter();
        T &operator[] (const int &);
};

    
template <class T>
//Defines the size of array and allocates memory while checking for neg. values
SortableVector<T>::SortableVector(int size){
    //set array size and allocate memory
    arraySize = size;
    try{
        ptrArray = new T[size];
    }
    catch (bad_alloc){
        memError();
    }

    for(int count = 0; count < arraySize; count++){
        *(ptrArray + count) = 0;
    }
}

template <class T>
SortableVector<T>::SortableVector(const SortableVector &c){
    arraySize = c.arraySize;
    ptrArray = new T [arraySize];
    if(ptrArray == 0){memError();}
    for(int count = 0; count < arraySize; count++){
        *(ptrArray + count) = *(c.ptrArray + count);
    }
}

template <class T>
    SortableVector<T>::~SortableVector(){
        if(arraySize > 0){delete [] ptrArray;}
}

template <class T>
//Displays and ends the program when there's a negative value
void SortableVector<T>::memError(){
    cout<<"Error: The amount entered must be a positive.\n";
    exit(EXIT_FAILURE);}

//Displays and ends the program when the subscript is out of range
template <class T>
void SortableVector<T>::subError(){
    cout<<"Error: The subscript is out of range.\n";
    exit(EXIT_FAILURE);}

//Gives the array values and checks if the subscript is in range.
template <class T>
T SortableVector<T>::getValue(int elem){
    if(elem < 0 || elem >= arraySize){subError();}
return ptrArray[elem];}

template <class T>
T &SortableVector<T>::operator[](const int &elem){
    if(elem < 0 || elem >= arraySize){subError();}
return ptrArray[elem];}

template <class T>
void SortableVector<T>::sorter(){ quickSort(ptrArray, 0, arraySize); }

//quicksort uses quicksort algorithm to sort the values
template <class T>
void SortableVector<T>::quickSort(T *ptrArray, int start, int end){
    int middle;
    if(start < end){
        middle = partition(ptrArray, start, end);
        quickSort(ptrArray, start, middle);
        quickSort(ptrArray, middle+1, end);
    }
return;}

    //Selects and return the middle value
    template <class T>
    int SortableVector<T>::partition(T *ptrArray, int start, int end){
        T arrStart = ptrArray[start], holder;
        int com = (start - 1), mid = (end + 1);

        do{
            do{ mid--; }while (arrStart > ptrArray[mid]);
            do{ com++; }while (arrStart < ptrArray[com]);
            if(com < mid){
                holder = ptrArray[com];
                ptrArray[com] = ptrArray[mid];
                ptrArray[mid] = holder;
            }
        }while(com < mid);
return mid;}

#endif	

