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

class stock {
private:
    int p, s, j, total;
    float discount, value;

public:
    
    static void Name() {
        cout << "Welcome to BELLZ Clothing Store!" << endl;
    }
    stock() {
        p = s = j = total = 0;
        discount = value = 0.0;
    }

    stock(int pants, int shirts, int jackets) {
        p = pants;
        s = shirts;
        j = jackets;
        total = (p * 500) + (s * 300) + (j * 1000);
        discount = value = 0.0;
    }

    stock(const stock &obj) {
        p = obj.p;
        s = obj.s;
        j = obj.j;
        total = obj.total;
        discount = obj.discount;
        value = obj.value;
    }

    stock operator+(stock &obj) {
        stock temp;
        temp.p = this->p + obj.p;
        temp.s = this->s + obj.s;
        temp.j = this->j + obj.j;
        temp.total = this->total + obj.total;

        if (temp.total >= 2000) {
            temp.value = temp.total * 0.02;
            temp.discount = temp.total - temp.value;
        } else {
            temp.discount = temp.total;
        }
        return temp;
    }

    void input();
    void cash();
    void upi();
    void bank();
    void card();
    void delivery(string date = "23-07-2025", int days = 5, string method = "standard");
    friend void bonus(stock s);
};

void stock::input() {
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
    cin >> p;
    cout << "Enter the no. of shirts: ";
    cin >> s;
    cout << "Enter the no. of jackets: ";
    cin >> j;

    total = (p * 500) + (s * 300) + (j * 1000);

    cout << "Total amount: " << total << "\n";

    if (total >= 2000) {
        value = total * 0.02;
        discount = total - value;
        cout << "Final amount after discount = " << discount << "\n";
    } else {
        cout << "No discount applied.\n";
        discount = total;
        cout << "Final amount = " << total << "\n";
    }

    bonus(*this);
    cout << "Enter method of payment:\n";
}

void stock::cash() {
    int pay;
    cout << "Enter the amount: ";
    cin >> pay;
    cout << "Amount paid successfully.\n";
    cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
}

void stock::upi() {
    string id;
    cout << "Enter UPI Id: ";
    cin >> id;
    cout << "Amount: " << discount << "\n";
    cout << "Amount paid successfully.\n";
    cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    delivery();
}

void stock::bank() {
    long acc;
    cout << "Enter the bank account number: ";
    cin >> acc;
    cout << "Amount: " << discount << "\n";
    cout << "Amount paid successfully.\n";
    cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    delivery();
}

void stock::card() {
    long no;
    cout << "Enter the card number: ";
    cin >> no;
    cout << "Amount: " << discount << "\n";
    cout << "Amount paid successfully.\n";
    cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    delivery();
}

void stock::delivery(string date, int days, string method) {
    cout << "\n------- BILL -------";
    cout << "\nDelivery Date: " << date;
    cout << "\nExpected Delivery in: " << days << " days";
    cout << "\nDelivery Method: " << method;
    cout << "\nPants: " << p;
    cout << "\nShirts: " << s;
    cout << "\nJackets: " << j;
    cout << "\nTotal Amount: " << total;
    if (total >= 2000)
        cout << "\nDiscounted Total: " << discount;
    cout << "\n----------------------------\n";
}

void bonus(stock s) {
    int bonusPoints = (s.total / 500) * 10;
    cout << "\nBONUS POINTS EARNED!!!!!: " << bonusPoints << " points";
    cout << "\n(You earn 10 points for every 500 spent)";
    cout << "\n----------------------------\n";
}

int main() {
    stock order1, order2;
    cout << "Enter details for first order:\n";
    order1.input();

    cout << "\nEnter details for second order:\n";
    order2.input();

    stock combined = order1 + order2;

    cout << "\nAfter combining both orders:";
    combined.delivery();

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
            combined.cash();
            break;
        case 2:
            combined.upi();
            break;
        case 3:
            combined.bank();
            break;
        case 4:
            combined.card();
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

