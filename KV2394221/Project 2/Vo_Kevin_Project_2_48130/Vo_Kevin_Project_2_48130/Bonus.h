/* 
 * File:   Bonus.h
 * Author: Kevin Vo
 *
 * Created on December 6, 2014, 4:50 PM
 */

#ifndef BONUS_H
#define	BONUS_H
using namespace std;

//******************************************************************************
//One Example of Classes
//Gets protected members from Time to convert it and display it
//******************************************************************************

class Bonus{
    private:
        int cAnswer1;
        int cCorrect1;
        int num1;
        int num2;

    public:
        Bonus(int, int);
        void setAnswer1(int);
        void setCorrect1(int);

        int getAnswer1();
        int getCorrect1();

        void displayResult();

};


Bonus::Bonus(int n1, int n2){
    num1 = 0;
    num2 = 0;
};

void Bonus::setAnswer1(int answ1){
    cAnswer1 = answ1;
};

void Bonus::setCorrect1(int cor1){
    cCorrect1 = cor1;
};

int Bonus::getAnswer1(){
    return cAnswer1;
};

int Bonus::getCorrect1(){
    return cCorrect1;
};


void Bonus::displayResult(){
        unsigned seed = time(0), Number1, Number2; 
//Random # gen. to provide addition problems
        srand(seed);
   
        num2 = rand()%999;
        num1 = rand()%999;

   //Use of if statement to determine right & wrong answers
    if (cCorrect1 == cAnswer1){
        if(num1 == num2){
            //Prize picture reward of dolphin after receiving correct answer
                cout<<"Congratulations, you have made it to dolphin status!\n";
                cout<<endl;
                cout<<"__________________ ##"<<endl;
                cout<<"_________________###*"<<endl;
                cout<<"______________.*#####"<<endl;
                cout<<"_____________*######"<<endl;
                cout<<"___________*#######"<<endl;
                cout<<"__________*########."<<endl;
                cout<<"_________*#########."<<endl;
                cout<<"_________*#######*##*"<<endl;
                cout<<"________*#########*###"<<endl;
                cout<<"_______*##########*__*##"<<endl;
                cout<<"_____*###########_____*"<<endl;
                cout<<"____############"<<endl;
                cout<<"___*##*#########"<<endl;
                cout<<"___*_____########"<<endl;
                cout<<"__________#######"<<endl;
                cout<<"___________*######"<<endl;
                cout<<"____________*#####*"<<endl;
                cout<<"______________*####*"<<endl;
                cout<<"________________*####"<<endl;
                cout<<"__________________*##*"<<endl;
                cout<<"____________________*##"<<endl;
                cout<<"_____________________*##."<<endl;
                cout<<"____________________.#####."<<endl;
                cout<<"_________________.##########"<<endl;
                cout<<"________________.####*__*####"<<endl;
                cout<<"(Photo provided by fsymbols.com)"<<endl;
            }
            else{
                cout<<"Congratulations, you have made it to sea horse status!\n";
                cout<<endl;
                cout<<"________$$$$.."<<endl;
                cout<<"______$$$$$$$$$"<<endl;
                cout<<"______$$$$$$$_$"<<endl;
                cout<<"_____$$$$$$$$$$"<<endl;
                cout<<"______$$$$$$$$$$"<<endl;
                cout<<"_____$$$$$$_$$$$$"<<endl;
                cout<<"____$$$$$$$_____$$$"<<endl;
                cout<<"____$$$$$$$$_____$"<<endl;
                cout<<"____$$$$$$$$$$"<<endl;
                cout<<"_____$$$$$$$$$$"<<endl;
                cout<<"_____$$$$$$$$$$$"<<endl;
                cout<<"______$$$$$$$$$$$"<<endl;
                cout<<"_$$$$___$$$$$$$$$"<<endl;
                cout<<"__$$$$$$$$$$$$$$$"<<endl;
                cout<<"_$$$$$$$$$$$$$$$"<<endl;
                cout<<"__$$$$$$$$$$$$$"<<endl;
                cout<<"$$$$$$$$$$$$$"<<endl;
                cout<<"__$__$$$$$$"<<endl;
                cout<<"____$$$$$$"<<endl;
                cout<<"____$$$$$"<<endl;
                cout<<"___$$$$$$_____$"<<endl;
                cout<<"___$$$$$$___$$_$$"<<endl;
                cout<<"____$$$$$___$__$$"<<endl;
                cout<<"____$$$$$______$$"<<endl;
                cout<<"_____$$$$$____$$$"<<endl;
                cout<<"_______$$$$$$$$$"<<endl;
                cout<<"__________$$$$"<<endl<<endl;      
                cout<<"(Photo provided by fsymbols.com)"<<endl;
                cout<<endl;
            }
          
    }
    else
    {
        cout<<"Sorry you did not get the correct answer.\n";
    }  
};

void bonusAdd(){
            //Primitive data types for case 1 
        int correct, Answer;
        unsigned seed = time(0), Number1, Number2; 
        
        //prompt of the mini program within case 1
cout<<"This program will be testing your basic math skills. You'll be able\n"
    <<"to pick between addition or multiplication. Depending on how many "
    <<"problems you\ndo, will did you a picture award.\nWarning: "
    <<"If you enter in an incorrect answer you will be forced to restart."
    <<endl<<endl;

//Random # gen. to provide addition problems
                srand(seed);
   
                       Number1 = rand()%999;
                       Number2 = rand()%999;
   
                correct= Number1 + Number2;
                cout<<"Please enter the correct answer to the problem below.\n";         
                cout<<"  "<<Number1<<"\t Answer: "<<correct<<endl;
                cout<<"+ "<<Number2<<endl;
                cout<<"-------"<<endl;
                cin>>Answer;//Input variable from user

                Bonus one(Number1, Number2);
                one.setAnswer1(Answer);
                one.setCorrect1(correct);
                one.displayResult();
                
};
#endif	/* BONUS_H */