/* 
 * Author - Balerion_The_second
 */


#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;



class CustomerAccount{
    public:
    string name;
    double balance;

    CustomerAccount(string name , double balance){
        this->name = name;
        if(balance>0){
            this->balance = balance;
        }
    }

};

class BankSystem{
private:
    vector<CustomerAccount*>accounts;

public:
    void addCustomers(CustomerAccount* c){
        accounts.push_back(c);
    }

    const vector<CustomerAccount*>& getAccounts(){
        return accounts;
    }

    double calculateTotalBalance(){
        double total = 0;
        for(auto t:accounts){
            total+=t->balance;
        }
        return total;
    }
};

class PrintBankBalance{
private:
    BankSystem* acc;

public:
    PrintBankBalance(BankSystem* acc){
        this->acc = acc;
    }

    void printBankBalance(){
        cout<<"Printing the balance"<<en;
        for(auto l:acc->getAccounts()){
            cout<<l->name<<" "<<l->balance<<" $"<<en;
        }
        cout<<"Total balance - $"<<acc->calculateTotalBalance()<<en;
    }
};

class StoreCustomerDataInDatabase{
private:
    BankSystem* acc;

public:
    StoreCustomerDataInDatabase(BankSystem* acc){
        this->acc = acc;
    }
    void storingData(){
        cout<<"Storing customers data"<<en;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BankSystem* acc1 = new BankSystem();
    acc1->addCustomers(new CustomerAccount("Saurabh",1232.2));
    acc1->addCustomers(new CustomerAccount("Anurag",2312.1));
    acc1->addCustomers(new CustomerAccount("Vaibhav",232.13));

    PrintBankBalance* printBalance = new PrintBankBalance(acc1);
    printBalance->printBankBalance();

    StoreCustomerDataInDatabase* db = new StoreCustomerDataInDatabase(acc1);
    db->storingData();
    return 0;
    
}