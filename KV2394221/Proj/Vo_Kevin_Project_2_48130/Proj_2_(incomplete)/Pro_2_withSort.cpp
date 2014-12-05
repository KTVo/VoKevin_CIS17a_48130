/* 
 * File:   Project_1.cpp
 * Author: Kevin Vo
 * Course: CSC-17A (48130)
 * Created on October 12, 2014, 2:11 PM
 */
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

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

struct Play{
    int *playerDamage; 
    int playerHealth;
    char userName[];
};
//Function Prototypes
int combatBoss(Play *);//Initiates boss battle

//Decryptin Prompt code for to get to boss level
void decryptPrompt();
void changer(int &, int &);
void displayResult(int*, string ="");
int *inputDecryption(int *);

//Congratulates for getting to boss level and requests code
int boss();

//Starts the minion battles for leveling up
int minion(char, Play *);

//Displays instruction, story progression, and status text
void endBattle();
void duringBattle();
void displayStatPlayer();
void congratDisplay();

//CONSTANT global variable for in-game decrpytion
const int inputCap = 4;

int main(int argc, char** argv){
    //Allocates memory so that the members of the structure can be used
    Play *c = new Play;
    int dmg = 8, endgameInput;
    c->playerDamage = &dmg;
    c->playerHealth = 100;
    char action;//Input for the player to play the game

    //Prompts the player about the game
    cout<<"Warriors' Extravaganza is an Roleplaying Game that soley depends on "
        <<"repetition until you understand the game.\nTo play, each turn you "
        <<"are given a chance to fight a boss or one of its minions. Each "
        <<"minion fight will give you a boost damage and health points.\n"
        <<"Hit enter to continue...";
    cin.ignore();
    //uses structure member "userName" to store name
    cout<<"Enter the name of your character: ";
    cin.get(c->userName, 10);
    char *namePtr;

    //Assigns a pointer to an element
    namePtr = c->userName;
   

    cout<<"\nHello.\n";
    cout<<"Let's begin!\n";
    //Uses member "userName" and *playerDamage to display string
    cout<<"Name: ";
    
    //Pointer Notation example
    for(int i=0; i < 6; i++){
        cout<<*(namePtr+i);
    }
    cout<<endl;
    cout<<"Here are your current stats:\n------------------------------\n"
        <<"Health: "<<c->playerHealth<<endl<<"Current Damage: "<<
            *c->playerDamage<<endl<<endl<<"Now hit enter to fight...";
    cin.ignore();
    cin.get();

    //Calls for minion battle
    minion(action, c);

    //Calls for decryption to boss
    boss();

    //Calls for boss battle
    combatBoss(c);

    //Displays congrats message
    congratDisplay();

    //Asks to write/read a .txt or end the game
    cout<<"Player Input: ";
    cin>>endgameInput;
    
    if(endgameInput == 1){
        int timeChoice;//stores
        int stdHr;//stores
        int stdMin;//stores
        int stdSec;//stores
        int foreInTime;

        cout<<"\nChoose the time format.\n";
        cout<<"*****************************\n";
        cout<<"Enter 1 for 24-HR Format.\n";
        cout<<"Enter 2 for Standard Format.\n";
        cout<<"User Input: ";
        cin>>timeChoice;

        while(timeChoice == 0 || timeChoice > 2){
            cout<<"Your input was invalid.\n";
            cout<<"Please select the format you wish to use.\n";
            cout<<"\nChoose the time format.\n";
            cout<<"*****************************\n";
            cout<<"Enter 1 for 24-HR Format.\n";
            cout<<"Enter 2 for Standard Format.\n";
            cout<<"User Input: ";
            cin>>timeChoice;
        }
        
        ofstream myfile ("stats.txt");
        if (myfile.is_open()){
        myfile<<"\n\n---File Content---\n";
            if (timeChoice == 2){
                cout<<"Enter the following for the standard time...\n";
                cout<<"Hour: ";
                cin>>stdHr;
                cout<<"Minute: ";
                cin>>stdMin;
                cout<<"Second: ";
                cin>>stdSec;
                myfile<<"Time: "<<stdHr<<":"<<stdMin<<":"<<stdSec<<endl;
            }

            else if(timeChoice == 1){
        

                cout<<"Enter Time in 24-hr format: ";
                cin>>foreInTime;

                try{
                    if(foreInTime > 2359 || foreInTime < 0){
                    throw 1756;
                    }

                    TimeClock time(foreInTime, 0);
                    time.display();
                    cout<<endl;

                }
                catch(int x){
                    cout<<endl<<"Error: "<<x<<endl;
                    cout<<"Input Validation: The class shouldn't accept hours"
                        <<" greater than 2359 or less than 0.\n";
                }
            }

       



        myfile<<"Name: "<<c->userName<<endl;
        myfile<<"Health: "<<c->playerHealth<<endl;
        myfile<<"Damage: "<<*c->playerDamage<<endl;
        myfile.close();



        int const arrSize = 3;//holds the amount of elements for the array
        int sortStat[arrSize];//sorts the elements so that it can be sorted

        sortStat[0] = 1;
        sortStat[1] = 2;
        sortStat[2] = 3;

        SortableVector<int> vect(arrSize);
    
        //Loops and assign inputs
        for(int count = 0; count < arrSize; count++){
            cout<<"Digit #"<<count + 1<<": ";

            vect[count] = sortStat[count];
        }

        //Sorts and then displays the result
        vect.sorter();
        cout<<"\n\tResult\n---------------------------\n";
        for(int count = 0; count < arrSize; count++){
        cout<<"\t"<<vect.getValue(count)<<endl;
        }






        cout<<"\nGoodbye!\n";
        }

        else cout<<"Cannot open file.";}
    else if(endgameInput == 2){
        string line;
        ifstream myfile ("stats.txt");
        if (myfile.is_open()){
            while(getline (myfile,line)){
                cout<<line<<'\n';}
             myfile.close();
            cout<<"\nGoodbye!\n";}//Closes the file
  else cout << "Cannot open file";}
    else{cout<<"\nBonne journée!\n";}

        delete[] namePtr;//cleans up
    return 0;}

