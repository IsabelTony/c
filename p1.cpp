#include <iostream>
#include <string>
using namespace std;

class stock
{

clrscr();
private:
    int p, s,total;

public:
    void input();

    
    void cash();
    void upi();
    void bank();
    void card();
};

void stock::input()
{
	cout<<"prices:\n";
	cout<<"pant=500\n";
	cout<<"shirt=300\n";
    cout << "Enter the no. of pants: ";
    cin >> p;
    cout << "Enter the no. of shirts: ";
    cin >> s;
    total=(p*500)+(s*300);
    cout<<"total amount\n";
    cout<<total;
    cout << "\nEnter method of payment:";
}


void stock::cash()
{
    int pay;
    cout << "Enter the amount: ";
    cin >> pay;
    cout << "Amount paid successfully.\n";
}

void stock::upi()
{
    string id;
    int a;
    cout << "Enter UPI Id: ";
    cin >> id;
    cout << "Enter the amount: ";
    cin >> a;
    cout << "Amount paid successfully.\n";
}

void stock::bank()
{
    long acc;
    int c;
    cout << "Enter the bank account number: ";
    cin >> acc;
    cout << "Enter the amount: ";
    cin >> c;
    cout << "Amount paid successfully.\n";
}

void stock::card()
{
    long  no;
    int b;
    cout << "Enter the card number: ";
    cin >> no;
    cout << "Enter the amount: ";
    cin >> b;
    cout << "Amount paid successfully.\n";
}

int main()
{
    stock amount;


    amount.input();

    int choice;
    do
    {
        cout << "\n-----Methods of Payment-----";
        cout << "\n1. Cash";
        cout << "\n2. UPI";
        cout << "\n3. Bank Account";
        cout << "\n4. Card";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            amount.cash();
            break;
        case 2:
            amount.upi();
            break;
        case 3:
            amount.bank();
            break;
        case 4:
            amount.card();
            break;
        case 5:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    
    

    return 0;
    
}



