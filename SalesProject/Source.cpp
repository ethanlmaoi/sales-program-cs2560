#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// function prototypes
void displayPrompt();
void getUserInput(string &userInput);
void addSale(vector<string> &itemNames, vector<double> &itemPrices);
void viewSales(const vector<string> itemNames, const vector<double> itemPrices, const int numberOfItems);
void editSale(const vector<string> &itemNames, vector<double> &itemPrices, const int numberOfItems);
void removeSale(vector<string> &itemNames, vector<double> &itemPrices, int numberOfItems);

int main() {
	vector<string> itemNames;
	vector<double> itemPrices;
	int numberOfItems = 0;
	bool finished = false;

	// introduces the program
	cout << "\nWelcome to the Sales Program!" << endl << "Created By Ethan Liao (CS2560)" << endl << "---------------------" << endl;

	// checks if the program is finished
	while (!finished) {
		// prompts the user to enter a command
		displayPrompt();

		// receive input from the user
		string userInput;
		getUserInput(userInput);
		
		// perform action based on input
		if (userInput == "A") { 
			addSale(itemNames, itemPrices);
			numberOfItems++;
		}
		else if (userInput == "V") {
			if (numberOfItems == 0)
				cout << "Cannot view! Add at least one sale first!" << endl;
			else
				viewSales(itemNames, itemPrices, numberOfItems);
		}
		else if (userInput == "E") {
			if (numberOfItems == 0)
				cout << "Cannot edit! Add at least one sale first!" << endl;
			else
				editSale(itemNames, itemPrices, numberOfItems);
		}
		else if (userInput == "R") {
			if (numberOfItems == 0)
				cout << "Cannot remove! Add at least one sale first!" << endl;
			else {
				removeSale(itemNames, itemPrices, numberOfItems);
				numberOfItems--;
			}
		}
		else if (userInput == "0") {
			finished = true;
		}
		else
		{
			cout << "That is not a valid input!" << endl;
		}
	}

	cout << "\nThank you for using the program!" << endl;
	
	return 0;
}

void addSale(vector<string> &itemNames, vector<double> &itemPrices) {
	string name;
	double price;

	cout << "\nEnter the name of the item: " << endl;
	cin.ignore();
	getline(cin, name);
	itemNames.push_back(name); // appends item name into Item Names

	cout << "Enter the price of the item: " << endl;
	cin >> price;
	itemPrices.push_back(price); // appends price into Price Names
}

void viewSales(const vector<string> itemNames, const vector<double> itemPrices, const int numberOfItems) {
	cout << "\nItem Index" << "             " << "Item Name" << "             " << "Item Price" << endl;
	for (int i = 0; i < numberOfItems; i++) {
		cout << "    " << left << setw(5) << i << right << setw(23) << itemNames[i] << right << setw(23) << fixed << setprecision(2) << itemPrices[i] << endl;
	}
}

void editSale(const vector<string> &itemNames, vector<double> &itemPrices, const int numberOfItems) {
	int userIndex;
	double newPrice;
	bool valid = false;

	viewSales(itemNames, itemPrices, numberOfItems);

	while (!valid) {
		cout << "\nWhich sale do you want to edit? (Input Index): ";
		cin >> userIndex;
		if (userIndex > numberOfItems-1 || userIndex < 0) {
			cout << "That is not a valid vector index!" << endl;
		}
		else
		{
			valid = true;
		}
	}

	cout << "What do you want the new price to be?: ";
	cin >> newPrice;

	itemPrices[userIndex] = newPrice; // update the price
}

void removeSale(vector<string> &itemNames, vector<double> &itemPrices, int numberOfItems) {
	int userIndex;
	bool valid = false;;
	viewSales(itemNames, itemPrices, numberOfItems);

	while (!valid) {
		cout << "\nWhich sale do you want to remove? (Input Index): ";
		cin >> userIndex;
		if (userIndex > numberOfItems-1 || userIndex < 0) {
			cout << "That is not a valid vector index!" << endl;
		}
		else
		{
			valid = true;
		}
	}
	cout << "Removed " << itemNames[userIndex] << " ($" << itemPrices[userIndex] << ")" << endl;
	itemNames.erase(itemNames.begin() + userIndex); // remove from Item Names
	itemPrices.erase(itemPrices.begin() + userIndex); // remove from Item Prices
}

void displayPrompt() {
	cout << "\nEnter 'A' to add an item" << endl;
	cout << "Enter 'V' to view your sales" << endl;
	cout << "Enter 'E' to edit a sale" << endl;
	cout << "Enter 'R' to remove a sale" << endl;
	cout << "Enter '0' to exit program" << endl;
}

void getUserInput(string &userInput) {
	cout << "\nWhich function do you want to perform?: ";
	cin >> userInput;
}