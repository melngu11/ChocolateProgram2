#pragma once
#pragma once
#include <vector>
using namespace std;


//Function Declartions

int getValue(string userStr);
//Pre  : Using program predefined string to obtain value from user
//Post : return number

char Menu();
//Pre  : N/A
//Post : display menu and return user's choice

int fillOrder(int& lrgInv, int& medInv, int& smlInv, int totalPounds, int& cycle);
//Pre  : accept current inventory for all size, currently order number and desired order weight
//Post : calculates order by size and display filled order information. Updates inventory after/if filled


void printInv(int lrgInv, int medInv, int smlInv);
//Pre  : accept current inventory 
//Post : display current inventory

void orderInv(int& lrgInv, int& medInv, int& smlInv);
//Pre  : accept currently inventory
//Post : using user desired order quantity to update specific size inventory