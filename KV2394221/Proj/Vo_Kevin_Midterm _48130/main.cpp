/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Student ID: 2394221
 * Assignment: Midterm
 * Class: CSC-17A (48130)
 * Created on October 24, 2014, 1:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//constant global variable for Prob. 4 input
const int inputCap = 4;

//Structure of Prob. 1
struct Customer{
    int accountNum;//holds the account number
    float balance;//holds the beginning balance
    float totalCheck = 0.0;//holds total of checks
    float totalDeposit = 0.0;//holds total of deposits
};

//Structure of Prob. 2
struct employeePay{
    string name; //stores the employee's name for identification
    int hoursWork; //stores the hours of which the person worked
    float rate; //stores the rate of which the person earns an hour
};

//Structure for Probelm 3
struct statsResult{
    float avg;
    float median;
    int *mode; 
    int nModes; 
    int maxFreq; 
};

//Function for menu
void Menu();
int getN();
void def(int);
void problem1();
int problem2();
void problem3();
int problem4();
void problem5();
void problem6();

//Function Prototypes for Prob. 3
statsResult *avgMedMode(int *, int);
void printStat(statsResult *);
void aMmPlacement(int *, int);
//Function Prototypes for Prob. 4
int *inputDecryption(int *);
int *inputEncryption(int *);
void changer(int &, int &);
void displayResult(int*, string ="");


//Begin Execution Here!!!
int main(int argv,char *argc[]){
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
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\nMenu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
    cout<<"User Input: ";
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    const int size = 100;//sets max # of customers
    const int accChecker = 100000;//Checks if account number is under 5 digits
    Customer *c = new Customer[size];
    char yesNo;
    float inputAmount;
    int numCust;

    //Prompts and asks for # of customers
    cout<<"This application determines if customer(s) has exceeded their "
        <<"balance.\n";
    cout<<"How many customers will you be entering?\n";
    cout<<"User Input: ";
    cin>>numCust;
    
    //For loop loops the session for each customer
    for(int count = 0; numCust > count; count++){
        
        //Do while loop makes sure that account number stays under 5 digits
        do{
            cout<<"\nAccount Number: ";
            cin>>c-> accountNum;
            
            if((c-> accountNum/accChecker) > 1 || c-> accountNum == 123456){
                cout<<"You have exceeded 5 digits. Please re-enter your account"
                    <<"number and try again.\n\n";
            }   
           }while((c-> accountNum/accChecker) > 1 || c-> accountNum == 123456);

        //Requests User to enter in a balance for the beginning of the month
        cout<<"Current Balance: $";
        cin>>c-> balance;

        //Asks & loops until the person is done entering checks
        cout<<"\nWould you like to input check(s)? (y/n): ";
        cin>>yesNo;

        if(yesNo == 'Y' || yesNo == 'y'){
            do {
                cout<<"*Note: Type in '0' when all checks have been entered "
                    <<"to continue.\n\nWhat is the amount for check #"<<": $";
                cin>>inputAmount;
                c->totalCheck = c-> totalCheck + inputAmount;
            } while(inputAmount != 0);
        }

        //Asks & loops until the person is done entering the deposits
        cout<<"Would you like to input deposits(s)? (y/n): ";
        cin>>yesNo;
        if(yesNo == 'Y' || yesNo == 'y'){
            do{
                cout<<"*Note: Type in '0' when all deposits have been entered "
                    <<"to continue.\n\n";
                cout<<"Deposit Amount: $";
                cin>>inputAmount;
                c-> totalDeposit = c-> totalDeposit + inputAmount;
            } while(inputAmount != 0);
        }

        //Makes calculations for current balance
        c-> balance = c-> balance - c-> totalCheck;
        c-> balance = c-> balance + c-> totalDeposit;
        //Displays current balance with current account #
        cout<<"\nAccount Number: "<<c-> accountNum<<"\t Current Balance: $"
            <<fixed<<setprecision(2)<<c-> balance<<endl;

        //Displays if an overdrawn exists
        if(c-> balance < 0){
            cout<<"Sorry, but your account was overdrawn. A fee of $12 will "
            "now be assesed.\n";
            c-> balance = c-> balance - 12;//Applies the $12 fee.
        cout<<"\nUpdated Balance: $"<<fixed<<setprecision(2)<<c-> balance<<endl;
        }
        
        if(c-> balance >= 1){
        cout<<"\nThank you and have a nice day!\n";
        }
        
    }
    delete[] c;//Clears the memory
}