//Function for duing gameplay
int minion(char action, struct Play *c){
    c-> playerHealth;
    int minionHealth = 800;
    c-> playerDamage;
    int overDose = 10;

    //Prompts player of the battle
    duringBattle();

    //Prompts user to push any other key to fight the boss right away.
    cout<<"\nIf you feel like battling the boss now. Enter in any other key.\n";

    //Loops until the player either dies or decides to fight the boss
    do{
        //Requests user to select the options during gameplay
        cout<<"Player Input: ";
        cin>>action;

        //If players enter 's' they will get a boost in health and dmg
        if(action == 's' || action == 'S'){
            overDose--;
            c->playerHealth = c->playerHealth + 90;
            *c->playerDamage += 90;
            minionHealth = minionHealth - *c->playerDamage;
            c->playerHealth = c->playerHealth - 25; 
            cout<<"\nYour Health: "<<c->playerHealth<<endl;
            cout<<"Your health and damage is boosted by 90 points.\n";
            cout<<overDose<<" more uses of health before overdose.\n"; 

            //If player drinks to many potions they will OD and die
            if(overDose <=0){//If player drinks all pots they will OD and die 
                cout<<"You have died by an overdose.\n";
                cout<<"Note: You don't get to store your stats to a .txt\n"
                    <<"until you have reach the boss.\n";
                exit (EXIT_FAILURE);}//Exits out the game.
            }
            else if(action == 'a' || 'A'){
                *c->playerDamage += 80;
                minionHealth = minionHealth - *c->playerDamage;
                c->playerHealth = c->playerHealth - 25;

                //Warns player of his/her low health
                if(c->playerHealth <= (c->playerHealth/2)){
                    cout<<"***WARNING: You have reached half health or less.\n"
                        <<"But heal too much and you will die.\n"
                        <<"Enter 's' or you will die!\n";
                }

                //Displays players health and current damage and minion health
                cout<<"Your Health: "<<c->playerHealth<<endl;
                cout<<"Your Damage: "<<*c->playerDamage<<" points\n";
                cout<<"\n\t Minion's Health: "<<minionHealth<<endl;

                if (c->playerHealth <= 0){//Ends game when user dies
                    cout<<"Sorry you have die. GAMEOVER!"<<endl;
                    exit (EXIT_FAILURE);
                }

                //Conditions if a minion is killed  
                if(minionHealth <= 0){
                    c->playerHealth = c->playerHealth + 500;
                
                    //Displays the options to fight boss/minions    
                    endBattle();

                    //If player input w it calls for function boss
                    //Occasional deduction for bonuses
                    if(action == 's' || action == 'S'){ 
                        overDose--;
                        c->playerHealth = c->playerHealth = 50;
                        cout<<"Your health is boosted by 50 points.\n";
                        cout<<overDose<<" more uses of health before overdose.";
                        cout<<endl;

                        //if death by OD = gameover in deduction moment of game
                        if(overDose <=0){
                                cout<<"You have died by an overdose.\n";
                        exit (EXIT_FAILURE);}
                    }

                else if (action == 'q' || action == 'Q'){//initi. minion rematch
                    //minion gets stronger
                    minionHealth = 1500;

                    duringBattle();//Displays prompt during battle

                    //Warns player about their quicker lost in health
                    if(c->playerHealth <= (c->playerHealth/2)){
                        cout<<"***WARNING: Your health is considerably low"
                            <<".\nEnter 's' or you will die!\n";
                    }
                    }
                    minionHealth = 1500;
                }
            }
    }while(action == 'a' || action == 'A'|| action == 's' || action == 'S' || 
        action == 'q' || action =='Q');
    
return 0;}

//Displays during battle instructions
void duringBattle(){
    cout<<"Here's another minion! Fight these to earn enough damage & HP "
        <<"to withstand the actual boss.\n\nType 'a' attack or 's' to heal.\n";
}

//Displays end battle options
void endBattle(){
    cout<<"\nCongratulations! You have gotten your kill! Now "
        <<"enter 'q' to continue more monsters and get stronger "
        <<"or enter 'w' to\ngo straight to the boss.\n\n";
}

//Congratulates and ask for decryption code
int boss(){
    int digitInput, selectInput;
    //pointer with array example
    int *inputPtr = new int [inputCap];
    bool btw07;
    char input;

    cout<<"\n\n***Congratulations you have reached the final boss but there's a"
        <<" lock on the door.\nOh wait! You have picked up a decoder from the "
        <<"last minion you have killed.\n";
    cout<<"\nHmmm... there seems to be a combination the wall of 4 digits.";
    cout<<"\nThe combination on the wall is: 1234\n\n";
    cout<<"Please pull out the decoder by entering 'a'.\n";
    cin.ignore();
    cin.get();

    decryptPrompt();//Displays and asks for combination on wall

    delete []inputPtr;//clears memory
return 0;}

//Use to swap the digits
void changer(int &input, int &INPUT) {
    int swap;
        swap = input;
        input = INPUT;
        INPUT = swap;
}

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

//Asks for found code
void decryptPrompt(){
    int digitInput, selectInput;
    int *inputPtr = new int [inputCap];
    bool btw07;

    cout<<"Enter in the code.\n";
    cout<<"Input Data: ";
    cin>>digitInput;
        cout<<"\nOh no there seems to be an error with the decoder!\n";
        cout<<"Now ";

    do{
        cout<<"\nPlease re-enter '1234' (without the ' ').\n";
        cout<<"Player Input: ";
        cin>>digitInput;
    }while(digitInput != 1234);

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
            inputPtr = inputDecryption(inputPtr);
            cout<<"\n.......... ....... ........... Decrypted Code: ";
            displayResult(inputPtr);
        }

    delete []inputPtr;//clears memory

    //Asks to input decrypted code
    int decrptInput;
    cout<<"\n\nNow please enter the Decrypted Code (It is 7610): ";
    cin>>decrptInput;

    //code input validation
    if (decrptInput != 7610){
        cout<<"\nYou have inputted the wrong code...\n";
        cout<<"Please try again... (the code is 7610)\n";
        cout<<"\nUser Input: ";
        cin>>decrptInput;
    }
        cout<<"\nThe doors are opening. Please hit enter to continue...";
        cin.ignore();
        cin.get();
}

//Calculates and prompts the boss battle
int combatBoss(struct Play *c){
    int bossHealth = 1000000, bossDamage = 100;
    char playerInput;
    c-> playerHealth;
    c-> playerDamage;

    //Prompts user about boss
    cout<<"\nThe boss is now here. He does more damage & has way more health "
        <<"than your previous enemies.\n"
        <<"Attack him by hitting 'a'.\nPlayer Input: ";
    cin>>playerInput;    

    //Loops while in boss fight
    do{
        //Calculations for boss' and player's status
        bossHealth = bossHealth - c-> playerHealth;
        c-> playerHealth = (c-> playerHealth*3);
        bossDamage = (bossDamage * 10);
        c-> playerHealth = c-> playerHealth - bossDamage;

        cout<<"\n---Boss' Status---:\n";
        cout<<"\tBoss' Health: "<<bossHealth<<endl;
        cout<<"\tBoss' Damage: "<<bossDamage<<endl;
        cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<"---Your Status---:\n";
        cout<<"\tYour Health: "<<c-> playerHealth<<endl;
        cout<<"\tYour Current Damage: "<<*c->playerDamage<<endl;
        cout<<"Input 'a' to ATTACK and 's' to Heal-ATTACK\n";
        cout<<"Player Input: ";
        cin>>playerInput;

        if(playerInput == 's'|| playerInput == 'S'){
            bossHealth = bossHealth - *c->playerDamage;
            *c->playerDamage = (*c->playerDamage*5);
            c-> playerHealth = c-> playerHealth + 190;
            //Multiplies bossDamage for every round
            bossDamage = (bossDamage * 2);
        }

        //Congrats the player for killing the boss
        if(bossHealth <=0){
            cout<<"\n***Congratulations you have defeated the boss!***.\n";
            return 0;}

        //Shows gameover screen if player was killed by the boss
        if(c-> playerHealth <=0){
            cout<<"\nYou were killed by the boss.\n";
            cout<<"\nGAMEOVER.\n";
            cout<<"Note: Kill more minions next time.\n";
            return 0;}

    }while(playerInput=='a'||playerInput=='A'||
        playerInput=='s'||playerInput=='S');
return 0;}

//Displays congratulations for beating the boss
void congratDisplay(){
        cout<<"**************************************************************";
        cout<<"************\n*";
        cout<<"Congratulations for getting to the boss win or not you are still"
            <<" a hero!*\n";
        cout<<"**************************************************************";
        cout<<"************\n";

        cout<<"\nNow what would you like to do?\n";
        cout<<"---------------------------------------\n";
        cout<<"Enter 1 to write your status to a text file.\n";
        cout<<"Enter 2 to view your last status.\n";
        cout<<"Enter 0 to exit game.\n";
}