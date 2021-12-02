#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "function.h"
#include <limits>
using namespace std;

//struct of the Protagonist's and Antagonist's skills
struct attackskills{
    string attack_name;
    int attack_hurt;
    int recover;
};
struct Critter{
    string attack_name;
    int attack_hurt;
};

//----story backgroud description
int main(){
    string name;
    int hp,HP, AP, Sheild=0, life=1;
    bool C1=false,C2=false,D=false;
    attackskills Attack[8];
    
    //skills of Protagonist
    attackskills Protagonist[9]={
        {"Smite", 10, 0},
        {"Stone", 12, 0},
        {"Strike", 14, 0},
        {"Spear", 16, 0},
        {"Dagger", 18, 0},
        {"Knife", 20, 5},
        {"Sword", 22, 10},
        {"Shot", 30, 20},
        {"Bomb", 40, 30}
    };
    //skills of Antagonists
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
    cout<<"Please name your hero: ";
    cin>>name;
    cout<<"Dear "<<name<<", Welcome to Magic Kingdom!"<<endl;
    cout<<"Magic Kingdom used to be a peaceful place..."<<endl;
    cout<<"Until one day, the dragon came."<<endl;
    cout<<"The dragon only loves two things: Shining Jewels and Beautiful Girls."<<endl;
    cout<<"After looting the kingdom's jewels, the dragon robbed th most precious property of the magic kingdom----the king's one and only daughter, princess Cici."<<endl;
    cout<<"The King has announced that whoever can beat the dragon and save the princess can inherit his place and merry Cici."<<endl;
    cout<<"You are a young man who are eager to become someone, so you decided to take this great path."<<endl;
    cout<<endl;
    cout<<"Do you want to start your journey? (yes/no)"<<endl;
    string input;
    cin>>input;
    if(input=="yes"){
        //roll for initial points;
        int initpoints=roll(7,10);
        cout<<"You have "<<initpoints<<" initial points to distribute."<<endl;
        cout<<endl;
        cout<<"Do you want to read the distribution rule? (yes/no)"<<endl;
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
        cin>>hp>>AP;
        bool initdist=false;
        initdist=checkinitdist(hp,AP,initpoints,initdist);
        if(initdist==true){
            HP=hp*10;
            cout<<"Successful distribution!"<<endl;
            cout<<"Your HP is: "<<HP<<endl;
            cout<<"Your AP is: "<<AP<<endl;
        }
        while(initdist!=true){
            initdist=checkinitdist(hp,AP,initpoints,initdist);
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
                HP=hp*10;
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
                    hp=hp+2;
                    HP=hp*10;
                    AP=AP+1;
                    cout<<"Your HP is: "<<HP<<endl;
                    cout<<"Your AP is: "<<AP<<endl;
                }
                else if(gift==4||gift==5){
                    gift=2;
		            Sheild=1;
                    cout<<"You gift is one sheild for the boss's final attack."<<endl;
                }
                else if(gift==6){
                    gift=3;
                    cout<<"Your gift is an extra life."<<endl;
                    life=2;
		}
            }
            if(input=="no"){
                gift=0;
                cout<<"You choose to start your journey without a gift, good luck."<<endl;
            }
        }
	    cout<<endl;
    }
    else{
        cout<<"You lost the chance!"<<endl;
        exit(0);
    }
        //Add attack skills for the protagonist
        for (int i=0; i<AP; i++){
            Attack[i].attack_name = Protagonist[i].attack_name;
            Attack[i].attack_hurt = Protagonist[i].attack_hurt;
            Attack[i].recover = Protagonist[i].recover;
        }
    cout<<"Press Enter to continue."<<endl;
    
    cin.ignore();
    cin.get();
    
   //Start the fight with the Critters
    cout << endl;
    cout << "On the way to the Dragon's castle, there are some little critters." << endl;
    cout << "They are the minions of the Dragon, preventing the challengers from getting to the castle." << endl;
    cout << "You have to beat all of them to get to the castle and fight with the Dragon." << endl;
    cout << "The way you play your card is by a random roll." << endl;
    cout << endl;
    cout << "Now you are facing the first little critter, its HP is 30." << endl;
    cout << "Good luck!" << endl;
    cout << endl;
    cout << "Press Enter to continue."<<endl;
    
    cin.get();
    
    //Cristter1
    int Critter1HP = 180;
    int winner;
    int Life=life;
    while(true){
        int YourAtt=roll(0,AP-1);
        cout<<"You played the skill:"<<Attack[YourAtt].attack_name<<endl;
        Critter1HP-=Attack[YourAtt].attack_hurt;
        if(Critter1HP<=0){
            cout<<"Congratulations! You've beaten the first Critter!";
            C1=true;
            break;
        }
        cout<<"The Critter's HP is: "<<Critter1HP<<endl;
        int CritterAtt=roll(1,6);
        if(CritterAtt<=4){
            cout<<"The Critter played the skill: "<<Critter1[0].attack_name<<endl;
            HP-=Critter1[0].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!";
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)";
                cout<<endl;
                cin>>input;
                if(input=="yes"){
                    HP=hp*10;
                    Life=life;
                }
               else{
                    break;
                }
            }
            cout<<"Your HP is: "<<HP<<endl;
        }
        else if(CritterAtt>4){
             cout<<"The Critter played the skill: "<<Critter1[1].attack_name<<endl;
           HP-=Critter1[1].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!";
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)";
                cin>>input;
                if(input=="yes"){
                    HP=hp*10;
                    Life=life;
                }
                else{
                    break;
                }
            } 
            cout<<"Your HP is: "<<HP<<endl;
        } 
    }
}



