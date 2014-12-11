/* 
 * File:   Vo_Kevin_Project_2_48130.cpp
 * Author: Kevin Vo
 * Student ID: 2394221
 * Created on December 6, 2014, 6:51 PM
 * Line Count: 1148 lines (without the checklist)
 * Project 2 Checklist:
 * 1) Dynamic Array -> int sortStat[arrSize]; in Sort.h and char userName[] in
 *    PlayerInfo.h
 * 2) Read & Write -> Lines 46 - 103 in SavePrompt.h
 * 3) Classes -> Bonus.h, BonusBoss.h, Timing.h, Sort.h
 * 4) Inheritance - > class ForeignTime:public Time in Timing.h
 * 5) Polymorphism -> Line 40 and down in BonusBoss.h virtual void attack(){}
 * 6) Template -> template <class T>class SortableVector in Sort.h utilizes a 
 *    class
 *
 * Project 1 Checklist: 
 * 1) Pointers -> *playerDamage, *inputDecrypting
 * 2) Functions with Struct -> int minion(char action, struct Play *c)
 *    in PlayerInfo.h
 * 3) Pointers with Arrays -> namePtr = c->userName; in main.cpp
 * 4) Array of Structures -> char userName[10]; (INTERNALLY) in PlayerInfo.h
 *	                         namePtr = c->userName; (EXTERNALLY) in main.cpp
 * 5) Pointer Notation -> *(namePtr+i) in main.cpp
 * 6) Pointer with Structures-> int *playerDamage; (INTERNAL)
 *	  PlayerInfo.h shows an example with pointer with structures EXTERNALLY.
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

#include "Timing.h"
#include "Sort.h"
#include "PlayerInfo.h"
#include "BonusBoss.h"
#include "Bonus.h"
#include "SavePrompt.h"


int main(int argc, char** argv){
    //Allocates memory so that the members of the structure can be used
    Play *c = new Play;
    int dmg = 8, endgameInput;
    c->playerDamage = &dmg;
    c->playerHealth = 100;
    char action;//Input for the player to play the game

    //Prompts the player about the game
    cout<<"Warriors' Extravaganza is an Roleplaying Game that soley depends on "
        <<"repetition until\nyou understand the game.\nTo play, each turn you "
        <<"are given a chance to fight a boss or one of its minions. Each "
        <<"minion fight will give you a boost damage\nand health points.\n"
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

    //Writes player's status to a .txt or reads previous stats
    //and displays the endgame options
    ReadWrite(endgameInput, c);

   delete namePtr;//cleans up

return 0;}