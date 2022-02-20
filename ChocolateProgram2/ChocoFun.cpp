#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ChocoFun.h"

using namespace std;

char Menu() {							//Display Menu & returns user's choice
	char select = 'M';
	cout << setw(10) << "F - Fill Order" << endl;
	cout << "P - Print Inventory" << endl;
	cout << "O - Order Inventory" << endl;
	cout << "E - Exit" << endl;
	cout << endl;
	cout << "What would you like to do?";
	cin >> select;
	select = toupper(select);
	while ((select != 'F') && (select != 'P') && (select != 'O') && (select != 'E')) {	//Error handling
		cout << "Invalid Entry - Please select from the menu: ";
		cin >> select;
		select = toupper(select);
	}
	return select;
}
void printInv(int lrgInv, int medInv, int smlInv) {  //Display current inventory
	cout << "Chocolate Inventory:" << endl;
	cout << "Large Bars:\t\t " << lrgInv << endl;
	cout << "Medium Bars:\t\t " << medInv << endl;
	cout << "Small Bars:\t\t" << smlInv << endl;
}
int getValue(string userStr) {						//Using program predefined string to obtain value from user
	int num = -1;
	cout << userStr;
	cin >> num;
	while (num <= 0) {								//Loop until valid number is entered
		cout << "Invalid entry - Please enter a value greater than 0: ";
		cin  >> num;
		cout << endl;
		if (num > 0)
			break;
	}
	return num;
}
int fillOrder(int& lrgInv, int& medInv, int& smlInv, int totalPounds, int& cycle) {
	int tempL, tempM, tempS;
	if (totalPounds == 0) {			//If order is 0, no order will be filled and no update to inventory will be made
		return 0;					//Exits the function back to menu
	}
	tempL = totalPounds / 5;						//Calculate amount of large bars to use
	if (tempL >= lrgInv)
		tempL = lrgInv;
	tempM = (totalPounds - (tempL * 5)) / 3;		//Calculate amount of medium bars to use
	if (tempM >= medInv)
		tempM = medInv;
	tempS = (totalPounds - ((tempL * 5) + (tempM * 3)));			//Calculate amount left for small bars to use
	if (tempS > smlInv) {										//Error message if inventory does not support order
		cout << "Invalid Entry - Order could not be filled." << endl;
		cout << endl;
	}
	else {
		double lrgPrice = 30.50, medPrice = 25.99, smlPrice = 10.50, tax = 0.075;
		double totalPrice, ship;

		if (totalPounds <= 10)								//Finding shipping cost bracket based on order weight
			ship = 5.25;
		else if (totalPounds <= 20)
			ship = 7.75;
		else if (totalPounds <= 50)
			ship = 12.25;
		else
			ship = 19.75;
		lrgPrice  *= tempL;			//Calculate total prices
		medPrice  *= tempM;
		smlPrice  *= tempS;
		totalPrice = lrgPrice + medPrice + smlPrice;
		double taxTot = totalPrice * tax;

		cout << "Chocolate Order #" << cycle << endl;		//Display info
		cout << "Large Bars:\t\t" << tempL << "\t$" << fixed << setprecision(2) << lrgPrice << endl;
		cout << "Medium Bars:\t\t" << tempM << "\t$" << fixed << setprecision(2) << medPrice << endl;
		cout << "Small Bars:\t\t" << tempS << "\t$" << fixed << setprecision(2) << smlPrice << endl;
		cout << endl;
		cout << "Sub Total:\t\t\t" << fixed << setprecision(2) <<"$"<< totalPrice << endl;
		cout << "Tax:\t\t\t\t" << fixed << setprecision(2) << "$" << taxTot << endl;
		cout << "Shipping:\t\t\t" << fixed << setprecision(2) << "$" << ship << endl;
		cout << "Total Cost:\t\t\t" << fixed << setprecision(2) << "$" << totalPrice + taxTot + ship << endl;
		cout << endl;

		//Update Inventory
		lrgInv -= tempL;
		medInv -= tempM;
		smlInv -= tempS;

	}

	return 0;
}
void orderInv(int& lrgInv, int& medInv, int& smlInv) {		//Update inventory with new orders
	char size;												//May only order one size at a time
	int order=0;
	cout << endl;
	cout << "What size chocolate to be order (L, M, or S): ";
	cin >> size;
	size = toupper(size);
	if ((size == 'L') || (size == 'M') || (size == 'S')) {
		switch (size) {
		case 'L':
			cout << "Qauntity: ";
			cin  >> order;
			lrgInv += order;
			break;
		case 'M':
			cout << "Qauntity: ";
			cin  >> order;
			medInv += order;
			break;
		case 'S':
			cout << "Qauntity: ";
			cin  >> order;
			smlInv += order;
			break;

		}
		cout << "\n" << "Order placed!" << endl;
		cout << endl;
	}
	else
		cout << "Invalid Entry - Error in size" << endl;		//Error handling
																//Will not loop, return to menu

}