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
    cout << "Now you are facing the first little critter, its HP is "<<HP-5<<"."<< endl;
    cout << "Good luck!" << endl;
    cout << endl;
    cout << "Press Enter to start the battle."<<endl;
    
    cin.get();
    
    //Cristter1
    int Critter1HP = HP-5;
    int winner;
    int Life=life;
    while(true){
        int YourAtt=roll(0,AP-1);
        cout<<"You played the skill: "<<Attack[YourAtt].attack_name<<endl;
        Critter1HP-=Attack[YourAtt].attack_hurt;
        if(Critter1HP<=0){
            cout<<"Congratulations! You've beaten the first Critter!"<<endl;
            C1=true;
            break;
        }
        cout<<"The Critter's HP is: "<<Critter1HP<<endl;
	cout << "Press Enter to continue the battle." << endl;
        cin.ignore();
        int CritterAtt=roll(1,6);
        if(CritterAtt<=4){
            cout<<"The Critter played the skill: "<<Critter1[0].attack_name<<endl;
            HP-=Critter1[0].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
            cout << "Press Enter to continue the battle." << endl;
            cin.get();
        }
        else if(CritterAtt>4){
             cout<<"The Critter played the skill: "<<Critter1[1].attack_name<<endl;
           HP-=Critter1[1].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
            cout << "Press Enter to continue the battle." << endl;
            cin.get();
        } 
    }
    cout<<endl;
    cout<<"Press Enter to continue."<<endl;
    cin.get();
    //roll for distribute after C1
    cout<<endl;
    if(C1==true){
    cout<<"Young hero, you have past the first challenge. "<<endl;
    cout<<"Now the goddess is offering you extra points to help you grow stronger."<<endl;
    int c1point=roll(1,2),hp1,ap1;
    cout<<endl;
    cout<<"You extra point is: "<<c1point<<endl;
    cout<<"You can distribute them to your HP or AP.(0<=HP<=2,0<=AP<=2)"<<endl;
    cout<<"Please enter your distribution.(two integers seperated by a space)"<<endl;
    cin>>hp1>>ap1;
    while(true){
        if (checkextradist(hp1,ap1,c1point)){
            cout<<"Successful distribution for the extra points."<<endl;
            hp=hp+hp1;
            AP+=ap1;
            cout<<"Your new HP is: "<<hp*10<<endl;
            cout<<"Your new AP is: "<<AP<<endl;
            break;
        }
        else{
            cout<<"Unsuccessful distribution."<<endl;
            cout<<"Please enter your distribution.(two integers seperated by a space)"<<endl;
            cin>>hp1>>ap1;
        }
        
    }
    }
    cout<<endl;
    cout<<"Press Enter to continue."<<endl;
    cin.ignore();
    cin.get();
    //Cristter2
    HP=hp*10;
    for (int i=0; i<AP; i++){
        Attack[i].attack_name = Protagonist[i].attack_name;
        Attack[i].attack_hurt = Protagonist[i].attack_hurt;
        Attack[i].recover = Protagonist[i].recover;
    }
    int Critter2HP = HP+10;
    cout<<"You can keep your journey now."<<endl;
    cout<<"After passing the first Critter, you walked into a dark forest."<<endl;
    cout<<"Suddenly, the second Critter jumped out."<<endl;
    cout<<"You shall not pass! Shouted the Critter."<<endl;
    cout<<"The Critter's HP is "<<Critter2HP<<"."<<endl;
    cout<<"Good luck."<<endl;
    cout<<endl;
    cout<<"Press Enter to start the battle."<<endl;
    cin.ignore();
    while(true){
        int YourAtt=roll(0,AP-1);
        cout<<"You played the skill: "<<Attack[YourAtt].attack_name<<endl;
        Critter2HP-=Attack[YourAtt].attack_hurt;
        HP+=Attack[YourAtt].recover;
        if(Critter2HP<=0){
            cout<<"Congratulations! You've beaten the second Critter!"<<endl;
            C2=true;
            break; 
        }
        cout<<"The Critter's HP is: "<<Critter2HP<<endl;
	cout << "Press Enter to continue the battle." << endl;
        cin.get();
        int CritterAtt=roll(1,6);
        if(CritterAtt<=3){
            cout<<"The Critter played the skill: "<<Critter2[0].attack_name<<endl;
            HP-=Critter2[0].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                cout<<"Press Enter to continue."<<endl;
                cin.get();
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
	    cout << "Press Enter to continue the battle." << endl;
            cin.get();
        }
        else if(CritterAtt>=4&&CritterAtt<=5){
            cout<<"The Critter played the skill: "<<Critter2[1].attack_name<<endl;
            HP-=Critter2[1].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
	    cout << "Press Enter to continue the battle." << endl;
            cin.get();
        }
        else if(CritterAtt==6){
            cout<<"The Critter played the skill: "<<Critter2[2].attack_name<<endl;
            HP-=Critter2[2].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
            else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
	    cout << "Press Enter to continue the battle." << endl;
            cin.get();
        }
    }
    cout<<"Press Enter to continue.";
    cin.get();
    // roll points after C2
    if(C2==true){
    cout<<"Young hero, you have past the second challenge. "<<endl;
    cout<<"Now the goddess is offering you extra points to help you grow stronger."<<endl;
    int c2point=roll(1,2),hp2,ap2;
    cout<<endl;
    cout<<"You extra point is: "<<c2point<<endl;
    cout<<"You can distribute them to your HP or AP.(0<=HP<=2,0<=AP<=2)"<<endl;
    cout<<"Please enter your distribution.(two integers seperated by a space)"<<endl;
    cin>>hp2>>ap2;
    while(true){
        if (checkextradist(hp2,ap2,c2point)){
            cout<<"Successful distribution for the extra points."<<endl;
            hp=hp+hp2;
            AP+=ap2;
            cout<<"Your new HP is: "<<hp*10<<endl;
            cout<<"Your new AP is: "<<AP<<endl;
            break;
        }
        else{
            cout<<"Unsuccessful distribution."<<endl;
            cout<<"Please enter your distribution.(two integers seperated by a space)"<<endl;
            cin>>hp2>>ap2;
        }
        
    }
    }
    cout<<endl;
    cout<<"Press Enter to continue."<<endl;
    cin.ignore();
    cin.get();
    // Battle with dragon
    cout<<"Young hero, now you are fully prepared for all the possible challenges. What waiting in front of you is the vicious dragon."<<endl;
    cout<<"Only after beaten the dragon can you save Princess Cici and become what you've always dreamed to be."<<endl;
    cout<<"But all the heroes who tried to beat the dragon failed."<<endl;
    cout<<"Waiting in front of you is unknown."<<endl;
    HP=hp*10;
    for (int i=0; i<AP; i++){
        Attack[i].attack_name = Protagonist[i].attack_name;
        Attack[i].attack_hurt = Protagonist[i].attack_hurt;
        Attack[i].recover = Protagonist[i].recover;
    }
    int dragonlife=2,dragonHP=HP+20;
    cout<<endl;
    cout << "The Dragon's HP is "<< dragonHP<< endl;
    cout<<"If you are ready, press Enter to start the battle."<<endl;
    cout << endl;
    cin.ignore();
    while (true){
        int YourAtt=roll(0,AP-1);
        cout<<"You played the skill:"<<Attack[YourAtt].attack_name<<endl;
        dragonHP-=Attack[YourAtt].attack_hurt;
        HP+=Attack[YourAtt].recover;
        if(dragonHP<=0&&dragonlife==2){
            cout<<"The dragon fell down."<<endl;
            cin.get();
            cout<<"But is this the end?"<<endl;
            cin.get();
            cout<<"Suddenly, the dragon opened its giant red eyes."<<endl;
            cout<<"It recovered!"<<endl;
            cin.get();
            cout<<"Come on young man, you've beaten the dragon once and you can do it again!"<<endl;
            dragonHP=HP+20;
            dragonlife-=1;
        }
        else if(dragonHP<=0&&dragonlife==1){
            cout<<"Fianlly, the dragon fell down again."<<endl;
            cin.get();
            cout<<"You moved forward to check if it will recover again."<<endl;
            cout<<"Fortunately, this time it really died."<<endl;
            cout<<"Congratulations young hero, you've beaten the vicious dragon."<<endl;
            D=true;
            break; 
        }
        cout<<"The Dragon's HP is: "<<dragonHP<<endl;
        cout << "Press Enter to continue the battle." << endl;
        cin.ignore();
        int DragonAtt=roll(1,8);
	if(DragonAtt<=3){
            cout<<"The Dragon played the skill: "<<Dragon[0].attack_name<<endl;
            HP-=Dragon[0].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
	    else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
            cout << "Press Enter to continue the battle." << endl;
            cin.get();
	}
	if(DragonAtt>=4 && DragonAtt<=5){
            cout<<"The Dragon played the skill: "<<Dragon[1].attack_name<<endl;
            HP-=Dragon[1].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
	    else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
            cout << "Press Enter to continue the battle." << endl;
            cin.get();
	}
	if(DragonAtt>=6 && DragonAtt<=7){
            cout<<"The Dragon played the skill: "<<Dragon[2].attack_name<<endl;
            HP-=Dragon[2].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
	    else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
            cout << "Press Enter to continue the battle." << endl;
            cin.get();
	}
	if(DragonAtt==8){
            cout<<"The Dragon played the skill: "<<Dragon[3].attack_name<<endl;
            HP-=Dragon[3].attack_hurt;
            if(HP<=0&&Life==2){
                cout<<"You died."<<endl;
                cout<<"Fortunately, you have another chance. Now get up and keep fighting!"<<endl;
                Life=Life-1;
                HP=hp*10;
            }
	    else if(HP<=0&&Life==1){
                cout<<"Unfortunately, you've lost all your chance. Do you want to replay this round?(yes/no)"<<endl;
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
            cout << "Press Enter to continue the battle." << endl;
            cin.get();
	}

    }
}



