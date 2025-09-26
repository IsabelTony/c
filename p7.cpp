#include <iostream>
#include <string>
using namespace std;

class Bellz {
    string name;
    int price;
    string size;

public:
    Bellz(string n, int p, string s) : name(n), price(p), size(s) {}

    Bellz operator-() {
        Bellz discounted = *this;
        discounted.price -= 500; 
        return discounted;
    }

    void display() {
        cout << "Product: " << name
             << " | Price: " << price
             << " | Size: " << size << endl;
    }
};

int main() {
    Bellz item("Dress", 4500, "Medium");

    cout << "total:\n";
    item.display();

    cout << "\nAfter applying discount:\n";
    Bellz discount = -item; 
    discount.display();

    return 0;
}
