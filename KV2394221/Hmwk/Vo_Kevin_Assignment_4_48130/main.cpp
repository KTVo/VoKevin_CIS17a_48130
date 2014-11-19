/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Book: Gaddis 7th Edition
 * Assignment: 4
 * Prob.1-> 13.1 Takes integers and display it in 3 diff. date formats
 * Prob.2-> 13.2 Takes employee information and then generate a chart
 * Prob.3-> 13.3 Accepts make and year of car and then display the acceleration
 * Prob.4-> 13.4 Have instances to hold personal information selectively
 * Prob.5-> 13.5 Takes info on item and then display it in a chart
 * Prob.6-> 14.2 Take an int of the day of the year and gives back the month+day
 * Prob.7-> 14.3 Same as Prob. 14.2 but loops operators ++ & --
 * Prob.8-> 14.4 Has +,-,++,-- operators to calcualate hours into days and hours
 * Prob.9-> 14.8 Similar to Prob. 13.1 but uses ++,--,-,insert, extract ops. 
 * Prob.10-> 14.10 Uses an array for the objects and then display sales & total
 * Created on November 17, 2014, 4:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "CH13Classes.h"
#include "CH14Classes.h"

using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();


    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          case 8:    problem8();break;
          case 9:    problem9();break;
          case 10:   problem10();break;
          default:   def(inN);}
        }while(inN<11);
        return 1;
    }
    void Menu()
    {
           cout<<"\nType 1 for problem 13.1"<<endl;
           cout<<"Type 2 for problem 13.2"<<endl;
           cout<<"Type 3 for problem 13.3"<<endl;
           cout<<"Type 4 for problem 13.4"<<endl;
           cout<<"Type 5 for problem 13.5"<<endl;
           cout<<"Type 6 for problem 14.2"<<endl;
           cout<<"Type 7 for problem 14.3"<<endl;
           cout<<"Type 8 for problem 14.4"<<endl;
           cout<<"Type 9 for problem 14.4"<<endl;
           cout<<"Type 10 for problem 14.10"<<endl;
           cout<<"Type 11 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    void problem1()
    {
            Date instance;//Defines an instance for class Date
    int inputMonth, inputDay, inputYear;

    //Prompts and requests user for the date
    cout<<"This problem will ask for the month, day, and year so that it can be"
        <<" put into a certain format\n";
    cout<<"\nNow please enter the following.\n";
    cout<<"Month (ex: 09): ";
    cin>>inputMonth;
    cout<<"Day (ex: 06): ";
    cin>>inputDay;
    cout<<"Year (ex: 1999): ";
    cin>>inputYear;

    //Input validation
    if (inputMonth > 12 || inputMonth < 1 || inputDay > 31 || inputDay < 1){
        cout<<"Input Validation: Do not accept values for the day greater than "
            <<"31 or less than 1. Do\nnot accept values for the month greater "
            <<"12 or less than 1.\n";
    }
    else{
        //Accepts inputted values so that it can be assigned to private members
        instance.setMonth(inputMonth);
        instance.setDay(inputDay);
        instance.setYear(inputYear);

        //String containing name of each month
        string nameMonth[12] = {"January", "Feburary", "March", "April", "May", 
            "June", "July", "August", "September", "October", "November", 
            "December"};

       //Displays all three format for dthe date
        cout<<endl<<instance.getMonth()<<"/"<<instance.getDay()<<"/"
            <<instance.getYear()<<endl;
        cout<<nameMonth[instance.getMonth()-1]<<" "<<instance.getDay()<<", "
            <<instance.getYear()<<endl;
        cout<<instance.getDay()<<" "<<nameMonth[instance.getMonth()-1]<<" "
            <<instance.getYear()<<endl;
    }
    }
    void problem2()
    {
        Employee emp1, emp2, emp3;

        //Requests and stores information
        cout<<"\nEmployee 1\n";
        emp1.getInfo();
        cout<<"\nEmployee 2\n";
        emp2.getInfo();
        cout<<"\nEmployee 3\n";
        emp3.getInfo();

        //Display results
        cout<<"\nName"<<setw(15)<<"ID Number"<<setw(15)<<"Department"<<setw(15)
            <<"Position\n";
        cout<<"-------------------------------------------------------------\n";
        emp1.displayResults();
        emp2.displayResults();
        emp3.displayResults();
    }
    void problem3()
    {
        int year, speed = 0;
        string make;

        cout<<"Enter the Year Model: ";
        cin>>year;
        cout<<"Enter the Car Make: ";
        cin>>make;
        //Accepts input as argument
        Car mac(year,make,speed);
        //Display original status and car make and year
        cout<<"\n\nYear: "<<mac.getYear()<<endl;
        cout<<"Make: "<<mac.getmake()<<endl;
        cout<<"Speed: "<<mac.getspeed()<<endl;
        //Accelerates and display by multiple of 5
        mac.accelerate(); mac.accelerate(); mac.accelerate(); mac.accelerate();
            mac.accelerate();
        cout<<"Accelerated Speed: "<<mac.getspeed()<<endl;
        //Decrease speed by a multi. of 5 then display
        mac.br(); mac.br(); mac.br(); mac.br(); mac.br();
        cout<<"Break Speed: "<<mac.getspeed()<<endl;
    }
    void problem4()
    {
        Data person1, person2, person3;
        cout<<"\nInput for Person 1\n";
        person1.getinfo();
        cout<<"\nInput for Person 2\n";
        person2.getinfo();
        cout<<"\nInput for Person 3\n";
        person3.getinfo();

        //Display results
        cout<<"\n***Results***\n";
        cout<<"Person 1\n";
        cout<<"Name: "<<person1.getname()<<endl;
        cout<<"Address: "<<person1.getaddr()<<endl;
        cout<<"Age: "<<person1.getage()<<endl;
        cout<<"Phone Number: "<<person1.getphone()<<endl;
        cout<<"\nPerson 2\n";
        cout<<"Name: "<<person2.getname()<<endl;
        cout<<"Address: "<<person2.getaddr()<<endl;
        cout<<"Age: "<<person2.getage()<<endl;
        cout<<"Phone Number: "<<person2.getphone()<<endl;
        cout<<"\nPerson 3\n";
        cout<<"Name: "<<person3.getname()<<endl;
        cout<<"Address: "<<person3.getaddr()<<endl;
        cout<<"Age: "<<person3.getage()<<endl;
        cout<<"Phone Number: "<<person3.getphone()<<endl;
    }
    void problem5()
    {
        //instances for the inputted items
        RetailItem a, b, c;
        cout<<"--Input for Item 1\n";
        a.getinfo();
        cout<<"--Input for Item 2\n";
        b.getinfo();
        cout<<"--Input for Item 3\n";
        c.getinfo();

        //Display results
        cout<<"Item #"<<setw(15)<<"Description"<<setw(10)<<"Units"<<setw(10)
            <<"Price\n";
        cout<<"--------------------------------------------------\n";
        cout<<"    #1"<<setw(10)<<a.getdesc()<<setw(10)<<a.getunits()<<setw(10)
            <<fixed<<setprecision(2)<<"$ "<<a.getprice()<<endl;
        cout<<"    #2"<<setw(10)<<b.getdesc()<<setw(10)<<b.getunits()<<setw(10)
            <<fixed<<setprecision(2)<<"$ "<<b.getprice()<<endl;
        cout<<"    #3"<<setw(10)<<c.getdesc()<<setw(10)<<c.getunits()<<setw(10)
            <<fixed<<setprecision(2)<<"$ "<<c.getprice()<<endl;
    }
    void problem6()
    {
        int inputDays;
        //Requests user to enter the day in number
        cout<<"Please the day in digit form: ";
        cin>>inputDays;
    
        //Accepts the input and display the result
        DayOfYear a(inputDays);
        a.calculate();
        a.displayDay();
    }
    void problem7()
    {
        int inputDays;
        
        cout<<"Enter a day of the year: ";
        cin>>inputDays;
       
        DayOfYearProb3 instance(inputDays);
        instance.calculate();
        instance.display();

        cout<<"\n-------------\n";
        for(int count = 0; count < 90; count++){
                inputDays++;
                instance.setDay(inputDays);
                instance.calculate();
                instance.display();
        }
    }
    void problem8()
    {
        int hour, day;
        NumDays one, two, result;
    
        //Requests for input
        cout<<"First Info.:\n";
        cout<<"Please enter the amount of day(s): ";
        cin>>day;
        cout<<"Please enter amount of hour(s): ";
        cin>>hour;
    
        //Obtains input for first inputs
        one.setHour(hour);
        one.setDays(day);

        cout<<"\nSecond Info.:\n";
        cout<<"Please enter the amount of day(s): ";
        cin>>day;
        cout<<"Please enter amount of hour(s): ";
        cin>>hour;

        //Obtain input of second input
        two.setHour(hour);
        two.setDays(day);

        //Adds the first and second inputs
        result = one + two;
    
        //Display results of sum and subtracted
        cout<<"\nSummed = ";
        cout<<result.getDays()<<" day(s) & "<<result.getHour()<<" hour(s)\n";
        //Subtracts
        result = one - two;

       cout<<"\nSubtracted = "<<result.getDays()<<" day(s) & "<<result.getHour()
           <<" hour(s)\n";

        //add & subtract with ++ & -- operators and loop to display
        cout<<"\n++ Operator (Adds an hour each time)\n";
        cout<<"-------------------------------\n";
    
        //for loop for ++ operator
        for(int count = 0; count < 20; count++){
            result.operator ++();
            cout<<result.getDays()<<" day(s) and "<<result.getHour()
                <<" hour(s)\n";
        }
    
        cout<<"\n--Operator (Deducts an hour each time)\n";
        cout<<"-------------------------------\n";
    
        //for loop for -- operator
        for(int count = 0; count < 20; count++){
            result.operator --();
            cout<<result.getDays()<<" day(s) and "<<result.getHour()
                <<" hour(s)\n";
        }
    }
    void problem9()
    {
        DateProb4 instance;
        //Obtains and stores the input
        instance.setMonth();
        instance.setDay();
        instance.setYear();
        //Displays result
        instance.display();
        //Loops the ++ operator and display
        for(int count = 0; count < 12; count++){
            instance.operator ++();
            instance.display();
        }
    }
    void problem10()
    {
        DivSales DivisionSale[6];
        int quarter, division;

        // This will pass quarter sales to AddSales
        for (division = 0; division < 6; division++){

        int Qrt1, Qrt2, Qrt3, Qrt4;
        int check;

        // Prompts the user for quarter sales of each division
        // divisions 1 - 6
        cout<<"\nEnter Sales of Division: "<<division+1<<endl;
        cout<<"Enter Quarter 1 Sales: ";
        cin>>Qrt1;
        check = Qrt1;
        if (check < 0){
           validate();
           }

        cout<<"\nEnter Quarter 2 Sales: ";
        cin>>Qrt2;
        check = Qrt2;
        if (check < 0){
           validate();
           }

        cout<<"\nEnter Quarter 3 Sales: ";
        cin>>Qrt3;
        check = Qrt3;
        if (check < 0){
           validate();
           }

        cout<<"\nEnter Quarter 4 Sales: ";
        cin>>Qrt4;
        check = Qrt4;
        if (check < 0){
           validate();
           }
        //Send all inputed value to totalSales
        DivisionSale[division].totalSales(Qrt1,Qrt2,Qrt3,Qrt4);
        }
        //Display table
        cout<<"\n---------------Results---------------\n";
        cout<<"\t"<<"Q1"<<"\t"<<"Q2"<<"\t"<<"Q3"<<"\t"<<"Q4\n";
        for (division = 0; division < 6; division++){
            cout<<"Div "<<division + 1;
            
            for (quarter = 0; quarter < 4; quarter++){
                cout<<"\t$" << DivisionSale[division].Sales(quarter);
            }
        cout<<endl;
        }
        cout<<"\n\nTotal Annual Sales: ";
        cout<<"$ "<<DivisionSale[0].getvalue()<<endl;
    }

    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }

