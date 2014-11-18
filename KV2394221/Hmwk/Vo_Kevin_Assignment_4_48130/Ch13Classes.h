/* 
 * File:   Ch13Classes.h
 * Author: Kevin Vo
 *
 * Created on November 17, 2014, 4:58 PM
 */

#ifndef CH13CLASSES_H
#define	CH13CLASSES_H
using namespace std;
//Class for Prob. 13_1
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
};

//Assigns the private members the inputted values
void Date::setDay(int iDay){
    day = iDay;
}

void Date::setMonth(int iMonth){
    month = iMonth;
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

//Prob. 13_2
class Employee{
    private:
        string name;
        int idNumber;
        string department;
        string position;
    public:
        void getInfo();
        void displayResults();
};

void Employee::getInfo(){
    string nam, depart, posit;
    int idNum;
    cout<<"Please enter the following...\n";
    cout<<"ID Number: ";
    cin>>idNum;
    idNumber = idNum;
    cout<<"Name: ";
    cin>>nam;
    name = nam;
    cout<<"Department: ";
    cin>>depart;
    department = depart;
    cout<<"Position: ";
    cin>>position;
    position = posit;
}

void Employee::displayResults(){
    cout<<name<<setw(10)<<idNumber<<setw(18)<<department<<setw(20)
    <<position<<endl;
}

//Prob. 13_3
class Car{
    private:
        int yearModel;
        string make;
        int speed;
    
    public:
        Car(int, string, int);
        int getYear() const{
            return yearModel;
        }
        string getmake() const{
            return make;
        }
        int getspeed() const{
            return speed;
        }
        //Constructors for acceleration and breaking
        int accelerate();
        int br();
};



Car::Car(int y, string m, int s){
    yearModel = y;
    make = m;
    speed = s;
}

int Car::accelerate(){
        speed += 5;
}

int Car::br(){
    speed -= 5;
}


//Prob. 13_4
class Data{
   private:
       string name;
       string address;
       int age;
       string phone;
   public:
       void getinfo();
       string getname(){
           return name;
       }
       string getaddr(){
           return address;
       }
       int getage(){
           return age;
       }
       string getphone(){
           return phone;
       }
};

void Data::getinfo(){
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Phone Number: ";
    cin>>phone;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Address: ";
    cin>>address;
 
}

//Prob. 13_4
class RetailItem{
   private:
       string descrption;
       int unitsOnHand;
       float price;
   public:
       void getinfo();
       string getdesc(){
           return descrption;
       }
       int getunits(){
           return unitsOnHand;
       }
       float getprice(){
           return price;
       }
};

void RetailItem::getinfo(){
    cout<<"Please enter the following...\n";
    cout<<"Description: ";
    cin>>descrption;
    cout<<"Units: ";
    cin>>unitsOnHand;
    cout<<"Price: ";
    cin>>price;
}

#endif	/* CH13CLASSES_H */

