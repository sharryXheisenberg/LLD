/* 
 * Author - Balerion_The_second
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


class DepositOnlyAccount{
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount: public DepositOnlyAccount{   //this account automatically gets the deposit feature
public:  
    virtual void withdraw(double amount) = 0;
};

class SavingAccount:public WithdrawableAccount{
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

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawl " << amount << " from savings account . New balance "<<balance<<endl;
        }else{
            cout<<"Insufficient funds / balance in Savings Account\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount{
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

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Withdrawl " << amount << " from savings account . New balance "<<balance<<endl;
        }else{
            cout<<"Insufficient funds / balance in Savings Account\n";
        }
    }
};

class FixedTermAccount: public DepositOnlyAccount{
private:
    double balance;

public:
    FixedTermAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited "<<amount << " in Fixed Term account. New Balance: "<<balance<<endl;
    }
};

class BankClient{
private:
    vector<WithdrawableAccount*>withdrawableAccounts;
    vector<DepositOnlyAccount*>depositOnlyAccounts;

public:
    BankClient(vector<WithdrawableAccount*>withdrawableAccounts , vector<DepositOnlyAccount*>depositOnlyAccounts){
        this->withdrawableAccounts= withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }
    
    void processTransactions(){
        for(WithdrawableAccount* acc:withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(DepositOnlyAccount* acc:depositOnlyAccounts){
            acc->deposit(5000);
        }
    }
};

int main(){
    vector<WithdrawableAccount*>withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(withdrawableAccounts,depositOnlyAccounts);
    client->processTransactions();
    return 0;

}