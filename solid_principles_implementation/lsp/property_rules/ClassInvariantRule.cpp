/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;



//  class invariant rule says that - A parent object should not be broken by child class object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down

//  or in simple words if parent class following some invariant (i.e rule) then child class of that base class should also follows the same rule and it should not be break otherwise the Liskov substitution principle get's breaks

// Invariant : Balance cannot be negative

class BankAccount{
protected:
    double balance;

public:
    BankAccount(double b){
        if(b<0) throw invalid_argument("Balance can't be negative");
        balance=b;
    }
    virtual void withdraw(double amount){
        if(amount>balance) throw runtime_error("Insufficient balance");
        balance-=amount;
        cout<<"Amount withdrawn . New balance is: $ "<<balance<<endl;
    }

};

//  Brakes Invariant: should not be allowed 
class InvariantBreakingClass: public BankAccount{
public:
    InvariantBreakingClass(double b) : BankAccount(b){}

    void withdraw(double amount) override{
        balance-=amount;  // lsp breaks here negative amount is not allowed 
        cout<<"Amount withdrawn. Remainig balance is $ "<<balance<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BankAccount* b1 = new BankAccount(100);
    b1->withdraw(200);
    BankAccount* b2 = new InvariantBreakingClass(200);
    b2->withdraw(300);

    return 0;
}