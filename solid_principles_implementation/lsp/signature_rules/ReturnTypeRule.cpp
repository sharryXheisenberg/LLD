/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */


#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


// Return type rule:
// Subtype overriden methods returns type should be either identical or narrower than the parent methods return type
//  this is also called as return type Covariance

class Animal{
    //  some methods
};

class Dog:public Animal{
    // Additional Dog methods specific to Dogs 
};


class Parent{
public:
    virtual Animal* getAnimal(){
        cout<<"Parent: returning Animal instance"<<en;
        return new Animal();   // returning the reference of class of Parent type 
    }
};

class Child : public Parent{
public:
    Animal* getAnimal() override{
        cout<<"Child : Returning Dog instance"<<endl;
        return new Dog();
    }
};

class Client{
private:
    Parent* p;

public:
    Client(Parent* p){
        this->p=p;
    }
    void takeAnimal(){
        p->getAnimal();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Parent* parent1 = new Parent();
    Child* ch1 = new Child();

    Client* cl = new Client(ch1);
    cl->takeAnimal();
    
    return 0;
}