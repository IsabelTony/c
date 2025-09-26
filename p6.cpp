#include <iostream>
#include <string>
using namespace std;

class Bellz {
public:
    void product(string name) {
        cout << "Product: " << name << endl;
    }

    void product(string name, int price) {
        cout << "Product: " << name << " | Price: " << price << endl;
    }
    void product(string name, int price, string size) {
        cout << "Product: " << name 
             << " | Price: " << price 
             << " | Size: " << size << endl;
    }
};

int main() {
    Bellz s;

    s.product("T-Shirt",1000);                       
    s.product("Jeans", 2500);                   
    s.product("Dress", 4500, "Medium");         

    return 0;
}

