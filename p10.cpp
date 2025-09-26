#include <iostream>
#include <string>
using namespace std;

class Brand {
public:
    string Name;

    Brand() {
        Name = "Bellz";
    }

    void showBrand() {
        cout << "Brand Name: " << Name << endl;
    }
};


class Category : public Brand {
public:
    string Name;

    void setCategory(string c) {
        Name = c;
    }

    void showCategory() {
        showBrand();
        cout << "Category: " << Name << endl;
    }
};

class Product : public Category {
public:
    string productName;
    int price;

    void setProduct(string p, int pr) {
        productName = p;
        price = pr;
    }

    void showProduct() {
        showCategory();
        cout << "Product: " << productName << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Product p1;

    p1.setCategory("Men's Wear");
    p1.setProduct("Denim Jacket", 2999);

    cout << "=== Product Details ===" << endl;
    p1.showProduct();

    return 0;
}

