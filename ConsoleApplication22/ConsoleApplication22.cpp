#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

//structure for details of each account
struct bankDetails
{
	string familyName="";
	string firstName="";
	long accountNumber=0;
	double accountBalance = 0.0;
};

//global variables
int numberOfAccounts;

//function declarations
int showMenu();
void addAccount(bankDetails b1[]);
void removeAccount(bankDetails b1[]);
int indexNum(bankDetails b[], long accNumber);
void depositMoney(bankDetails b1[]);
void withdrawMoney(bankDetails b1[]);
void showAccountInfo(bankDetails b1[]);
void swapArray(bankDetails b[], int i, int j);
void displayListDescending(bankDetails b1[]);
void displayListAscending(bankDetails b1[]);
double displayAverageBalance(bankDetails b1[]);
double displayTotalBalance(bankDetails b1[]);
template <typename T>

T GetValidInput(string msg, string errorMsg, T min, T max)
{
	T val;
	cout << msg;
	cin >> val;
	while ((cin.fail() || cin.peek() != '\n') || (val < min || val > max))
	{
		cin.clear();
		cin.ignore(512, '\n');
		cout << errorMsg;
		cin >> val;
	}
	return val;
}

int main()
{
	int SIZE_OF_ARRAY = 100;
	numberOfAccounts = 0;
	int choice;
	bankDetails b[100];
	cout << "WELCOME TO OUR BANK!!!" << endl;
	choice = showMenu();
	while (choice != 9)//loop for repeating the entry of choice until exit
	{
		switch (choice)//switch to take action according to the input choice number
		{
		case 1: addAccount(b);
			break;
		case 2: removeAccount(b);
			break;
		case 3: showAccountInfo(b);
			break;
		case 4: depositMoney(b);
			break;
		case 5: withdrawMoney(b);
			break;
		case 6: int choice;
			cout << "1: To sort in Ascending " << endl << "2: To sort in Descending ";
			choice = GetValidInput<int>("Enter your choice : ", "Invalid Input!!! Enter your choice in terms of digits from 1 and 2 only: ", 1, 2);
			if (choice == 1) {
				displayListAscending(b);
			}
			else if (choice == 2)
			{
				displayListDescending(b);
			}
			break;
		case 7:cout << "The total balance is : " << displayTotalBalance(b);
			break;
		case 8: cout << "The total balance is : " << displayAverageBalance(b);
			break;
		case 9: exit(0);
			break;
		default:;
		}
		choice = showMenu();
	}
	for (int i = 0; i <= numberOfAccounts; i++)

	{
		cout << b[i].firstName;
	}
}

int showMenu()//outputs the menu to the console for the user
{
	int choice;
	cout << endl << "MENU: " << endl;
	cout << "1 : Add a new bank account" << endl;
	cout << "2 : Remove a new bank account" << endl;
	cout << "3 : Show account information" << endl;
	cout << "4 : Deposit money in your account" << endl;
	cout << "5 : Withdraw money from your account" << endl;
	cout << "6 : Display the list of clients according to their balance, family name and given name" << endl;
	cout << "7 : Display the average balance value of the accounts" << endl;
	cout << "8 : Display the total balance value of the accounts" << endl;
	cout << "9 : Exit" << endl;
	choice = GetValidInput<int>("Enter your choice : ", "Invalid Input!!! Enter your choice in terms of digits from 1 to 9 only: ", 1, 9);
	return choice;
}

void addAccount(bankDetails b1[])//function to add an account
{ 
	double amountToDeposit=0.0;
	cout << endl << "Welcome to account opening section : " << endl;
	cout << "Enter your firstname : ";
	cin >> b1[numberOfAccounts].firstName;
	cout << "Enter your family name : ";
	cin >> b1[numberOfAccounts].familyName;
	b1[numberOfAccounts].accountBalance = GetValidInput<double>("Enter the money to be deposited(Must be atleast 100 dollars) : ", "Invalid Input!!! Enter amount in digits only(Must be atleast 100 dollars) : ", 100, 100000);
	b1[numberOfAccounts].accountNumber = 10000+numberOfAccounts;
	cout << "CONGRATULATIONS!! YOUR ACCOUNT HAS BEEN CREATED."<<endl;

	if (numberOfAccounts != 0) {
		int count = 0;
		for (int i = 10000; i <= 10099; i++) {
			for (int j = 0; j < numberOfAccounts; j++) {
				if (i == b1[j].accountNumber) {
					count++;
				}
			}
			if (count == 0) {
				b1[numberOfAccounts].accountNumber = i;
				break;
			}
			count = 0;
		}
	}
	else
	{
		b1[numberOfAccounts].accountNumber = 10000;
	}
	cout << "Your account number is: " << b1[numberOfAccounts].accountNumber;
	numberOfAccounts++;
}

void removeAccount(bankDetails b1[])//function to add an account
{
	long accNum;
	cout << endl << "Welcome to account removal section : " << endl;
	cout << "Enter your account number : ";
	cin >> accNum;
	for (int i = 0; i <= numberOfAccounts; i++)
	{
		if (b1[i].accountNumber == accNum)
		{
			for (int j = i; j <= numberOfAccounts; j++)
			{
				b1[i].firstName = b1[i + 1].firstName;
				b1[i].familyName = b1[i + 1].familyName;
				b1[i].accountNumber = b1[i + 1].accountNumber;
				b1[i].accountBalance = b1[i + 1].accountBalance;
			}
		}
	}
	for (int i = 0; i < numberOfAccounts; i++)
	{
		cout << "*****"<<b1[i].firstName<<"*********";
	}
	numberOfAccounts--;
}