int problem2(){
    int numEmpolyee;
    float totalPay = 0.0;//Stores and displays the total value

    //Prompts the user
    cout<<"How many employees will are being entered?\n";
    cout<<"User Input: ";
    cin>>numEmpolyee;

    //allocate dyn memory for multiple employees
    employeePay *emp = new employeePay[numEmpolyee];

    //For loop to cycle through one empolyee then the next
    for (int countEmpolyee = 0; countEmpolyee < numEmpolyee; countEmpolyee++){
        cout<<"\nName of Employee #"<<countEmpolyee+1<<": ";//Asks for name
        cin.ignore();
        getline(cin, emp-> name);
        
        //Asks for the # of hours worked for that employee
        cout<<"\nHours Worked: ";
        cin>>emp-> hoursWork;
        
        //Checks for ours input validation
        if(emp-> hoursWork < 0){
            cout<<"Cannot accept negative number of hours worked.\n";
        return 0;}

        cout<<"\nPay rate (per hour): $";
        cin>>emp-> rate;
        
        //Checks for rate input validation
        if (emp-> rate < 0){
            cout<<"Cannot accept negative number of rate of pay.\n";
        return 0;}
        
    //Calculates the the gross pay if hours worked is 20 or less
    if(emp-> hoursWork <= 20){ 
        totalPay = (emp-> rate * emp-> hoursWork);
    }
    //Calculates the the gross pay if hours worked is 40 or less
    else if(emp-> hoursWork <= 40){ 
        totalPay = (emp-> rate*20 + (emp-> rate * 2) * 
            (emp-> hoursWork-20));
    }
    //Otherwise
    else {totalPay = (emp-> rate * 20 + emp-> rate *
        40 + emp-> rate * 3 * emp-> hoursWork - 40);}

    cout<<"\t\t\t\t***Total Earning: $"<<fixed<<setprecision(2)
            <<totalPay<<endl;
    }
    delete []emp;
}

void problem3(){
    int numDigits = 0;
    statsResult *aMm;

    cout<<"How many digits will be entered?\n";
    cout<<"User Input: ";
    cin>>numDigits;

    int *digitInput = new int[numDigits];

    for(int count =  0; count < numDigits; count++){
        cout<<"User Input #"<<count+1<<": ";
        cin>>digitInput[count];
    }

    aMmPlacement(digitInput, numDigits);
    aMm = avgMedMode(digitInput, numDigits);
    printStat(aMm);

    delete aMm;
    delete []digitInput;
}

//Problem 3 Functions 
//Calculates
statsResult *avgMedMode(int *digitInput, int numDigits){
    float num = 0.0;
    bool change = false;
    statsResult *result = new statsResult();
    int modeMinor = 0, nmodes = 0, countC = 0;
    result-> maxFreq = 0;

    for(int count = 0; count < numDigits; count++){
        num = num + digitInput[count];
    }

    //Calculates the average
    result-> avg = num/numDigits;
    
    //Looks for the median
    if (numDigits %2 == 1){
    result-> median = digitInput[(numDigits - 1)/2];
    }

    else{
        result-> median = (digitInput[numDigits/2] + 
            digitInput[1 + (numDigits /2)])/2;
    }
    
    num = 1;
    for(int count = 0; count < numDigits - 1; count++){
        if(digitInput[count] == digitInput[count + 1]){
        num++;
    }
    
    else if(digitInput[count] != digitInput[count + 1]){
        if(num > result-> maxFreq)
        result-> maxFreq=num;
        num=  1;
    }

    if(count == numDigits - 2 && result-> maxFreq<num)
        result-> maxFreq=num;
    }

    //Finds the mode
    for (int count = 0; count < numDigits; count++) {
        if (digitInput[count] > modeMinor){
            modeMinor = digitInput[count];
        }
    }
    result-> mode = &modeMinor;

    //Find the number of modes
    for(int count = 1; count < numDigits; count++){
        if(digitInput[count] == digitInput[count - 1]){
            countC++;
            if(result-> maxFreq==countC){
                nmodes++;
            }
        }else{
           countC=0;
        }
    }
    result->nModes = nmodes+2;
return result;}

void aMmPlacement(int *digitInput, int numDigits){
    bool change;

    do{
        int num;
        change = false;
        
        for(int count = 0; count < numDigits; count++){
            if(digitInput[count] > digitInput[count + 1]){
                num = digitInput[count];
                digitInput[count] = digitInput[count + 1];
                digitInput[count + 1] = num;
                change = true;
            }
        }
    }while(change == true);
}

//Displays Result
void printStat(statsResult *aMm){
    cout<<"\n***Results***\n";
    cout<<"-----------------------------------------------";
    cout<<"\nAverage: "<<aMm-> avg;
    cout<<"\nMedian: "<<aMm-> median;
    cout<<"\nNumber of Modes: "<<aMm->nModes;
    cout<<"\nMax Frequency: "<<aMm-> maxFreq;
    cout<<"\nMode: "<<*aMm-> mode;
    cout<<"\n-----------------------------------------------\n";
}

int problem4(){
    int digitInput, selectInput;
    int *inputPtr = new int [inputCap];
    bool btw07;
    char repeat;


    //Prompts user of the program
    cout<<"This program will encrypt your data / decrypt already encrypted data"
        <<". Please insert your data below.\n";
    cout<<"Input Data (4 digits only): ";
    cin>>digitInput;

    //For loop to put the input into array
    for (int count = 3; count >= 0; --count) {
        inputPtr[count] = (digitInput % 10);
        digitInput = (digitInput/10);
    }

    //Checks if the inputted value
    for (int count = 0; count != 4; ++count){
        if (*(inputPtr + count) > 7){
            btw07 = 0;
        }
        btw07 = 1;
    }

    if (btw07) {
    //Asks for a encryption or decr
    cout<<"What would you like to do with the inputted data?\nEnter 1 for "
    <<"Encryption.\nEnter 2 for Decryption.\n";
    cin>>selectInput;

        if (selectInput == 1){
            inputPtr = inputEncryption(inputPtr);
            cout<<"Encrypted Value: ";
            displayResult(inputPtr);
        }
        // user wants to decrypt number
        else if (selectInput == 2){
            inputPtr= inputDecryption(inputPtr);
            cout<<"Decrypted Value: ";
            displayResult(inputPtr);
        }
        else
            return 0;
        }
        
    delete []inputPtr;//clears memory
}

