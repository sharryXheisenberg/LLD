/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;

// Exception rules
// A subclass should throw fewer or narrower exception
// but not additional or broader exception) than the parent

/*
std:logic_error    (this is one of subtype of errors/exception class in c++)
->invalid_argument
->domain_error
->length_error
->out_of_range


std:runtime_error  (this is another type of exception/error class in C++)
->range_error
->overflow_error
->underflow_error
*/


class Parent{
public:
    virtual void getValue() noexcept(false){
        throw logic_error("Parent error");
    }
};

class Child:public Parent{
public:
    void getValue() noexcept(false) override{   // here child is throwing the subclass(out_of_range) of logic_error parent class which is fine but it should not return sub class of runtime_error class or throw runtime error  
        throw out_of_range("Child error");
    }
};

class Client{
private:
    Parent* p;

public:
    Client(Parent* p){
        this->p=p;
    }
    void takeValue(){
        try{
            p->getValue();
        }catch(const logic_error& e){
            cout<<"Logic error exception occured "<<e.what()<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Parent* p1 = new Parent();
    Child* ch1 = new Child();
    Client* cl1 = new Client(ch1);
    cl1->takeValue();
    return 0;
}