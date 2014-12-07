/* 
 * File:   BonusBoss.h
 * Author: Kevin Vo
 *
 * Created on December 6, 2014, 4:24 PM
 */

#ifndef BONUSBOSS_H
#define	BONUSBOSS_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//******************************************************************************
//Polymorphic and Virtual Function Example
//Diplays different outputs from same function
//******************************************************************************


//Contains the Health status for Human Player
class BonusPlayer{
    private:
        int bonusPlayerHP;//Stores Player's health
    
    public:
        BonusPlayer(){ bonusPlayerHP = 100;}//Sets Player's health to 100
        void setBonusPlayerHP(int damage){ bonusPlayerHP = damage;};
        int getBonusPlayerHP()const{return bonusPlayerHP;};
};



class BonusEnemy{
    protected:
        int enemyHealth;
    public:
        BonusEnemy(){enemyHealth = 100;}
        void setEnemyHealth(){enemyHealth -= 20;};
        virtual void attack(){}

        int getEnemyHealth() const{return enemyHealth;}
        
};



class FormA : public BonusEnemy{
    public:
        void attack(){
            cout<<"\n****************************************\n";
            cout<<"\nThe Bonus Boss is now FIRE mode.\n";}
        
};

class FormB : public BonusEnemy{
    public:
        void attack(){
            cout<<"\n****************************************\n";
            cout<<"\nThe Bonus Boss is now WATER mode.\n"; }
        
};


void bonusBoss(){
    FormA f;
    FormB w;

    BonusEnemy *FormFire = &f;
    BonusEnemy *FormWater = &w;

    BonusEnemy z;
    BonusPlayer p;

    int userInput;
    int tempHealth = 100;
    int rNum;//Holds the value of the random number for enemy's changing form
    
    cout<<"Instructions: The Bonus Boss can switch form from a FIRE type to "
        <<"Water type.\nYou'll have to choose which attack is more effective "
        <<"in order to do damage. If the wrong attack move is choosen no damage"
        <<"to the enemy will be done.\n";


    do {
        //Randomizes rNum so to switch modes for the enemy
        for(int count = 0; count < 200; count++){
            //Gets the system's time.
            unsigned seed = time (0);

            //Seed the random number generator.
            srand(seed);

            rNum = rand()%100;
        }

        //If rNum is less than or equal to 49 the enemy is FIRE mode
        if (rNum <= 49){
            FormFire->attack();
            cout<<"\nEnemy Health: "<<z.getEnemyHealth();
            cout<<"\nPlayer Health: "<<p.getBonusPlayerHP()<<endl;
            cout<<endl;

            cout<<"\nEnter: 1 for WATER attack.\n";
            cout<<"       2 for LIGHTNING attack.\n";
            cout<<"Player Input: ";
            cin>>userInput;


            if (rNum <= 49 && userInput == 1){
                cout<<"\nEnemy Health : "<<z.getEnemyHealth();
                cout<<"\nPlayer Health: "<<p.getBonusPlayerHP()<<endl;
                z.setEnemyHealth();//Deducts enemy's health
                tempHealth -= 5;
                p.setBonusPlayerHP(tempHealth);//Deducts player's health
                
            }
            else if(rNum <=49 && userInput == 2){
                cout<<"\n!!! YOU DID NO DAMAGE !!!";
                cout<<"\nEnemy Health : "<<z.getEnemyHealth();
                cout<<"\nPlayer Health: "<<p.getBonusPlayerHP()<<endl;
                tempHealth -= 5;
                p.setBonusPlayerHP(tempHealth);//Deducts player's health
            }
        }

        else if (rNum > 49){
            FormWater->attack();
            cout<<"\nEnemy Health : "<<z.getEnemyHealth();
            cout<<"\nPlayer Health: "<<p.getBonusPlayerHP()<<endl;
            cout<<endl;

            cout<<"\nEnter: 1 for WATER attack.\n";
            cout<<"       2 for LIGHTNING attack.\n";
            cout<<"Player Input: ";
            cin>>userInput;


            if (rNum > 49 && userInput == 2){
                cout<<"\nEnemy Health : "<<z.getEnemyHealth();
                cout<<"\nPlayer Health: "<<p.getBonusPlayerHP()<<endl;
                z.setEnemyHealth();//Deducts enemy's health
                tempHealth -= 5;

                p.setBonusPlayerHP(tempHealth);//Deducts player's health
            }

            else if (rNum > 49 && userInput == 1){
                cout<<"\n!!! YOU DID NO DAMAGE !!!";
                cout<<"\nEnemy Health : "<<z.getEnemyHealth();
                cout<<"\nPlayer Health: "<<p.getBonusPlayerHP()<<endl;

                tempHealth -= 5;
                p.setBonusPlayerHP(tempHealth);
            }

        }

    } while (p.getBonusPlayerHP() > 0 && z.getEnemyHealth() > 0);



    if(z.getEnemyHealth() < p.getBonusPlayerHP()){
        cout<<"\nYou have beat the Bonus Boss.\n";
    }
    if(z.getEnemyHealth() > p.getBonusPlayerHP()){
        cout<<"\nYou've lost against the Bonus Boss.\n";
    }
        
    delete FormFire;
    delete FormWater;
}
#endif	/* BONUSBOSS_H */