//Functions for Prob. 4
//Use to swap the digits
void changer(int &input, int &INPUT) {
    int swap;
        swap = input;
        input = INPUT;
        INPUT = swap;
}

//Encrypts the input
int *inputEncryption(int *inputEcrypting) {
    //for loop to +3 and %8 every inputted digit
    for (int count = 0; count != inputCap; ++count){
        *(inputEcrypting + count) += 3;
        *(inputEcrypting + count) %= 8;
    }
    changer(*(inputEcrypting), *(inputEcrypting + 1));
    changer(*(inputEcrypting + 2), *(inputEcrypting + 3));
    return inputEcrypting;}

//Undo the ecryption by working backwards
int *inputDecryption(int *inputDecrypting) {
    // undo the swapping made during encryption
    changer(*(inputDecrypting), *(inputDecrypting + 1));
    changer(*(inputDecrypting + 2), *(inputDecrypting + 3));

    for (int demod = 0; demod != inputCap; ++demod){
        if (*(inputDecrypting + demod) < 3){
            *(inputDecrypting + demod) = (*(inputDecrypting + demod) + 8);
        }
        else{
            *(inputDecrypting + demod) = *(inputDecrypting + demod);
        }
    //subtracts the 3 that was added during encryption
    *(inputDecrypting + demod) -= 3;}
return inputDecrypting;}

//Displays the encrypted or decrypted value
void displayResult(int *displayer, string input2string) {
    for (int count = 0; count != inputCap; ++count) {
        cout<<displayer[count]<<input2string;
    }
}

void problem5(){
    int INTE = 1;
    float floater = 1;
    double Doub = 1;
    short shorty = 1;
    long Lng = 1;
    int fInt, fLong, fFloat, fDoub, fShort;

    //Prompt
    cout<<"\nThis Program will calculate and display the factorial of each data"
        <<" type.\n";
    cout<<"Press enter to continue...";
    cin.ignore();
    cin.get();
    

        
   //Finds factorial for int
    for(int countInt = 1; countInt <= 300; countInt++){
            INTE = INTE *countInt;
            if(INTE<=0){
                fInt = countInt - 1;
                countInt = 300;}
    }

    //Finds factorial for float
    for(int countFloat = 1; countFloat <= 300; countFloat++){
        floater = floater * countFloat;
        
        if(floater <= 0){
            floater = countFloat - 1;    
            countFloat = 300;
        }

        else if(countFloat == 300){
            fFloat = countFloat;
        }
    }

      //Finds factorial for short
      for(int countShort = 1; countShort <= 300; countShort++){
            shorty = shorty * countShort;
            if(shorty <= 0){
                fShort = countShort - 1;
                countShort = 300;
            }
        }

       //Finds the factorial for long int
        for(int countLng = 1; countLng <= 300; countLng++){
            Lng = (Lng * countLng);
            if(Lng <= 0){
                fLong = (countLng - 1); 
                countLng = 300;
            }
        }

     //Finds factorial for double
     for(int countDoub = 1; countDoub <= 300; countDoub++){
        Doub = Doub * countDoub;
        if(Doub <= 0){
                Doub = countDoub - 1;
                countDoub = 300;
        }
        else if(countDoub == 300){
            fDoub = countDoub;}
    }

        //Displays all the factorials
        cout<<"Factorial Integer: "<<fInt<<endl;
        cout<<"Factorial Short Integer: "<<fShort<<endl;
        cout<<"Factorial Long Integer: "<<fLong<<endl;
        cout<<"Factorial Float: "<<fFloat<<endl;
        cout<<"Factorial Double: "<<fDoub<<endl;
}

void problem6(){
    //Displays the conversion
    cout<<"a)  Convert the following 2 numbers to binary, octal and hex.\n";
    cout<<"\nWhen Decimal = 1.125\n";
    cout<<"------------------------------\n";
    cout<<"Binary: 10.001\n";
    cout<< "Octal: 2.1\n";
    cout<< "Hexidecimal: 2.2\n";
    cout<<"\nWhen Decimal = 0.0664025\n";
    cout<<"------------------------------\n";
    cout<<"Binary: .0001\n";
    cout<<"Octal: .021\n";
    cout<<"Hexidecial: .11\n";
    cout<<"\nb)  Convert the float representations of the following into the ";
    cout<<"decimal number.\n";
    cout<<"------------------------------\n";
    cout<< "46666601 = 1181115905\n";
    cout<< "46666602 = 1181115906\n";
    cout<< "B9999AFE = 3113851646\n";
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
