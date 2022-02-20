#include <iostream>
#include <iomanip>
#include "ChocoFun.h"

using namespace std;

int main() {
	char select;
	bool access = true;
	int lrgInv = 1500;
	int medInv = 1200;
	int smlInv = 7000;
	int totalPounds;
	int cycle = 1;
	cout << "Welcome to Nguyen Chocolate Inventory Control Program" << endl;
	cout << setfill('-') << setw(53) << "" << endl;

	while (access) {
		
		select = Menu();
		switch (select) {
			case 'E':
				access = false;
				break;
			case 'F':
				totalPounds = getValue("Enter the total pounds of chocolate you would like: ");
				cout << endl;
				fillOrder(lrgInv, medInv, smlInv, totalPounds, cycle);
				cycle += 1;
				break;
			case 'P':
				printInv(lrgInv, medInv, smlInv);
				break;
			case 'O':
				orderInv(lrgInv, medInv, smlInv);
				break;
		}

	}
	cout << endl;
	cout << "Thank you for using N.C.I.C.P" << endl;
	

}
