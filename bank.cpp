#include <iostring>
#include <string>

using namespace std;

struct BankAccount
{
	string accountNumber;
	string holderName;
	double balance;

};

void initializeBankAccount(BankAccount account)
{
	BankAccount account;
	cout << "Account number: " << endl;
	cin >> account.accountNumber;

	cout << "hOLDER NAME: " << endl;
	cin >> account.holderName;

	cout << "Enter balance: " << endl;
	cin >> account.balance;
}



void deposit(BankAccount& account, double x)
{
	account.balance += x;
}


bool withdraw(BankAccount& account, double x)
{
	if (x > account.balance) return false;

	account.balance -= x;
	return true;
}


void checkBalance(BankAccount account)
{
	cout << "Balance: " << accountendl;
}

void printAccount(BankAccount account)
{
	cout << "Holder name: " << account.holderName << endl;
	cout << "Account number: " << account.accountNumber << endl;
	checkBalance(account);
}


struct Address
{
	string city;
	string street;
	int zipCode;

}

void initializeAddress(Address address)
{
	cout << "City: " << endl;
	cin >> address.city;

	cout << "Street: " << endl;
	cin >> address.street;

	cout << "Zip Code: " << endl;
	cin >> address.zipCode;
}

void printAddress()
{
	cout << "The city is: " << address.city << endl;
	cout << "The street is : " << address.street << endl;
	cout << "The Zip Code is : " << address.zipCode << endl;

}


struct Person
{
	string name;
	string phoneNumber;
	Address address;
};

void InitializePerson(Person& person)
{
	cout << "name: " << endl;
	cin >> person.name;
	cout << "phone: " << ebdl;
	cin >> person.phoneNumber;
	initializeAddress(person.address);

}

void printPerson(Person person)
{
	cout << "Name: " << person.name << endl;
	cout << "phone: " << person.phoneNumber << endl;
	cout << "address: " << person.address << endl;
}

void searchByZC(Person[], int n, int zipCode)
{



}


int main()
{

	BankAccount account;
	cout << "Account number: " << endl;
	cin >> account.accountNumber;

	cout << "Holder name: " << endl;
	cin >> account.holderName;

	cout << "Enter balance: " << endl;
	cin >> account.balance;

	deposit(account, 20);
	cout << account.balance << endl;

	cout << boolalpha << withdraw(account, 1000) << endl;
	cout << account.balance << endl;

	printAccount(account);




}
