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
#include<iomanip>
using  namespace std;
const int ITEM_LIMIT = 30; //max limit
class ComputerData //class
{
private:
	float cost[ITEM_LIMIT];
	string partName[ITEM_LIMIT];
	int numberUsed[ITEM_LIMIT];
	
	
	
public:
	ComputerData() //
	{
		partName[0] = "";
		cost[0] = 0;
		numberUsed[0] = 0;
		
	}
	void getItemName(string name, int index);
	void getItemCost(float itemCost, int index);
	void getNumItem(int amount, int index);
	void printFileItems(int index);
	void printRam();
	void printCPU();
	void printGPU();
	void printPSU();
	void printMotherboards();
	void printStorage();
	void printCordsAndWires();
	void printCart(int index) const;
	void purchaseToFile(int index);
	float findSum(int index);
	//arrays holding item names and prices for all catagories
	string ramNames[12]
	{ "Corsair Vengeance LPX 16GB(2x8GB) DDR4 - 4600 CL19 - $150.99",
	 "G.SKILL Ripjaws V 32GB (2x16GB) DDR4-3600 CL18 - $169.99",
	 "Crucial Ballistix 16GB (2x8GB) DDR4-3200 CL16 - $109.99",
	 "TEAMGROUP T-Force Delta RGB 32GB (2x16GB) DDR4-3600 CL18 - $179.99",
	 "Kingston Fury Beast 16GB (2x8GB) DDR4-3200 CL16 - $119.99",
	 "Patriot Viper Steel 32GB (2x16GB) DDR4-4000 CL19 - $189.99",
	 "Corsair Vengeance RGB 32GB (2x16GB) DDR5-6000 CL36 - $407.99",
	 "Crucial Pro Overclocking 32GB (2x16GB) DDR5-6000 CL36 - $273.99",
	 "G.SKILL Trident Z5 Neo RGB 32GB (2x16GB) DDR5-6400 CL32 - $459.99",
	 "G.SKILL Trident Z5 Neo RGB 128GB (2x64GB) DDR5-6000 CL34 - $929.99",
	 "Thermaltake TOUGHRAM XG RGB 32GB (2x16GB) DDR5-6000 CL36 - $249.99",
	 "Kingston Fury Renegade 32GB (2x16GB) DDR5-6400 CL32 - $479.99" };
	string cpuNames[10]
	{ "Intel Core i9-14900K – $499.99",
	"Intel Core i7-14700K – $334.99",
	"Intel Core i5-14600K – $204.99",
	"Intel Core i3-14100 – $131.82",
	"Intel Core i5-12400F – $137.99",
	"AMD Ryzen 9 7950X – $501.00",
	"AMD Ryzen 9 7900X – $374.00",
	"AMD Ryzen 7 7700X – $299.00",
	"AMD Ryzen 5 7600X – $204.00",
	"AMD Ryzen 5 5600 – $146.99" };
	string gpuNames[8]
	{ "GeForce RTX 4090 – $3,499.00",
	"GeForce RTX 4080 – $1,779.00",
	"GeForce RTX 4070 Ti – $899.00",
	"Intel Arc A770 – $322.00",
	"Intel Arc A750 – $283.00",
	"Radeon RX 7900 XTX – $809.00",
	"Radeon RX 7800 XT – $593.00",
	"Radeon RX 7900 XT – $580.00" };
	string psuNames[7]
	{ "Corsair RM850x (850W, 80+ Gold, Fully Modular) – $149.99",
	"EVGA SuperNOVA 750 G6 (750W, 80+ Gold, Fully Modular) – $129.99",
	"Seasonic PRIME TX-1000 (1000W, 80+ Titanium, Fully Modular) – $689.00",
	"Cooler Master MWE Gold 750 V2 (750W, 80+ Gold, Fully Modular) – $69.99",
	"ASUS ROG Thor 1200W Platinum II (1200W, 80+ Platinum, Fully Modular) – $599.00",
	"Thermaltake Toughpower GF1 (850W, 80+ Gold, Fully Modular) – $216.50",
	"MSI MPG A850G (850W, 80+ Gold, Fully Modular) – $129.99" };
	string mbNames[8] //motherboard
	{ "ASUS ROG Strix Z790-E Gaming WiFi – $399.99",
	"MSI MPG Z790 Carbon WiFi – $361.20",
	"Gigabyte Z790 AORUS Elite AX – $179.99",
	"ASRock Z790 Taichi – $379.99",
	"MSI MAG B650 Tomahawk WiFi – $179.99",
	"ASUS TUF Gaming X670E-Plus WiFi – $209.99",
	"ASRock B650E Steel Legend WiFi – $198.99",
	"Gigabyte B550 AORUS Elite – $188.42" };
	string storageNames[8]
	{ "Seagate Barracuda 2TB HDD (7200 RPM) – $64.99",
	"Toshiba X300 4TB HDD (7200 RPM) – $137.13",
	"Western Digital Blue 1TB HDD (7200 RPM) – $42.95",
	"Samsung 980 Pro 1TB NVMe SSD – $99.99",
	"WD Black SN850X 1TB NVMe SSD – $109.99",
	"Crucial P5 Plus 1TB NVMe SSD – $139.95",
	"Kingston KC3000 1TB NVMe SSD – $132.11",
	"Sabrent Rocket 4 Plus 2TB NVMe SSD – $209.99" };
	string wireAndCordNames[8]
	{ "ATX 24-Pin Motherboard Power Cable — $8.99",
	"CPU 8-Pin EPS Power Cable (4+4 Pin) — $7.59",
	"PCIe GPU Power Cable (8-Pin to 6+2 Pin) — $12.99",
	"SATA III Data Cable (18-inch, pack of 3) — $6.99",
	"USB 3.0 Internal Header Cable (19/20 Pin) — $9.89",
	"Front Panel USB 3.0 Extension Cable — $12.79",
	"HDMI Cable (6 ft, High-Speed 4K) — $8.49",
	"DisplayPort Cable (6 ft, 4K/8K Ready) – $12.29" };
	float ramPrice[12]{ 150.99, 169.99, 109.99, 179.99, 119.99, 189.99, 407.99, 273.99, 459.99, 929.99, 249.99, 479.99 };
	float cpuPrice[10]{ 499.99, 334.99, 204.99, 131.82, 137.99, 501.00, 374.00, 299.00, 204.00, 146.99 };
	float gpuPrice[8]{ 3499.00, 1779.00, 899.00, 322.00, 283.00, 809.00, 593.00, 580.00 };
	float psuPrice[7]{ 149.99, 129.99, 689.00, 69.99, 599.00, 216.50, 129.99 };
	float mbPrice[8]{ 399.99, 361.20, 179.99, 379.99, 179.99, 209.99, 198.99, 188.42};
	float storagePrice[8]{ 64.99, 137.13, 42.95, 99.99, 109.99, 139.95, 132.11, 209.99};
	float wireAndCordPrice[8]{8.99, 7.59, 12.99, 6.99, 9.89, 12.79, 8.49, 12.29};

};
int main() 
{
	ComputerData CD;
	float partCost; // will be a placeholder for cost to have the inputted data be sent to the class member
	string nameOfPart;  // will be a placeholder for partName to have the inputted data be sent to the class member
	int amount;  // will be a placeholder for numberUsed to have the inputted data be sent to the class member
	int totalNumParts = 0; 
	string filename;
	string filePath;
	bool ramAdded = false;
	bool cpuAdded = false;
	bool gpuAdded = false;
	bool psuAdded = false;
	bool mbAdded = false;
	bool storageAdded = false;
	int option;
	int maxStorage = 0;
	bool breakLoop = false;
	while (breakLoop == false)
	{
		
		cout << "Will you be ordering parts, building a a full PC, or reading in an order/build file?" << endl
			<< "Type the matching number to proceed." << endl << "1. Order" << endl << "2. Build"
			<< endl << "3. Read file" << endl;cin >> option;
		if (option == 1) // Ordering root choice ****************************************************************
		{
			int partChoice;
			cout << "Type number of which part(s)/action you would like to select:" << endl;
			cout << "1. RAM sticks (Random Access Memory)" << endl << "2. CPU (Central Processing Unit)"
				<< endl << "3. GPU (Graphics Processing Unit)" << endl << "4. PSU (Power Supply Unit)"
				<< endl << "4. Motherboards" << endl << "5. Storage Devices" << endl << "6. Computer Fans"
				<< endl << "7. Cords/Wires" << endl << "8. View cart" << endl << "9. To proceed to checkout"
				<< endl << "0. To cancel order and return to menu" << endl;
			cout << "You can choose a max amount of 30 parts" << endl;
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
					CD.printRam();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.ramNames[indexChoice];
					float costOfItem = CD.ramPrice[indexChoice];
					if (itemName == CD.ramNames[indexChoice] && costOfItem == CD.ramPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						itemAmount--;
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}

				}
				else if (partChoice == 2) // CPUs
				{
					CD.printCPU();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.cpuNames[indexChoice];
					float costOfItem = CD.cpuPrice[indexChoice];
					if (itemName == CD.cpuNames[indexChoice] && costOfItem == CD.cpuPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}
				}
				else if (partChoice == 3) // GPUs
				{
					CD.printGPU();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.gpuNames[indexChoice];
					float costOfItem = CD.gpuPrice[indexChoice];
					if (itemName == CD.gpuNames[indexChoice] && costOfItem == CD.gpuPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}
				}
				else if (partChoice == 4)// PSUs
				{
					CD.printPSU();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.psuNames[indexChoice];
					float costOfItem = CD.psuPrice[indexChoice];
					if (itemName == CD.psuNames[indexChoice] && costOfItem == CD.psuPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}
				}
				else if (partChoice == 5) // Motherboards
				{
					CD.printMotherboards();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.mbNames[indexChoice];
					float costOfItem = CD.mbPrice[indexChoice];
					if (itemName == CD.mbNames[indexChoice] && costOfItem == CD.mbPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}
				}
				else if (partChoice == 6) // Storage devices
				{
					CD.printStorage();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.storageNames[indexChoice];
					float costOfItem = CD.storagePrice[indexChoice];
					if (itemName == CD.storageNames[indexChoice] && costOfItem == CD.storagePrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}
				}
				else if (partChoice == 7) // Cords/Wires
				{
					CD.printCordsAndWires();
					cout << "Enter item number: " << endl;
					int indexChoice;
					cin >> indexChoice;
					if (indexChoice == 0) break;
					indexChoice -= 1;
					string itemName = CD.wireAndCordNames[indexChoice];
					float costOfItem = CD.wireAndCordPrice[indexChoice];
					if (itemName == CD.wireAndCordNames[indexChoice] && costOfItem == CD.wireAndCordPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
						int itemAmount;
						cout << "How many of this item would you like to order?" << endl;
						cin >> itemAmount;
						CD.getItemName(itemName, totalNumParts);
						CD.getItemCost(costOfItem, totalNumParts);
						CD.getNumItem(itemAmount, totalNumParts);
						totalNumParts++;
						cout << totalNumParts << endl;
					}
					else
					{
						cout << "Invalid choice" << endl;
					}
				}
				else if (partChoice == 8) //Cart
				{
					cout << endl << "Items in cart:" << endl;
					if (totalNumParts > 0)
					{
						for (int i = 0; i < totalNumParts; i++)
						{
							CD.printCart(i);
						}
						cout << "Total price: $";
						cout << fixed << setprecision(2) << CD.findSum(totalNumParts) << endl;
					}
					else
					{
						cout << endl << "No items in cart" << endl << endl;
					}
				}
				else if (partChoice == 9) // Checkout
				{
					char yesOrNo;
					cout << "Would you like to view your build before proceeding to checkout? y/n" << endl;
					cin >> yesOrNo;
					cout << yesOrNo << endl;
					while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N')
					{
						cout << "Invalid choice try again" << endl;
						cin >> yesOrNo;
					}
					if (yesOrNo == 'y' || yesOrNo == 'Y')
					{
						cout << endl << "Items in cart:" << endl;
						if (totalNumParts > 0)
						{
							for (int i = 0; i < totalNumParts; i++)
							{
								CD.printCart(i);
							}
						}
					}
					else
					{
						cout << "Continuing" << endl;
					}
					cout << "Total price: $";
					cout << fixed << setprecision(2) << CD.findSum(totalNumParts) << endl;
					long int card;
					int cvv;
					cout << "Please enter your 12 digit card number. Or enter 0 to go back to menu." << endl;
					cin >> card;
					if (card == 0) break;
					cout << "Please enter your 3 digit cvv" << endl;
					cin >> cvv;
					if (card >= 100000000000 && card < 1000000000000 && cvv > 0 && cvv < 1000)
					{
						cout << "Thank you for your purchase! Would you like to save a file of your purchase? y/n" << endl;
						char yesOrNo;
						cin >> yesOrNo;
						while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N')
						{
							cout << "Invalid choice try again" << endl;
							cin >> yesOrNo;
						}
						if (yesOrNo == 'y' || yesOrNo == 'Y')
						{
							CD.purchaseToFile(totalNumParts);
							cout << "Purchase complete." << endl;
						}
						else
							cout << "Purchase complete." << endl;
						breakLoop = true;
						return 0;
					}
					else
					{
						cout << "Invalid cvv or card number." << endl << endl;
					}
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
				<< endl << "5. Motherboards" << endl << "6. Storage Devices"  << endl 
				<< "7. View current build" << endl << "8. To proceed to checkout"
				<< endl << "0. To cancel build and return to menu" << endl;
			cout << "You will need to have selected a required amount of parts to be able to proceed to checkout." << endl
				 << "Each item can be chosen only once however storage devices can be chosen up to 3 times. Cancel to reset choices." << endl 
				<< " A free case will be provided with your purchase. The base number of required wires/cords will be added at a flat fee." << endl;
			if(ramAdded == false)
			{
				cout << "RAM required" << endl;
			}
			if (cpuAdded == false)
			{
				cout << "CPU required" << endl;
			}
			if (gpuAdded == false)
			{
				cout << "GPU required" << endl;
			}
			if (psuAdded == false)
			{
				cout << "PSU required" << endl;
			}
			if (mbAdded == false)
			{
				cout << "Montherboard required" << endl;
			}
			if (storageAdded == false)
			{
				cout << "Storage required" << endl;
			}
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
					ramAdded = false;
					cpuAdded = false;
					gpuAdded = false;
					psuAdded = false;
					mbAdded = false;
					storageAdded = false;
					maxStorage = 0;
					break;
				}

				if (partChoice == 1) // RAM sticks
				{
					if(ramAdded == false)
					{
						CD.printRam();
						cout << "Enter item number: " << endl;
						int indexChoice;
						cin >> indexChoice;
						if (indexChoice == 0) break;
						indexChoice -= 1;
						string itemName = CD.ramNames[indexChoice];
						float costOfItem = CD.ramPrice[indexChoice];
						if (itemName == CD.ramNames[indexChoice] && costOfItem == CD.ramPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
							int itemAmount;
							itemAmount = 1;
							CD.getItemName(itemName, totalNumParts);
							CD.getItemCost(costOfItem, totalNumParts);
							CD.getNumItem(itemAmount, totalNumParts);
							itemAmount--;
							totalNumParts++;
							ramAdded = true;
						}
						else
						{
							cout << "Invalid choice" << endl;
						}
					}
					else cout << "Max RAM added" << endl;
				}
				else if (partChoice == 2) // CPUs
				{
					if (cpuAdded == false)
					{
						CD.printCPU();
						cout << "Enter item number: " << endl;
						int indexChoice;
						cin >> indexChoice;
						if (indexChoice == 0) break;
						indexChoice -= 1;
						string itemName = CD.cpuNames[indexChoice];
						float costOfItem = CD.cpuPrice[indexChoice];
						if (itemName == CD.cpuNames[indexChoice] && costOfItem == CD.cpuPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
							int itemAmount;
							itemAmount = 1;
							CD.getItemName(itemName, totalNumParts);
							CD.getItemCost(costOfItem, totalNumParts);
							CD.getNumItem(itemAmount, totalNumParts);
							totalNumParts++;
							cpuAdded = true;
						}
						else
						{
							cout << "Invalid choice" << endl;
						}
					}
					else cout << "Max CPUs added" << endl;
				}
				else if (partChoice == 3) // GPUs
				{
					if(gpuAdded == false)
					{
						CD.printGPU();
						cout << "Enter item number: " << endl;
						int indexChoice;
						cin >> indexChoice;
						if (indexChoice == 0) break;
						indexChoice -= 1;
						string itemName = CD.gpuNames[indexChoice];
						float costOfItem = CD.gpuPrice[indexChoice];
						if (itemName == CD.gpuNames[indexChoice] && costOfItem == CD.gpuPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
							int itemAmount;
							itemAmount = 1;
							CD.getItemName(itemName, totalNumParts);
							CD.getItemCost(costOfItem, totalNumParts);
							CD.getNumItem(itemAmount, totalNumParts);
							totalNumParts++;
							cout << totalNumParts << endl;
							gpuAdded = true;
						}
						else
						{
							cout << "Invalid choice" << endl;
						}
					}
					else cout << "Max GPUs added" << endl;
				}
				else if (partChoice == 4)// PSUs
				{
					if (psuAdded == false)
					{
						CD.printPSU();
						cout << "Enter item number: " << endl;
						int indexChoice;
						cin >> indexChoice;
						if (indexChoice == 0) break;
						indexChoice -= 1;
						string itemName = CD.psuNames[indexChoice];
						float costOfItem = CD.psuPrice[indexChoice];
						if (itemName == CD.psuNames[indexChoice] && costOfItem == CD.psuPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
							int itemAmount;
							itemAmount = 1;
							CD.getItemName(itemName, totalNumParts);
							CD.getItemCost(costOfItem, totalNumParts);
							CD.getNumItem(itemAmount, totalNumParts);
							totalNumParts++;
							cout << totalNumParts << endl;
							psuAdded = true;
						}
						else
						{
							cout << "Invalid choice" << endl;
						}
					}
					else cout << "Max PSUs added" << endl;
				}
				else if (partChoice == 5) // Motherboards
				{
					if (mbAdded == false) {
						CD.printMotherboards();
						cout << "Enter item number: " << endl;
						int indexChoice;
						cin >> indexChoice;
						if (indexChoice == 0) break;
						indexChoice -= 1;
						string itemName = CD.mbNames[indexChoice];
						float costOfItem = CD.mbPrice[indexChoice];
						if (itemName == CD.mbNames[indexChoice] && costOfItem == CD.mbPrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
							int itemAmount;
							itemAmount = 1;
							CD.getItemName(itemName, totalNumParts);
							CD.getItemCost(costOfItem, totalNumParts);
							CD.getNumItem(itemAmount, totalNumParts);
							totalNumParts++;
							cout << totalNumParts << endl;
							mbAdded = true;
						}
						else
						{
							cout << "Invalid choice" << endl;
						}
					}
					else cout << "Max motherboards added" << endl;
				}
				else if (partChoice == 6) // Storage devices
				{
					if(maxStorage < 3){
						CD.printStorage();
						cout << "Enter item number: " << endl;
						int indexChoice;
						cin >> indexChoice;
						if (indexChoice == 0) break;
						indexChoice -= 1;
						string itemName = CD.storageNames[indexChoice];
						float costOfItem = CD.storagePrice[indexChoice];
						if (itemName == CD.storageNames[indexChoice] && costOfItem == CD.storagePrice[indexChoice] && totalNumParts < ITEM_LIMIT) {
							int itemAmount;
							itemAmount = 1;
							CD.getItemName(itemName, totalNumParts);
							CD.getItemCost(costOfItem, totalNumParts);
							CD.getNumItem(itemAmount, totalNumParts);
							totalNumParts++;
							cout << totalNumParts << endl;
							storageAdded = true;
							maxStorage++;
						}
						else
						{
							cout << "Invalid choice" << endl;
						}
					}
				}
				else if (partChoice == 7) //Current build
				{
					cout << endl << "Current build:" << endl;
					if (totalNumParts > 0)
					{
						for (int i = 0; i < totalNumParts; i++)
						{
							CD.printCart(i);
						}
						cout << "Total cost: $" << CD.findSum(totalNumParts) << endl;
					}
					else
					{
						cout << endl << "No items in added to build" << endl << endl;
					}

				}
				else if (partChoice == 8) // Checkout
				{

					//This if will be used to prevent user from proceeding to checkout in they dont select all required parts
					if (ramAdded == true && cpuAdded == true && gpuAdded == true && psuAdded == true && mbAdded == true && storageAdded == true)
					{
						char yesOrNo;
						cout << "Would you like to view your build before proceeding to checkout? y/n" << endl;
						cin >> yesOrNo;

						while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N')
						{
							cout << "Invalid choice try again" << endl;
							cin >> yesOrNo;
						}
						if (yesOrNo == 'y' || yesOrNo == 'Y')
						{
							cout << endl << "Items in build:" << endl;

							for (int i = 0; i < totalNumParts; i++)
							{
								CD.printCart(i);
							}

						}
						else
						{
							cout << "Continuing" << endl;
						}
						cout << "Total price: $";
						cout << fixed << setprecision(2) << CD.findSum(totalNumParts) << endl;
						long long card;
						int cvv;
						cout << "Please enter your 12 digit card number. Or enter 0 to go back to menu." << endl;
						cin >> card;
						if (card == 0) break;
						cout << "Please enter your 3 digit cvv" << endl;
						cin >> cvv;
						if (card >= 100000000000 && card < 1000000000000 && cvv > 0 && cvv < 1000)
						{
							cout << "Thank you for your purchase! Would you like to save a file of your purchase? y/n" << endl;
							char yesOrNo;
							cin >> yesOrNo;
							while (yesOrNo != 'y' && yesOrNo != 'Y' && yesOrNo != 'n' && yesOrNo != 'N')
							{
								cout << "Invalid choice try again" << endl;
								cin >> yesOrNo;
							}
							if (yesOrNo == 'y' || yesOrNo == 'Y')
							{
								CD.purchaseToFile(totalNumParts);
								cout << "Purchase complete." << endl;
							}
							else
								cout << "Purchase complete." << endl;


							breakLoop = true;
						}
						else
						{
							cout << endl << "Not enough items chosen" << endl;
							break;
						}
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
				else
				{
					cout << "Invalid choice" << endl;
				}
				cout << "Type number of which part(s)/action you would like to select:" << endl;
				cout << "1. RAM sticks (Random Access Memory)" << endl << "2. CPU (Central Processing Unit)"
					<< endl << "3. GPU (Graphics Processing Unit)" << endl << "4. PSU (Power Supply Unit)"
					<< endl << "5. Motherboards" << endl << "6. Storage Devices" << endl << "7. View current build" 
					<< endl << "8. To proceed to checkout" << endl << "0. To cancel build and return to menu" << endl;
				cout << "You will need to have selected a required amount of parts to be able to proceed to checkout." << endl;
				if (ramAdded == false)
				{
					cout << "RAM required" << endl;
				}
				if (cpuAdded == false)
				{
					cout << "CPU required" << endl;
				}
				if (gpuAdded == false)
				{
					cout << "GPU required" << endl;
				}
				if (psuAdded == false)
				{
					cout << "PSU required" << endl;
				}
				if (mbAdded == false)
				{
					cout << "Montherboard required" << endl;
				}
				if (storageAdded == false)
				{
					cout << "Storage required" << endl;
				}
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
			while (totalNumParts < ITEM_LIMIT && infile >> nameOfPart >> partCost >> amount) {
				CD.getItemName(nameOfPart, totalNumParts);
				CD.getItemCost(partCost, totalNumParts);
				CD.getNumItem(amount, totalNumParts);
				totalNumParts++;
			}
			cout << "Item Name-Cost-Number of item ordered/in build" << endl;
			for (int i = 0; i < totalNumParts; i++) {
				CD.printFileItems(i);
			}
			cout << "Total price: $";
			cout << fixed << setprecision(2) << CD.findSum(totalNumParts) << endl;
			breakLoop = true;
			infile.close();
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
	cout << "Goodbye!" << endl;
	return 0;
}

// ----------------------------------Functions------------------------------------

void ComputerData::getItemName(string name, int index)
{
	partName[index] = name;
}
void ComputerData::getItemCost(float itemCost, int index)
{
	cost[index] = itemCost;
}
void ComputerData::getNumItem(int amount, int index)
{
	numberUsed[index] = amount;
}
void ComputerData::printFileItems(int index)
{
	
	cout << index + 1 << ". " << partName[index] << " x" << numberUsed[index] << endl;

}
void ComputerData::printRam()
{
	cout << "0. To cancel" << endl
		<< "DDR 4 Ram:\n";
	cout << "1. Corsair Vengeance LPX 16GB(2x8GB) DDR4 - 4600 CL19 - $150.99" << endl
		<< "2. G.SKILL Ripjaws V 32GB (2x16GB) DDR4-3600 CL18 - $169.99" << endl
		<< "3. Crucial Ballistix 16GB (2x8GB) DDR4-3200 CL16 - $109.99" << endl
		<< "4. TEAMGROUP T-Force Delta RGB 32GB (2x16GB) DDR4-3600 CL18 - $179.99" << endl
		<< "5. Kingston Fury Beast 16GB (2x8GB) DDR4-3200 CL16 - $119.99" << endl
		<< "6. Patriot Viper Steel 32GB (2x16GB) DDR4-4000 CL19 - $189.99" << endl << endl;
	cout << "\nDDR 5 Ram:\n";
	cout << "7. Corsair Vengeance RGB 32GB (2×16GB) DDR5-6000 CL36 – $407.99" << endl
		<< "8. Crucial Pro Overclocking 32GB (2×16GB) DDR5-6000 CL36 – $273.99" << endl
		<< "9. G.SKILL Trident Z5 Neo RGB 32GB (2×16GB) DDR5-6400 CL32 – $459.99" << endl
		<< "10. G.SKILL Trident Z5 Neo RGB 128GB (2×64GB) DDR5-6000 CL34 – $929.99" << endl
		<< "11. Thermaltake TOUGHRAM XG RGB 32GB (2×16GB) DDR5-6000 CL36 – $249.99" << endl
		<< "12. Kingston Fury Renegade 32GB (2×16GB) DDR5-6400 CL32 – $479.99" << endl << endl;
}
void ComputerData::printCPU()
{
	cout << "0. To cancel" << endl
		<< "Intel CPUs:" << endl
		<< "1. Intel Core i9-14900K - $499.99" << endl
		<< "2. Intel Core i7-14700K - $334.99" << endl
		<< "3. Intel Core i5-14600K - $204.99" << endl
		<< "4. Intel Core i3-14100 - $131.82" << endl
		<< "5. Intel Core i5-12400F - $137.99" << endl << endl
		<< "AMD CPUs" << endl
		<< "6. AMD Ryzen 9 7950X - $501.00" << endl
		<< "7. AMD Ryzen 9 7900X - $374.00" << endl
		<< "8. AMD Ryzen 7 7700X - $299.00" << endl
		<< "9. AMD Ryzen 5 7600X - $204.00" << endl
		<< "10. AMD Ryzen 5 5600 - $146.99" << endl << endl;
}
void ComputerData::printGPU()
{
	cout << "0. To cancel" << endl 
		<< "NVIDIA GPUs:" << endl
		<< "1. GeForce RTX 4090 - $3,499.00" << endl
		<< "2. GeForce RTX 4080 - $1, 779.00" << endl
		<< "3. GeForce RTX 4070 Ti - $899.00" << endl << endl
		<< "Intel GPUs:" << endl
		<< "4. Intel Arc A770 - $322.00" << endl
		<< "5. Intel Arc A750 - $283.00" << endl << endl
		<< "AMD GPUs:" << endl
		<< "6. Radeon RX 7900 XTX - $809.00" << endl
		<< "7. Radeon RX 7800 XT - $593.00" << endl
		<< "8. Radeon RX 7900 XT - $580.00" << endl << endl;
}
void ComputerData::printPSU()
{
	cout << "0. To cancel" << endl
		<< "PSUs:" << endl
		<< "1. Corsair RM850x (850W, 80+ Gold, Fully Modular) - $149.99" << endl
		<< "2. EVGA SuperNOVA 750 G6 (750W, 80+ Gold, Fully Modular) - $129.99" << endl
		<< "3. Seasonic PRIME TX-1000 (1000W, 80+ Titanium, Fully Modular) - $689.00" << endl
		<< "4. Cooler Master MWE Gold 750 V2 (750W, 80+ Gold, Fully Modular) - $69.99" << endl
		<< "5. ASUS ROG Thor 1200W Platinum II (1200W, 80+ Platinum, Fully Modular) - $599.00" << endl
		<< "6. Thermaltake Toughpower GF1 (850W, 80+ Gold, Fully Modular) - $216.50" << endl
		<< "7. MSI MPG A850G (850W, 80+ Gold, Fully Modular) - $129.99" << endl << endl;
}
void ComputerData::printMotherboards()
{
	cout << "0. To cancel" << endl
		<< "Intel Motherboard Platforms:" << endl
		<< "1. ASUS ROG Strix Z790-E Gaming WiFi - $399.99" << endl
		<< "2. MSI MPG Z790 Carbon WiFi - $361.20" << endl
		<< "3. Gigabyte Z790 AORUS Elite AX - $179.99" << endl
		<< "4. ASRock Z790 Taichi - $379.99" << endl << endl
		<< "AMD Motherboard Platforms:" << endl
		<< "5. MSI MAG B650 Tomahawk WiFi - $179.99" << endl
		<< "6. ASUS TUF Gaming X670E-Plus WiFi - $209.99" << endl
		<< "7. ASRock B650E Steel Legend WiFi - $198.99" << endl
		<< "8. Gigabyte B550 AORUS Elite - $188.42" << endl << endl;
}
void ComputerData::printStorage()
{
	cout << "0. To cancel" << endl
		<<"Hard Disk Drives:" << endl
		<< "1. Seagate Barracuda 2TB HDD (7200 RPM) - $64.99" << endl
		<< "2. Toshiba X300 4TB HDD (7200 RPM) - $137.13" << endl
		<< "3. Western Digital Blue 1TB HDD (7200 RPM) - $42.95" << endl << endl
		<< "Solid State Drives:" << endl
		<< "4. Samsung 980 Pro 1TB NVMe SSD - $99.99" << endl
		<< "5. WD Black SN850X 1TB NVMe SSD - $109.99" << endl
		<< "6. Crucial P5 Plus 1TB NVMe SSD - $139.95" << endl
		<< "7. Kingston KC3000 1TB NVMe SSD - $132.11" << endl
		<< "8. Sabrent Rocket 4 Plus 2TB NVMe SSD - $209.99" << endl << endl;

}
void ComputerData::printCordsAndWires()
{

	cout << "0. To cancel" << endl 
		<< "Power Cables:" << endl
		<< "1. ATX 24-Pin Motherboard Power Cable - $8.99" << endl
		<< "2. CPU 8-Pin EPS Power Cable (4+4 Pin) - $7.59" << endl
		<< "3. PCIe GPU Power Cable (8-Pin to 6+2 Pin) - $12.99" << endl << endl
		<< "Data Cables:" << endl
		<< "4. SATA III Data Cable (18-inch, pack of 3) - $6.99" << endl
		<< "5. USB 3.0 Internal Header Cable (19/20 Pin) - $9.89" << endl
		<< "6. Front Panel USB 3.0 Extension Cable - $12.79" << endl << endl
		<< "Display Cables:" << endl
		<< "7. HDMI Cable (6 ft, High-Speed 4K) - $8.49" << endl
		<< "8.DisplayPort Cable (6 ft, 4K/8K Ready) - $12.29" << endl << endl;

}
void ComputerData::printCart(int index) const
{
	cout << index+1 << ". " << partName[index] << " x" << numberUsed[index] << endl;
}
void ComputerData::purchaseToFile(int index)
{
	string fileName = "PurchaseReciept.txt";
	string filePath;
	float sum = 0.00;
	cout << "Enter a file location to save your file to (example: \"C: / Users / YourName / Documents /\")" << endl;
	cin >> filePath;
	ofstream saveFile;
	saveFile.open(filePath + fileName);
	if(!saveFile)
	{
		cout << "Error saving file" << endl;
		return;
	}
	for (int i = 0; i < index; i++)
	{
		saveFile << index + 1 << ". " << partName[index] << " x" << numberUsed[index] << endl;
	}
	saveFile << "*******************************************************************************************" << endl;
	saveFile << "Item Name-Cost-Number ordered" << endl;
	saveFile << "Total price: $";
	cout << fixed << setprecision(2) << findSum(index) << endl;
	saveFile << endl;
	saveFile.close();
	cout << "File saving complete." << endl;
}
float ComputerData::findSum(int index)
{
	float sum = 0.00;
	for (int i = 0; i < index; i++)
	{
		sum += cost[i];
	}
	return sum;
}