// Open-close principle
// A class should be open for extension but close for modification
// this implementation follows both SRP and OCP
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
            cout<<p->name<<" "<<p->price<<"$ "<<en;
        }
        cout<<"Total price: $"<<cart->calculateTotal()<<en;
    }
};

class Persistance{
private:
    ShoppingCart* cart;

public:
    virtual void save(ShoppingCart* cart) = 0;   // this is a pure virtual function 
};

class SQLPersistance : public Persistance{
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to SQL DB.."<<en;
    }
};

class MongoPersistance: public Persistance{
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to MongoDB .."<<en;
    }
};

class FilePersistance: public Persistance{
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to a file.."<<en;
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

    Persistance* sql = new SQLPersistance();
    Persistance* mongo = new MongoPersistance();
    Persistance* file = new FilePersistance();

    sql->save(cart);
    mongo->save(cart);
    file->save(cart);

    return 0;

}