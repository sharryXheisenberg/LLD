/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */


//  signature rule  states that the child class have type of  methods implementation that their base classes / parents have 
// or it may work if it have more implementation than that of parent

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;

class Parent{
    public:
        virtual void print(string msg){
            cout<<"Parent "<<msg<<endl;
        }
};

class Child : public Parent{
    public:
        void print(string msg){
            cout<<"Child message"<<msg<<endl;
        }
};


class Client{
private:
    Parent* p;

public:
    Client(Parent* p){
        this->p = p;
    }

    void printMsg(){
        p->print("Hello!");
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Parent* parent = new Parent();
    Parent* child = new Child();

    Client* client = new Client(child);
    cout<<"Printing the msg function from child class methods"<<endl;
    client->printMsg();
    cout<<"\n";
    Client* client1 = new Client(parent);
    cout<<"Printing the msg function from parent class"<<endl;
    client1->printMsg();
    return 0;

}