#include <iostream>
#include <string>
using namespace std;
#define BRIGHT_PURPLE  "\033[95m"

// ------------------- Program 1 -------------------
class Product {
public:
    string name;
    int price;

    void setData(string n, int p) {
        name = n;
        price = p;
    }

    void display() {
        cout<< "- " << name << " : " << price << "\n";
    }
};

class stock {
private:
    int p, s,j, total;
    float discount, value;

public:
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
    cout<<"enter the no.of jackets: ";
    cin>> j;

    total = (p * 500) + (s * 300)+ (j*1000);

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
    int a;
    cout << "Enter UPI Id: ";
    cin >> id;
    cout << "amount: " << discount << "\n";
    cout << "Amount paid successfully.\n";
    cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    delivery();
}

void stock::bank() {
    long acc;
    int c;
    cout << "Enter the bank account number: ";
    cin >> acc;
    cout << "amount: " << discount << "\n";
    cout << "Amount paid successfully.\n";
    cout << "____THANK YOU FOR SHOPPING WITH BELLZ___\n";
    delivery();
}

void stock::card() {
    long no;
    int b;
    cout << "Enter the card number: ";
    cin >> no;
    cout << "amount: " << discount << "\n";
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

// ------------------- Program 2 -------------------
class Brand {
protected:
    string brandName;
public:
    Brand(string name) {
        brandName = name;
    }
    void showBrand() {
        cout << "Brand Name: " << brandName << endl;
    }
};

class Product2 {
protected:
    string category;
    int price;
public:
    Product2(string cat, int p) {
        category = cat;
        price = p;
    }
    void showProduct() {
        cout << "Product Category: " << category << endl;
        cout << "Price: " << price << endl;
    }
};

class Bellzz : public Brand, public Product2 {
public:
    Bellzz(string b, string c, int p) : Brand(b), Product2(c, p) {}

    void display() {
        cout << "=== Clothing Brand Details ===" << endl;
        showBrand();      
        showProduct();    
        cout << "Tagline: Wear the trend with Bellzz!" << endl;
    }
};

// ------------------- Main -------------------
int main() {
    // Run Program 1
    stock amount;
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

    // Run Program 2
    Bellzz item("BELLZZ", "T-Shirt", 1200);
    item.display();

    return 0;
}

