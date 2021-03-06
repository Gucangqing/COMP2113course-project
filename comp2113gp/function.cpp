#include <iostream>
#include <string>
#include <random>
#include "function.h"
using namespace std;

//random number generator to roll skill points
int roll(int n1, int n2){
  srand(time(0));
  return rand() % (n2-n1+1) + n1;
}

//function to check if the distributed skill points meet the requirements
bool checkinitdist(int HP, int AP, int initpoints, bool &initdist){
  if (HP >= 1 && HP <= 5 && AP >= 1 && AP <= 5&& (HP+AP)==initpoints) return true;
  else return false;
}
//function to check if the extra points distribution works
bool checkextradist(int HP,int AP, int extrapoints){
    if(HP>=0&&HP<=2&&AP>=0&&AP<=2&&(HP+AP)==extrapoints) return true;
    else return false;
}
