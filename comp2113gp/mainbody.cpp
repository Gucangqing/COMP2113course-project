#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "function.h"
using namespace std;
//roll generator
int roll(int n1,int n2){
    srand(time(0));
    return rand() % (n2-n1+1) +n1; 
    
}
bool checkinitdist(int HP,int AP,int initpoints,bool &initdist){
    if(HP>=1&&HP<=5&&AP>=1&&AP<=5&&HP+AP==initpoints){
        return true;
    }
    else{
        return false;
    }
}
add_skills(vector<attack> skills,int AP){
    
}
//----story backgroud description
int main(){
    string name;
    cout<<"Please name your hero:";
    cin>>name;
    cout<<"Dear "<<name<<", Welcome to Magic Kingdom!"<<endl;
    cout<<"Magic Kingdom used to be a peaceful place..."<<endl;
    cout<<"Until one day, the dragon came."<<endl;
    cout<<"The dragon only loves two things: Shining Jewels and Beautiful Girls."<<endl;
    cout<<"After looting the kingdom's jewels, the dragon robbed th most precious property of the magic kingdom----the king's one and only daughte, princess Cici."<<endl;
    cout<<"The King has announced that whoever can beat the dragon and save the princess can inherit his place and merry Cici."<<endl;
    cout<<"You are a young man who are eager to become someone, so you decided to take this great path."<<endl;
    cout<<endl;
    cout<<"Do you want to start your journey?(yes/no)"<<endl;
    string input;
    cin>>input;
    if(input=="yes"){
        int HP,AP;
        //roll for initial points;
        int initpoints=roll(7,10);
        cout<<"You have "<<initpoints<<" initial points to distribute."<<endl;
        cout<<endl;
        cout<<"Do you want to read the distribution rule?(yes/no)"<<endl;
        cin>>input;
        //distribution rules
        if(input=="yes"){
            cout<<"For your initial points, you can distribute them to your HP(Health Points) or AP(Attack Points)"<<endl;
            cout<<"Initial points for HP and AP should be integers between 1 and 5."<<endl;
            cout<<"You must distribute all your initial points and cannot exceed."<<endl;
            cout<<"For each game, you only have one distribute chance for your initial points, be clever."<<endl;
        }
        // input distribution points
        cout<<endl;
        cout<<"Please input your distribution points for HP and AP (Two inegers seperated by space):"<<endl;
        cin>>HP>>AP;
        bool initdist=false;
        initdist=checkinitdist(HP,AP,initpoints,initdist);
        if(initdist==true){
            HP=HP*10;
            cout<<"Successful distribution!"<<endl;
            cout<<"Your HP is: "<<HP<<endl;
            cout<<"Your AP is: "<<AP<<endl;
        }
        while(initdist!=true){
            initdist=checkinitdist(HP,AP,initpoints,initdist);
            if (initdist!=true){
                cout<<"Unsuccessful distribution."<<endl;
                cout<<endl;
                cout<<"Rules:"<<endl;
                cout<<"For your initial points, you can distribute them to your HP(Health Points) or AP(Attack Points)"<<endl;
                cout<<"Initial points for HP and AP should be integers between 1 and 5."<<endl;
                cout<<"You must distribute all your initial points and cannot exceed."<<endl;
                cout<<"For each game, you only have one distribute chance for your initial points, be clever."<<endl;
                cout<<endl;
                cout<<"Please input your distribution points for HP and AP (Two inegers seperated by space):"<<endl;
                cin>>HP>>AP;
            }
            else{
                HP=HP*10;
                cout<<"Successful distribution!"<<endl;
                cout<<"Your HP is: "<<HP<<endl;
                cout<<"Your AP is: "<<AP<<endl;
            }
            
        }
        //roll for random gift
        int gift=0;
        if (initdist==true){
            cout<<endl;
            cout<<"The goddess is offering you a gift from the three gifts below:"<<endl;
            cout<<"Extra points for HP and AP."<<endl;
            cout<<"A sheild that can save you once."<<endl;
            cout<<"Extra life."<<endl;
            cout<<endl;
            cout<<"Do you want to roll for your gift?(yes/no)"<<endl;
            cin>>input;
            if(input=="yes"){
                int gift=roll(1,6);
                if (gift==1||gift==2||gift==3){
                    gift=1;
                    cout<<"Your gift is extra 2 points for HP and extra 1 point for AP."<<endl;
                    HP=HP+20;
                    AP=AP+1;
                    cout<<"Your HP is: "<<HP<<endl;
                    cout<<"Your AP is: "<<AP<<endl;
                }
                else if(gift==4||gift==5){
                    gift=2;
                    cout<<"You gift is one sheild for the boss's final attack."<<endl;
                }
                else if(gift==6){
                    gift=3;
                    cout<<"Your gift is an extra life."<<endl;
                }
            }
            if(input=="no"){
                gift=0;
                cout<<"You choose to start your journey without a gift, good luck."<<endl;
            }
        }
        
        //define all attack methods
        struct attackskills{
            string attack_name;
            int attack_hurt;
            int recover;
        };
        struct Critter{
            string attack_name;
            int attack_hurt;
        };
        //skills of Protagonist
        attackskills Protagonist[8]={
            {"Smite", 10, 0},
            {"Stone", 12, 0},
            {"Strike", 14, 0},
            {"Spear", 16, 0},
            {"Dagger", 18, 0},
            {"Knife", 20, 5},
            {"Sword", 22, 10},
            {"Shot", 30, 20}
        };
        //skills of Antagonist
        Critter Critter1[2]={
            {"Spark", 8},
            {"Flame", 12}
        };
        Critter Critter2[3]={
            {"Spark", 8},
            {"Flame", 12},
            {"Flare", 16}
        };
        Critter Dragon[4]={
            {"Spark", 8},
            {"Flame", 12},
            {"Flare", 16},
            {"Blast", 30}
        };
        cin >> AP;
        attackskills Attack[8];
        for (int i=0; i<AP; i++){
            Attack[i].attack_name = Protagonist[i].attack_name;
            Attack[i].attack_hurt = Protagonist[i].attack_hurt;
            Attack[i].recover = Protagonist[i].recover;
        }
        
    }
    else{
        cout<<"You lost the chance!"<<endl;
    }
    
   
}



