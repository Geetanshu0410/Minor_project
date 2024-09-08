#include <iostream>
#include <string>
using namespace std;

// Struct to represent an account in the linked list
struct Account {
    string accountName;
    int accountNumber;
    string accountType;
    double balance;
    Account* next; // Pointer to the next account

    // Constructor for easier account creation
    Account(string name, int number, string type, double bal) {
        accountName = name;
        accountNumber = number;
        accountType = type;
        balance = bal;
        next = nullptr;
    }
};

// Class for managing the ATM system
class ATM {
private:
    Account* head; // Head pointer for the linked list of accounts

public:
    ATM() {
        head = nullptr;
    }

    // Function to add a new account
    void addAccount() {
        string name, type;
        int number;
        double balance;

        cout << "Enter Account Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> number;
        cout << "Enter Account Type (Savings/Current): ";
        cin >> type;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        Account* newAccount = new Account(name, number, type, balance);

        // Insert the new account at the beginning of the list
        newAccount->next = head;
        head = newAccount;

        cout << "Account added successfully!\n";
    }

    // Function to display account details
    void displayAccounts() {
        if (head == nullptr) {
            cout << "No accounts available.\n";
            return;
        }

        Account* temp = head;
        while (temp != nullptr) {
            cout << "-------------------------\n";
            cout << "Account Name: " << temp->accountName << endl;
            cout << "Account Number: " << temp->accountNumber << endl;
            cout << "Account Type: " << temp->accountType << endl;
            cout << "Balance: " << temp->balance << endl;
            temp = temp->next;
        }
    }

    // Function to search for an account by account number
    void searchAccount() {
        if (head == nullptr) {
            cout << "No accounts available.\n";
            return;
        }

        int number;
        cout << "Enter Account Number to search: ";
        cin >> number;

        Account* temp = head;
        while (temp != nullptr) {
            if (temp->accountNumber == number) {
                cout << "Account found!\n";
                cout << "Account Name: " << temp->accountName << endl;
                cout << "Account Number: " << temp->accountNumber << endl;
                cout << "Account Type: " << temp->accountType << endl;
                cout << "Balance: " << temp->balance << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Account not found.\n";
    }

    // Function to display the menu and handle user input
    void menu() {
        int choice;
        do {
            cout << "\n=== ATM System ===\n";
            cout << "1. Add Account\n";
            cout << "2. Display Accounts\n";
            cout << "3. Search Account\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addAccount();
                    break;
                case 2:
                    displayAccounts();
                    break;
                case 3:
                    searchAccount();
                    break;
                case 4:
                    cout << "Exiting system. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    ATM atmSystem;
    atmSystem.menu();
    return 0;
}
