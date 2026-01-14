/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


// A precondition must be statisfied before a method can be executed . 
//  Sub classes can weaken the precondition but cannot strengthen it .



class User{
public:
    virtual void setPassword(string password){
        if(password.length()<8){
            throw invalid_argument("Password must be at least 8 characters long !!");
        }
        cout<<"Password set successfully"<<endl;
    }

};

class AdminUser: public User{
public:
    void setPassword(string password){
        if(password.length()<6){   // here above precondition of the base class is weaken not strengthen 
            throw invalid_argument("Password must be at least 6 characters long!");
        }
        cout<<"Password set successfully"<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    User* u1 = new User();
    u1->setPassword("saurw32r23qw3");
    AdminUser* a1 = new AdminUser();
    a1->setPassword("334f");
    return 0;
}