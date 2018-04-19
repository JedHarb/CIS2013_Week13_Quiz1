#include <iostream> //mish mash of code from my other quiz program and copying notes from class. Dont expect this to work at all.
#include <string>
using namespace std;
int number = 100;

class BankAccount {
private:
	
	char userInput;
	string name = "default";
	string acct_number;
	string phone;
	// bool accountCreated = false;
	int deposit;
	int withdraw;
	int balance = 0;
	float rate;

public:

	void deposit(int x) {
		balance += x;
	}

	void withdraw(int x) {
		balance -= x;
	}
	
	int getBalance() {
		return balance;
	}

};

class savings : public BankAccount {
private:
	int minimum_balance = 200;
	int withdraw_limit;

public:
	savings(string n, string p) {
		rate = 5.0; // these are giving an error (squigly red underline) that the member (up above) is inaccessible. This changes when the above variables are put in "public"
		name = "n";
		phone = p;
		acct_number = number++;
		balance = 0;
	}

	bool underMin() {
		if (balance < minimum_balance) {
			return true;
		}
		else {
			return false;
		}
	}

	//bool overLimit() {
	//	if (BankAccount.withdraw > withdraw_limit) {
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}
};

class checking : public BankAccount {
	int overdraft_fee;

	bool checkOverdraft() {
		if (balance < 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	BankAccount B;
	savings S;
	checking C;
	bool keepAlive = true;
	char userInput;

	while (keepAlive == true) {
		cout << endl << "Welcome to 'Not-A-Scam' bank!" << endl << "Please choose checking (c) or savings (s) account, or exit (x) the program: ";
		cin >> userInput;
		cout << endl;

		if (userInput == 'x') {
			keepAlive = false;
		}
		//else if (userInput == 's') {
		//	S.getInput('m');
		//	cin >> userInput;
		//	S.getInput(userInput);
		//}
		//else if (userInput == 'c') {
		//	C.getInput('m');
		//	cin >> userInput;
		//	C.getInput(userInput);
		//}
		else {
			cout << "Sorry, I didn't get that." << endl;
		}
	}

	return 0;
}


//void getInput(char input) {
//	switch (input) {
//	case 'a':
//		cout << "Please name your account (no spaces): ";
//		cin >> name;
//		cout << "Please provide a phone number (numbers only): ";
//		cin >> phone;
//		cout << "What is the account number?: ";
//		cin >> acct_number;
//		accountCreated = true;
//		break;
//	case 'd':
//		if (accountCreated == true) {
//			cout << "Amount to deposit (numbers only): ";
//			cin >> deposit;
//			balance += deposit;
//			cout << "You now have " << balance << " dollars." << endl;
//		}
//		else {
//			cout << "You don't have an account here." << endl;
//		}
//		break;
//	case 'w':
//		if (accountCreated == true) {
//			cout << "Choose amount to withdraw: ";
//			cin >> withdraw;
//			balance -= withdraw;
//			cout << "You now have " << balance << " dollars." << endl;
//		}
//		else {
//			cout << "You don't have an account here." << endl;
//		}
//		break;
//	case 'p':
//		if (accountCreated == true) {
//			cout << "Your account, " << name << " (" << acct_number << "), has " << balance << " dollars." << endl;
//		}
//		else {
//			cout << "You don't have an account here." << endl;
//		}
//		break;
//	case 'm':
//		cout << "Menu: " << endl << "Create account (a)" << endl << "Deposit to account (d)" << endl << "Withdraw from account (w)" << endl << "Print totals (p)" << endl << "Show this menu again (m)" << endl << "Please make a selection: ";
//		break;
//	default:
//		cout << "Sorry, I didn't get that." << endl;
//	}