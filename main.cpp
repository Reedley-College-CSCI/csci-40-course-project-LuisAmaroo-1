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

const int tempLimit = 30;

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
	void printRam();
	void printCPU();
	void printGPU();
	void printPSU();
	void printMotherboards();
	void printStorage();
	void printCordsAndWires();
	void printCart();

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

	
	int option;
	bool breakLoop = false;
	while (breakLoop == false)
	{
		
		cout << "Will you be ordering parts, building a a full PC, or reading in an order/build file?" << endl
			<< "Type the matching number to proceed." << endl << "1. Order" << endl << "2. Build"
			<< endl << "3. Read file" << endl;cin >> option;
		if (option == 1) // Order root choice ***********************************
		{
			int partChoice;
			cout << "Type number of which part(s)/action you would like to select:" << endl;
			cout << "1. RAM sticks (Random Access Memory)" << endl << "2. CPU (Central Processing Unit)"
				<< endl << "3. GPU (Graphics Processing Unit)" << endl << "4. PSU (Power Supply Unit)" 
				<< endl << "4. Motherboards" << endl << "5. Storage Devices" << endl << "6. Computer Fans"
				<< endl << "7. Cords/Wires" << endl << "8. View cart" << endl << "9. To proceed to checkout" 
				<< endl << "0. To cancel order and return to menu" << endl;
			cout << "You can choose a max amount of 50 parts" << endl;
			cin >> partChoice;
			while (true)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input! Please enter a number.\n";
					cin >> partChoice;
					continue;
				}

				if (partChoice == 0) // exit
				{
					cout << "Returning to main menu.\n";
					breakLoop = false;
					totalNumParts = 0;
					break;
				}

				if (partChoice == 1) // RAM sticks
				{
					
				}
				else if (partChoice == 2) // CPUs
				{
				
				}
				else if (partChoice == 3) // GPUs
				{
				
				}
				else if (partChoice == 4)// PSUs
				{
				
				}
				else if (partChoice == 5) // Motherboards
				{
				
				}
				else if (partChoice == 6) // Storage devices
				{

				}
				else if (partChoice == 7) // Cords/Wires
				{

				}
				else if (partChoice == 8) //Cart
				{
					/* Will be used once parts are able to be added
					for (int i = 0; i < totalNumParts; i++) {
				CD[i].printItems();
			}
					*/
				}
				else if (partChoice == 9) // Checkout
				{
					breakLoop = true;
					break; //To do add a method to checkout. Temp break used
				}
				else
				{
					cout << "Invalid choice! Try again.\n";
				}
				cout << "Type number of which part(s)/action you would like to select:" << endl;
				cout << "1. RAM(Random Access Memory)" << endl << "2. CPU (Central Processing Unit)"
					<< endl << "3. GPU (Graphics Processing Unit)" << endl << "4. PSU (Power Supply Unit)"
					<< endl << "4. Motherboards" << endl << "5. Storage Devices" << endl << "6. Computer Fans"
					<< endl << "7. Cords/Wires" << endl << "8. View cart" << endl << "9. To proceed to checkout"
					<< endl << "0. To cancel order and return to menu" << endl;
				cout << totalNumParts << " parts selected" << endl;
				cin >> partChoice;
			}

		}
		else if (option == 2) //Build root choice **************************
		{
			int partChoice;
			cout << "Type number of which part(s)/action you would like to select:" << endl;
			cout << "1. RAM sticks (Random Access Memory)" << endl << "2. CPU (Central Processing Unit)"
				<< endl << "3. GPU (Graphics Processing Unit)" << endl << "4. PSU (Power Supply Unit)"
				<< endl << "4. Motherboards" << endl << "5. Storage Devices" << endl << "6. Computer Fans"
				<< endl << "7. Cords/Wires" << endl << "8. View current build" << endl << "9. To proceed to checkout"
				<< endl << "0. To cancel build and return to menu" << endl;
			cout << "You can choose a max amount of 30 parts" << endl;
			cout << "You will need to have selected a required amount of parts to be able to proceed to checkout" << endl;
			cin >> partChoice;
			while (true)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input! Please enter a number.\n";
					cin >> partChoice;
					continue;
				}

				if (partChoice == 0) // exit
				{
					cout << "Returning to main menu.\n";
					breakLoop = false;
					totalNumParts = 0;
					break;
				}

				if (partChoice == 1) // RAM sticks
				{

				}
				else if (partChoice == 2) // CPUs
				{

				}
				else if (partChoice == 3) // GPUs
				{

				}
				else if (partChoice == 4)// PSUs
				{

				}
				else if (partChoice == 5) // Motherboards
				{

				}
				else if (partChoice == 6) // Storage devices
				{

				}
				else if (partChoice == 7) // Cords/Wires
				{

				}
				else if (partChoice == 8) //Build
				{
					// to do 
				}
				else if (partChoice == 9) // Checkout
				{
					/* This if will be used to prevent user from proceeding to checkout
					if ()
					{
					
					}
					else
					{
					cout << "Not enough parts selected" << endl;
					}
					*/
					breakLoop = true;
					break; //To do add a method to checkout built pc. Temp break used
				}
				else
				{
					cout << "Invalid choice! Try again.\n";
				}
				cout << "Type number of which part(s)/action you would like to select:" << endl;
				cout << "1. RAM sticks (Random Access Memory)" << endl << "2. CPU (Central Processing Unit)"
					<< endl << "3. GPU (Graphics Processing Unit)" << endl << "4. PSU (Power Supply Unit)"
					<< endl << "4. Motherboards" << endl << "5. Storage Devices" << endl << "6. Computer Fans"
					<< endl << "7. Cords/Wires" << endl << "8. View current build" << endl << "9. To proceed to checkout"
					<< endl << "0. To cancel build and return to menu" << endl;
				cout << "You can choose a max amount of 30 parts" << endl;
				cout << totalNumParts << " parts selected" << endl;
				//to do add a way to display which parts are still required to check out
				cin >> partChoice;
			}
		}
		else if (option == 3) //File read root choice ***********************************
		{
			ifstream infile;
			cout << "Enter the file path of the file you wish to read:" << endl;
			cin >> filePath;
			infile.open(filePath);
			
			if (!infile)
			{
				cout << "Error file not found" << endl;
			}
			while (totalNumParts < tempLimit && infile >> nameOfPart >> partCost >> amount) {
				CD[totalNumParts].getItemName(nameOfPart);
				CD[totalNumParts].getItemCost(partCost);
				CD[totalNumParts].getNumItem(amount);
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