void depositMoney(bankDetails b1[])//function to deposit an amount
{
	double amount;
	long accNum;
	cout << endl << "Welcome to deposit section : " << endl;
	cout << "Enter your account number : ";
	cin >> accNum;
	cout << "Enter the amount to deposit : ";
	cin >> amount;
	int index = indexNum(b1, accNum);
    b1[index].accountBalance += amount;
	cout << "Your Current balance is : " << b1[index].accountBalance;
	for (int i = 0; i < numberOfAccounts; i++)
	{
		cout << "*****" << b1[i].accountBalance << "*********";
	}
}

void withdrawMoney(bankDetails b1[])//function for withdrawing an amount
{
	double amount;
	long accNum;
	cout << endl << "Welcome to withdrawal section : " << endl;
	accNum = GetValidInput<long>("Enter your account number : ", "Invalid Input!!! Enter amount in digits only(Must be atleast 100 dollars) : ", 10000, 10099);
	amount = GetValidInput<double>("Enter the amount to withdraw : ", "Invalid Input!!! Enter amount in digits only(Must be atleast 100 dollars) : ", 100, 100000);
	int index = indexNum(b1, accNum);
	b1[index].accountBalance -= amount;
	cout << "Your Current balance is : " << b1[index].accountBalance;
	for (int i = 0; i < numberOfAccounts; i++)
	{
		cout << "*****" << b1[i].accountBalance << "*********";
	}
}

double displayTotalBalance(bankDetails b1[])
{
	double totalBalance=0.0;
	for (int i = 0; i < numberOfAccounts; i++)
	{
		totalBalance = totalBalance + b1[i].accountBalance;
	}
	return totalBalance;
}

double displayAverageBalance(bankDetails b1[])
{
	double averageBalance = displayTotalBalance(b1) / numberOfAccounts;
	return averageBalance;
}

void showAccountInfo(bankDetails b1[])
{
	long accNum;
	cout << endl << "Welcome to display section : " << endl;
	cout << "Enter your account number : ";
	cin >> accNum;
	int index = indexNum(b1, accNum);
	cout << "First Name : " << b1[index].firstName;
	cout << "Family Name : " << b1[index].familyName;
	cout << "Your Current balance is : " << b1[index].accountBalance;
}

void displayListDescending(bankDetails b1[])
{
	int choice;
	cout << " 1 : Display according to balance" << endl << " 2 : Display according to first name" << endl << " 3 : Display according to family name";
	choice = GetValidInput<int>("Enter your choice : ", "Invalid Input!!! Enter your choice in terms of digits from 1 to 3 only: ", 1, 3);
	if (choice == 1)
	{
		for (int i = 0; i < numberOfAccounts; i++)
		{
			for (int j = i + 1; j < numberOfAccounts; j++)
			{
				if (b1[j].accountBalance > b1[i].accountBalance)
				{
				 swapArray(b1, i, j);
				}
			}
		}
	}
	else if(choice==2)
	{
		for (int i = 0; i < numberOfAccounts; i++)
		{
			for (int j = i + 1; j < numberOfAccounts; j++)
			{
				if (b1[j].firstName .compare(b1[i].firstName)>0)
				{
					swapArray(b1, i, j);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < numberOfAccounts; i++)
		{
			for (int j = i + 1; j < numberOfAccounts; j++)
			{
				if (b1[j].familyName.compare(b1[i].familyName) > 0)
				{
					swapArray(b1, i, j);
				}
			}
		}
	}
	for (int i = 0; i < numberOfAccounts; i++)
	{
		cout << b1[i].accountBalance<<" ";
		cout<< b1[i].firstName << " ";
		cout<< b1[i].familyName << " "<<endl;
	}
}

void displayListAscending(bankDetails b1[])
{
	int choice;
	cout << " 1 : Display according to balance" << endl << " 2 : Display according to first name" << endl << " 3 : Display according to family name";
	choice = GetValidInput<int>("Enter your choice : ", "Invalid Input!!! Enter your choice in terms of digits from 1 to 3 only: ", 1, 3);
	if (choice == 1)
	{
		for (int i = 0; i < numberOfAccounts; i++)
		{
			for (int j = i + 1; j < numberOfAccounts; j++)
			{
				if (b1[j].accountBalance < b1[i].accountBalance)
				{
					swapArray(b1, i, j);
				}
			}
		}
	}
	else if (choice == 2)
	{
		for (int i = 0; i < numberOfAccounts; i++)
		{
			for (int j = i + 1; j < numberOfAccounts; j++)
			{
				if (b1[j].firstName.compare(b1[i].firstName) < 0)
				{
					swapArray(b1, i, j);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < numberOfAccounts; i++)
		{
			for (int j = i + 1; j < numberOfAccounts; j++)
			{
				if (b1[j].familyName.compare(b1[i].familyName) < 0)
				{
					swapArray(b1, i, j);
				}
			}
		}
	}
	for (int i = 0; i < numberOfAccounts; i++)
	{
		cout << b1[i].accountBalance << " ";
		cout << b1[i].firstName << " ";
		cout << b1[i].familyName << " " << endl;
	}
}

void swapArray(bankDetails b[], int i, int j) {
	bankDetails temp;
	temp = b[j];
	b[j] = b[i];
	b[i] = temp;
}

int indexNum(bankDetails b[], long accNumber) {
	for (int i = 0; i <= numberOfAccounts; i++)
	{
		if (b[i].accountNumber == accNumber)
		{
			return i;
		}
	}
}

