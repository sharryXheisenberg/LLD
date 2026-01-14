/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


// sub class methods should not be allowed state changes which are following by base class


class BankAccount{
protected:
    double balance;

public:
    BankAccount(double b){
        if(b<0) throw invalid_argument("Balance can't be negative");
        balance=b;
    }
    virtual void withdraw(double amount){
        if(amount>balance) throw runtime_error("Insufficient funds");
        balance-=amount;
        cout<<"Amount withdrawn. Remaining balance is "<<balance<<endl;
    }

};

class FixedDepositAccount:public BankAccount{
public:
    FixedDepositAccount(double b): BankAccount(b) {}

    // here LSP breaks because it doesn't follows the parent class rule which is withdraw
    // and also 'History constraint' gets breaks
    void withdraw(double amount) override{
        throw runtime_error("Withdraw not allowed in Fixed deposit account");
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BankAccount* b1 = new BankAccount(100);
    FixedDepositAccount* f1 =new FixedDepositAccount(200);
    // b1->withdraw(200);
    f1->withdraw(100);
}