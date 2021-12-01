#include <iostream>
#include <string>
#include <vector>
#include "function.h"
using namespace std;

//random number generator to roll skill points
int roll(int n1, int n2){
  srand(time(0));
  return rand() % (n2-n1+1) + n1;
}

//function to check if the distributed skill points meet the requirements
bool checkinitdist(int HP, int AP, int initpoints, bool &initdist){
  if (HP >= 1 && HP <= 5 && AP >= 1 && AP <= 5) return true;
  else return false;
}
