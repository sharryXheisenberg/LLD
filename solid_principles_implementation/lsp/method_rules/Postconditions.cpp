/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;

// A postcondition must be statisfied after a method is executed .
// Sub classes can strengthen the post condition but cannot weaken it exactly opposite to pre condition 


class Car{
protected:
    int speed;

public:
    Car(){
        speed =0;
    }
    void acclerate(){
        cout<<"Acclerating"<<endl;
    }
    virtual void brake(){
        if(speed>10){
            cout<<"Applying brakes"<<endl;
            speed-=10;
        }
        cout<<"you cannot apply brakes on still position"<<endl;
    }
};

class HybridCar:public Car{
private:
    int charge;

public:
    HybridCar():Car(){
        charge = 0;
    }
    // postcondition speed decreases by 10 
    //  postcondition increases speed
    void brake(){
        cout<<"Applying break"<<endl;
        speed-=20;
        charge+=10;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Car* c1 = new Car();
    c1->acclerate();
    c1->brake();
    return 0;
}