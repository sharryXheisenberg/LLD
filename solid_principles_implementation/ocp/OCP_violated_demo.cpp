// Open-close principle
// A class should be open for extension but close for modification
// this is SRP followed but OCP violated implementation

/* 
 * Author - Balerion_The_second
 */


#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


class Product{
public:
    string name;
    double price;

    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};


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
        cout<<"List and invoice:\n";
        for(auto p:cart->getProducts()){
            cout<<p->name<<"$."<<p->price<<""<<en;
        }
        cout<<"Total price "<<cart->calculateTotal()<<en;
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToSQLDatabase(){
        cout<<"Saving shopping cart to SQL DB.."<<en;
    }
    void saveToFile(){
       cout<<"Saving shopping cart to File storage"<<en; 
    }
    void saveToMongoDB(){
        cout<<"Saving shopping cart to MongoDB"<<en;
    }
    
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1323.12));
    cart->addProduct(new Product("Mouse",232.3));
    cart->addProduct(new Product("Speakers", 232432.32));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    cout<<"\n";

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->saveToSQLDatabase();
    return 0;

}