/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;


// Interface segregation princple (ISP) - Many client specific interfaces are better than the one general client specific interface

class TwoDShape{
public:
    virtual double area() = 0;
};

class ThreeDShape{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDShape{
private:
    double side;

public:
    Square(double s):side(s){}
    
    double area() override{
        return side*side;
    }
};

class Rectangle:public TwoDShape{
private:
    double length , width;

public:
    Rectangle(double l ,double w):length(l) , width(w){}

    double area() override{
        return length*width;
    }
};

class Cube:public ThreeDShape{
private:
    double side;

public:
    Cube(double s):side(s){}

    double area() override{
        return 6*side*side;
    }
    double volume() override{
        return side*side*side;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TwoDShape* sq = new Square(4);
    TwoDShape* rect = new Rectangle(5,4);
    ThreeDShape* cube = new Cube(3.3);

    cout<<"Square "<<endl;
    cout<<"Area of Square "<<sq->area()<<endl;

    cout<<"Rectangle"<<endl;
    cout<<"Area of rectangle"<<rect->area()<<endl;

    cout<<"Cube"<<endl;
    cout<<"Area of cube "<<cube->area()<<endl;
    cout<<"Volume of cube "<<cube->volume()<<endl;

}