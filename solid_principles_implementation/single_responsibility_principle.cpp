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

// class ShoppingCart{
//     private:
//     vector<Product*>products;

//     public:
//          ~ShoppingCart(){
//             for(auto p : products) delete p;
//             products.clear();
//         }

//         void addProduct(Product* p){
//             products.push_back(p);
//         }
//         const vector<Product*>& getProducts(){
//             return products;
//         }


//         // 1. calculate total price in cart

//         double calculateTotal(){
//             double totoal = 0;
//             for(auto p:products){
//                 totoal+=p->price;
//             }
//             return totoal;
//         }

//         void printInvoice(){
//             cout<<"Shopping Invoice\n";
//             for(auto p : products){
//                 cout<<p->name<< "- $"<<p->price<<en;
//             }
//             cout<<"Total: $" <<calculateTotal()<<en;
//         }

//         void saveDataBase(){
//             cout<<"Saving shopping cart to database"<<en;
//         }
// };


// here is an exmaple where we are following the SRP
class ShoppingCart{
private:
    vector<Product*>products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotal(){
        double total = 0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
private:
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"Shopping cart Invoice:\n";
        for(auto p:cart->getProducts()){
            cout<<p->name<<" - $ "<<p->price<<en;
        }
        cout<<"Total: $"<< cart->calculateTotal()<<en;
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }
    void saveToDatabase(){
        cout<<"Saving shopping cart to Database"<<en;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",15000));
    cart->addProduct(new Product("Mouse",50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToDatabase();
    return 0;
}