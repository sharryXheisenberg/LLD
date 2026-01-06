/* 
 * Author - Balerion_The_second
 */


#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;

class Account{    // abstract class 
public:
    virtual void deposit(double amount) = 0;   // this is a pure virtual function
    virtual void withdrawl(double amount) = 0;
};

class SavingAccount:public Account{
private:
    double balance;

public:
    SavingAccount(){
        balance = 0;
    }
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Deposited "<<amount<<" in Savings account. New balance "<< balance<<endl;
        }else{
            cout<<"Please do not deposit negative amount "<<endl;
        }
    }

    void withdrawl(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawl " << amount << "from savings account . New balance "<<balance<<endl;
        }else{
            cout<<"Insufficient funds / balance in Savings Account\n";
        }
    }
};
class CurrentAccount:public Account{
private:
    double balance;

public:
    CurrentAccount(){
        balance = 0;
    }
    void deposit(double amount){
        if(amount>0){
            balance+=amount;
            cout<<"Deposited "<<amount<<" in Savings account. New balance "<< balance<<endl;
        }else{
            cout<<"Please do not deposit negative amount "<<endl;
        }
    }

    void withdrawl(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawl " << amount << " from savings account . New balance "<<balance<<endl;
        }else{
            cout<<"Insufficient funds / balance in Savings Account\n";
        }
    }

};

class FixeTermAccountant:public Account{
private:
    double balance;

public:
    FixeTermAccountant(){
        balance = 0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited "<<amount<<" in Fixed Term Deposit Account. New balance "<<balance<<endl;
    }
    void withdrawl(double amount){
        throw logic_error("Withdrawl not allowed in Fixed term account: ");     
    }
};

class BankClient{
private:
    vector<Account*>accounts;

public:
    BankClient(vector<Account*>accounts){
        this->accounts = accounts;
    }
    void processTransaction(){
        for(Account* acc:accounts){
            acc->deposit(1000);

            if(typeid(*acc)== typeid(FixeTermAccountant)){
                cout<<"Skipping withdrawl for Fixed term Account.\n";
            }
            else{
             try{
                acc->withdrawl(500);
            }catch(const logic_error& e){
                cout<<"Exception"<<e.what()<<endl;
             }
            }
            
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixeTermAccountant());

    BankClient* client = new BankClient(accounts);
    client->processTransaction();  // throws the exception when withdrawing from FixedTermAccount
    return 0;
}