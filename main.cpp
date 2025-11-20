// CSCI-40 Final Project
// Author: Luis Amaro

/* 
Description:
My project idea will be for a PC building helper app designed to assist them in 
viewing, adding, and ordering PC components for those having trouble doing so 
on their own. The user will be able to use this app to see a large catalogue of 
parts for computers and will be able to even add parts not listed in the initial
registry. The prices of each individual part as well as their related specs will 
be displayed. The user will be given the prompted to either order their chosen 
parts or even be able order their pc prebuilt if they have selected enough of the 
required parts. After ordering the user will have a list file saved for them that 
will show all their parts and the prices as well as the total for everything that 
is being shipped. This file can be sent to the app so that the user can modify it 
if they wish to remove or add parts or can be used to cancel the order entirely.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using  namespace std;

const int tempLimit = 50;

class ComputerData
{
private:
	float cost;
	string partName;
	int numberUsed;
	
public:
	ComputerData()
	{
		partName = "";
		cost = 0;
		numberUsed = 0;
	}
	void getItemName(string name);
	void getItemCost(float itemCost);
	void getNumItem(int amount);
	void printItems();
};

int main() 
{
	ComputerData CD[tempLimit];
	float partCost; // will be a placeholder for cost to have the inputted data be sent to the class member
	string nameOfPart;  // will be a placeholder for partName to have the inputted data be sent to the class member
	int amount;  // will be a placeholder for numberUsed to have the inputted data be sent to the class member
	int totalNumParts = 0; 
	string filename;
	string filePath;

	cout << "Will you be ordering parts, building a a full PC, or reading in an order/build file?" << endl 
		<< "Type the matching number to proceed." << endl << "1. Order" << endl << "2. Build"
		<< endl << "3. Read file" << endl;
	int option;
	bool breakLoop = false;
	while (breakLoop == false)
	{
		cin >> option;
		if (option == 1)
		{
			
			breakLoop = true;
		}
		else if (option == 2)
		{
			
			breakLoop = true;
		}
		else if (option == 3)
		{
			ifstream infile;
			cout << "Enter the file path of the file you wish to read:" << endl;
			cin >> filePath;
			infile.open(filePath);
			int i = 0;
			while (i < tempLimit && infile >> nameOfPart >> partCost >> amount) {
				CD[i].getItemName(nameOfPart);
				CD[i].getItemCost(partCost);
				CD[i].getNumItem(amount);
				i++;
				totalNumParts++;
			}
			for (int i = 0; i < totalNumParts; i++) {
				CD[i].printItems();
			}
			breakLoop = true;
		}
		else
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Invalid choice try again" << endl;
		}
		
	}
	
	return 0;
}

// ----------------------------------Functions------------------------------------

void ComputerData::getItemName(string name)
{
	partName = name;
}
void ComputerData::getItemCost(float itemCost)
{
	cost = itemCost;
}
void ComputerData::getNumItem(int amount)
{
	numberUsed = amount;
}
void ComputerData::printItems()
{
	cout << partName << " $" << cost << " " << numberUsed << endl;
}