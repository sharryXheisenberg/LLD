/* 
 * Author - Balerion_The_second
 */


#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


// product class representing any item from the E-commerce 
class Product{
    public:
    string name;
    double price;

    Product(string name , double price){
        this->name = name;
        this->price = price;
    }
};

// here is an example how ShoppingCart is violating the SRP 

class ShoppingCart{
    private:
    vector<Product*>products;

    public:
         ~ShoppingCart(){
            for(auto p : products) delete p;
            products.clear();
        }

        void addProduct(Product* p){
            products.push_back(p);
        }
        const vector<Product*>& getProducts(){
            return products;
        }


        // 1. calculate total price in cart

        double calculateTotal(){
            double totoal = 0;
            for(auto p:products){
                totoal+=p->price;
            }
            return totoal;
        }

        void printInvoice(){
            cout<<"Shopping Invoice\n";
            for(auto p : products){
                cout<<p->name<< "- $"<<p->price<<en;
            }
            cout<<"Total: $" <<calculateTotal()<<en;
        }

        void saveDataBase(){
            cout<<"Saving shopping cart to database"<<en;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",15000));
    cart->addProduct(new Product("Mouse",50));

    cart->printInvoice();
    cart->calculateTotal();
    cart->saveDataBase();
}