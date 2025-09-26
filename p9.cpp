#include <iostream>
#include <string>
using namespace std;


class Product {
public:
    string name;
    int price;

    void setData(string n, int p) {
        name = n;
        price = p;
    }

    void display() {
        cout << "- " << name << " : " << price << "\n";
    }
};

class Payment {
protected:
    float discount;
public:
    void setDiscount(float d) { discount = d; }
    float getDiscount() { return discount; }

    void cash() {
        int pay;
        cout << "Enter the amount: ";
        cin >> pay;
        cout << "Amount paid successfully.\n";
        cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    }

    void upi() {
        string id;
        cout << "Enter UPI Id: ";
        cin >> id;
        cout << "Amount: " << discount << "\n";
        cout << "Amount paid successfully.\n";
        cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    }

    void bank() {
        long acc;
        cout << "Enter the bank account number: ";
        cin >> acc;
        cout << "Amount: " << discount << "\n";
        cout << "Amount paid successfully.\n";
        cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    }

    void card() {
        long no;
        cout << "Enter the card number: ";
        cin >> no;
        cout << "Amount: " << discount << "\n";
        cout << "Amount paid successfully.\n";
        cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    }
};

class Delivery {
protected:
    int p, s, j;
    int total;
public:
    void setItems(int pants, int shirts, int jackets, int tot) {
        p = pants;
        s = shirts;
        j = jackets;
        total = tot;
    }

    void delivery(string date = "23-07-2025", int days = 5, string method = "standard") {
        cout << "\n------- BILL -------";
        cout << "\nDelivery Date: " << date;
        cout << "\nExpected Delivery in: " << days << " days";
        cout << "\nDelivery Method: " << method;
        cout << "\nPants: " << p;
        cout << "\nShirts: " << s;
        cout << "\nJackets: " << j;
        cout << "\nTotal Amount: " << total;
        if (total >= 2000)
            cout << "\nDiscounted Total: " << total * 0.02; 
        cout << "\n----------------------------\n";
    }
};

class bill : public Payment, public Delivery {
private:
    int pants, shirts, jackets;
    int totalAmount;
public:
    static void Name() {
        cout << "Welcome to BELLZ Clothing Store!" << endl;
    }

    stock() {
        pants = shirts = jackets = totalAmount = 0;
        discount = 0.0;
    }

    void input() {
        Product catalog[3];
        catalog[0].setData("Pant", 500);
        catalog[1].setData("Shirt", 300);
        catalog[2].setData("Jacket", 1000);

        cout << "****BELLZ****\n";
        cout << "---Welcome To BELLZ---\n";
        cout << "Our Products:\n";
        for (int i = 0; i < 3; i++) {
            catalog[i].display();
        }

        cout << "\nEnter the no. of pants: ";
        cin >> pants;
        cout << "Enter the no. of shirts: ";
        cin >> shirts;
        cout << "Enter the no. of jackets: ";
        cin >> jackets;

        totalAmount = (pants * 500) + (shirts * 300) + (jackets * 1000);

        if (totalAmount >= 2000) {
            discount = totalAmount * 0.02; 
            cout << "Total amount: " << totalAmount << "\n";
            cout << "Final amount after discount = " << discount << "\n";
        } else {
            discount = totalAmount;
            cout << "Total amount: " << totalAmount << "\n";
            cout << "No discount applied.\n";
            cout << "Final amount = " << totalAmount << "\n";
        }

        bonus(*this);
        cout << "Enter method of payment:\n";

        
        setItems(pants, shirts, jackets, totalAmount);
    }

    friend void bonus(bill s);
};

void bonus(bill s) {
    int bonusPoints = (s.totalAmount / 500) * 10;
    cout << "\nBONUS POINTS EARNED!!!!!: " << bonusPoints << " points";
    cout << "\n(You earn 10 points for every 500 spent)";
    cout << "\n----------------------------\n";
}

int main() {
    bill amount;
    amount.input();
    

    int choice;
    do {
        cout << "\n----- Methods of Payment -----";
        cout << "\n1. Cash";
        cout << "\n2. UPI";
        cout << "\n3. Bank Account";
        cout << "\n4. Card";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            amount.cash();
            amount.delivery();
            break;
        case 2:
            amount.upi();
            amount.delivery();
            break;
        case 3:
            amount.bank();
            amount.delivery();
            break;
        case 4:
            amount.card();
            amount.delivery();
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

