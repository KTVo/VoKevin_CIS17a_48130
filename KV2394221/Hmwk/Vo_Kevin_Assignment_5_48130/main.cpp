/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Book: Gaddis 7th Edition
 * Created on November 30, 2014, 1:01 PM
 * Prob. 15.1-> Employee and ProductionWorker Classes
 * Prob. 15.2-> ShiftSupervisor Class
 * Prob. 15.3-> TeamLeader Class
 * Prob. 15.4-> Time Format
 * Prob. 15.5-> Time Clock
 * Prob. 16.1-> Date Exceptions
 * Prob. 16.4-> Absolute Value Template
 * Prob. 16.5-> Total Template
 * Prob. 16.7-> TestScores Class
 * Prob. 16.10-> SortableVector ClassTemplate
 */

/*
* Checklist:
* 2 utilizing exceptions at least one with a class:
*   1) Prob. 16.1 -> Uses EXCEPTION and CLASS
*   2) Prob. 16.7 -> Uses EXCEPTION and CLASS
* 2 utilizing templates at least one with a class:
*   1) Prob. 16.10 -> Uses TEMPLATE and CLASS
*   2) Prob. 16.5 -> Uses TEMPLATE
*   3) Prob. 16.4 -> Uses TEMPLATE
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

#include "header.h"


void Menu();
int getN();
void def(int);
void problem15_1();
void problem15_2();
void problem15_3();
void problem15_4();
void problem15_5();
void problem16_1();
void problem16_4();
void problem16_5();
void problem16_7();
void problem16_10();

int main(int argv,char *argc[]){
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem15_1();break;
          case 2:    problem15_2();break;
          case 3:    problem15_3();break;
          case 4:    problem15_4();break;
          case 5:    problem15_5();break;
          case 6:    problem16_1();break;
          case 7:    problem16_4();break;
          case 8:    problem16_5();break;
          case 9:    problem16_7();break;
          case 10:    problem16_10();break;
          default:   def(inN);}
        }while(inN<11);
        return 1;
    }
void Menu()
    {
           cout<<"\nType 1 for problem 15.1"<<endl;
           cout<<"Type 2 for problem 15.2"<<endl;
           cout<<"Type 3 for problem 15.3"<<endl;
           cout<<"Type 4 for problem 15.4"<<endl;
           cout<<"Type 5 for problem 15.5"<<endl;
           cout<<"Type 6 for problem 16.1"<<endl;
           cout<<"Type 7 for problem 16.4"<<endl;
           cout<<"Type 8 for problem 16.5"<<endl;
           cout<<"Type 9 for problem 16.7"<<endl;
           cout<<"Type 10 for problem 16.10"<<endl;
           cout<<"Type 11 to exit \n"<<endl;
    }
int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }

void problem15_1(){
        int inputNum, inputShift;
        string inputName, inputDate;
        float inputPayRate;

        //Prompts and requests input
        cout<<"\nThis program will accept and display info of an employee.";
        cout<<"\nPlease enter the following information...\n";
        cout<<"Employee's Name: ";
        cin.ignore();
        getline(cin, inputName);
        cout<<"Employee's Number: ";
        cin>>inputNum;
        cout<<"Employee's Date of Hire: ";
        cin.ignore();
        getline(cin, inputDate);
        cout<<"Employee's Shift (Enter: 1 for day, 2 for night): ";
        cin>>inputShift;
        cout<<"Employee's Hourly Pay Rate: $";
        cin>>inputPayRate;

        Employee person(inputName, inputNum, inputDate);
        ProductionWorker pay(inputShift, inputPayRate);

        //Output results
        cout<<"\nDisplay Results\n";
        cout<<"---------------------\n";
        cout<<"Name: "<<person.getName()<<endl;
        cout<<"Number: "<<person.getNum()<<endl;
        cout<<"Date of Hire: "<<person.getDate()<<endl;
        //if statement determining whether inputed shift was day/night
        if(pay.getShift() == 1){
            cout<<"Shift: Day\n";}
        if(pay.getShift() == 2){
            cout<<"Shift: Night\n";
        }
        cout<<"Hourly Pay: $"<<fixed<<setprecision(2)<<pay.gethrPay()<<endl;
    }

void problem15_2(){
        string inName, inDate;
        int inNum;
        float inSalary, inBonus;

        //prompts and requests input
        cout<<"\nThis program accepts and display the info of a shift supervisor.";
        cout<<"\nEnter the following information\n";
        cout<<"Shift Supervisor's Name: ";
        cin.ignore();
        getline(cin, inName);//accepts string input with space
        cout<<"Shift Supervisor's Number: ";
        cin>>inNum;
        cout<<"Date of Hire: ";
        cin.ignore();
        getline(cin, inDate);//accepts string input with space
        cout<<"Shift Supervisor's Annual Salary: $";
        cin>>inSalary;
        cout<<"Shift Supervisor's Annual Production Bonus: $";
        cin>>inBonus;

        EmployeeProb2 pay(inName, inNum, inDate);
        ShiftSupervisor sSuper(inSalary, inBonus);

        //Outputs results
        cout<<"Name: "<<pay.getName()<<endl;
        cout<<"Number: "<<pay.getNum()<<endl;
        cout<<"Date of Hire: "<<pay.getDate()<<endl;
        cout<<"Annual Salary: $"<<sSuper.getSalary()<<endl;
        cout<<"Annual Production Bonus: $"<<sSuper.getBonus()<<endl;
    }
void problem15_3(){

    int num, hr, hrDone;
    string inName, inDate;
    float mBonus;

    cout<<"\nThis program determines if a Leader gets a fixed bonus or not.\n";
    cout<<"Please enter the following...\n";
    cout<<"--------------------------------\n";
    cout<<"Name: ";
    cin.ignore();
    getline(cin, inName);
    cout<<"Enter Employee's Number: ";
    cin>>num;
    cout<<"Date of Hire: ";
    cin.ignore();
    getline(cin, inDate);
    cout<<"Enter Monthly Bonus Amount: ";
    cin>>mBonus;
    cout<<"Required Training Hours: ";
    cin>>hr;
    cout<<"Completed Training Hours: ";
    cin>>hrDone;

    EmployeeProb2 personal(inName, num, inDate);
    TeamLeader train(mBonus, hr, hrDone);

    //Outputs the results
    cout<<"Employee Name: "<<personal.getName()<<endl;
    cout<<"Employee Number: "<<personal.getNum()<<endl;
    cout<<"Employee Hire Date: "<<personal.getDate()<<endl;

    //Determines if leader gets a fixed bonus
    if(train.getHrDone() >= train.getHrNeed()){
        cout<<"Bonus = $"<<train.getBonus()<<endl;
    }
    if(train.getHrDone() < train.getHrNeed()){
        cout<<"No bonus.\n";
    }
}
    void problem15_4(){
        int inputTime;
        
        //Prompts then requests for start and end time
        cout<<"This program requests the start & end time in military format &"
            <<" then display the elapses time\n";
        cout<<"Enter Starting Time (military format): ";
        cin>>inputTime;


        //input validation check    
        if(inputTime > 2359 || inputTime < 0){
            cout<<"\nInput Validation: The class shouldn't accept hours greater"
                <<" than 2359 or less than 0.\n";
        }

        else{
            TimeClock time(inputTime, 0);
            time.display();
            cout<<endl;
            }
    }
    
    void problem15_5(){
        int timeStart, timeStop;
        
        //Prompts then requests for start and end time
        cout<<"This program requests the start & end time in military format &"
            <<" then display the elapses time\n";
        cout<<"Enter Starting Time (military format): ";
        cin>>timeStart;
        cout<<"Enter Ending Time (military format): ";
        cin>>timeStop;

        //input validation check    
        if(timeStart > 2359 ||timeStart < 0 || timeStop > 2359 || timeStop < 0){
            cout<<"\nInput Validation: The class shouldn't accept hours greater"
                <<" than 2359 or less than 0.\n";
        }

        else{
            TimeClock time(timeStart, timeStop);
            cout<<"\n\t\tResults\n-------------------------------------\n";
            time.getStandHr2();
            cout<<endl;
            }
    }
    void problem16_1(){
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

        try{
            //Accepts inputted values so that it can be assigned to private memb
            instance.setMonth(inputMonth);
            instance.setDay(inputDay);
            instance.setYear(inputYear);

            //String containing name of each month
            string nameMonth[12] = {"January", "Feburary","March","April","May", 
                "June", "July", "August", "September", "October", "November", 
                "December"};

        //Displays all three format for the date
            cout<<endl<<instance.getMonth()<<"/"<<instance.getDay()<<"/"
                <<instance.getYear()<<endl;
            cout<<nameMonth[instance.getMonth()-1]<<" "<<instance.getDay()<<", "
                <<instance.getYear()<<endl;
            cout<<instance.getDay()<<" "<<nameMonth[instance.getMonth()-1]<<" "
                <<instance.getYear()<<endl;
        }
        catch(Date::InvalidDay){
            cout<<"\nError: Day is not between 1 and 31.\n";
        }
        catch(Date::InvalidMonth){
            cout<<"\nError: Month is not between 1 and 12.\n";
        }
    }
    void problem16_4(){
        int numDigit;
        cout<<"This program will accept values then display the total using "
            <<"template called total.\n";
        cout<<"Enter in the total number of digits that will be entered.\n";
        cout<<"User Input: ";
        cin>>numDigit;
        cout<<"\n\nTotal = "<<total(numDigit)<<endl;
    }
    void problem16_7(){
        const int mArrSize = 100;
        int numTest;
        float inScore[mArrSize], checker;
    
        cout<<"Please enter the number of test scores: ";
        cin>>numTest;

        for(int count = 0; count < numTest; count ++){
            cout<<"Enter score of test#"<<count+1<<": ";
            cin>>inScore[count];
        }
    
        //checks for input errors
        try{
            TestScores test(numTest, inScore);
            cout<<"\nThe Average is: "<<test.getAvg()<<endl;
        }
        catch(TestScores::InvalidInput){
            cout<<"\nError: The test scores' values is negative greater than 100.\n";
        }
    }
    
    void problem16_5(){
        float inVal;
        
        cout<<"This program will accept a value & display its absolute value.\n";
        cout<<"Please enter a numeric value: ";
        cin>>inVal;
        cout<<"\nAbsolute Value = "<<e(inVal)<<endl;
    }
    
    void problem16_10(){
        int numDigit;//holds the amount of elements for the array
        float inDigit;//sorts the elements so that it can be sorted

        //Requests user number of elements and values for each of them
        cout<<"How many digits do you wish to be sorted?\n";
        cout<<"User Input: ";
        cin>>numDigit;
        SortableVector<float> vect(numDigit);
        cout<<"\nPlease enter the following digits.\n";
    
        //Loops and assign inputs
        for(int count = 0; count < numDigit; count++){
            cout<<"Digit #"<<count + 1<<": ";
            cin>>inDigit;
            vect[count] = inDigit;
        }

        //Sorts and then displays the result
        vect.sorter();
        cout<<"\n\tResult\n---------------------------\n";
        for(int count = 0; count < numDigit; count++){
        cout<<"\t"<<vect.getValue(count)<<endl;
        }
    }
    

    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }

