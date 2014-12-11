/* 
 * File:   SavePrompt.h
 * Author: Kevin Vo
 *
 * Created on December 6, 2014, 11:31 AM
 */

#ifndef SAVEPROMPT_H
#define	SAVEPROMPT_H
using namespace std;

#include "Bonus.h"
#include "BonusBoss.h"
#include "BonusBoss.cpp"

//******************************************************************************
//Read and Write Example
//Write or read player's stats
//******************************************************************************

void ReadWrite(int endgameInput, Play *c){
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
        cout<<"Enter 3 for Bonus Features.\n";
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
                    myfile<<"Time: "<<foreInTime<<endl;

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

        cout<<"\nGoodbye!\n";
        }

    else cout<<"Cannot open file.";}

    //If person chooses to view the file
    else if(endgameInput == 2){
        string line;
        ifstream myfile ("stats.txt");
        if (myfile.is_open()){
            while(getline (myfile,line)){
                cout<<line<<'\n';}
             myfile.close();//Closes the file
            cout<<"\nGoodbye!\n";}
  else cout << "Cannot open file";}
    else if(endgameInput == 3){
        int endSelect;
        
        cout<<"\nWhich would you like to do?\n";
        cout<<"Enter 1 for Bonus Boss\n";
        cout<<"Enter 2 for Problem Solving\n";
        cout<<"Enter any other key to exit\n";
        cout<<"User Input: ";
        cin>>endSelect;
        if (endSelect == 1){
            bonusBoss();
        }
        else if (endSelect == 2){
            bonusAdd();
        }
        else{}
    }
    else{cout<<"\nBonne journée!\n";}
}



#endif	/* SAVEPROMPT_H */