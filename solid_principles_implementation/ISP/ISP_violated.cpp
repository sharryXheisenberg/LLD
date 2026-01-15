/* 
 *  (▀̿Ĺ̯▀̿ ̿) Author - Balerion_The_second  (▀̿Ĺ̯▀̿ ̿)
 */

#include<bits/stdc++.h>
#define ll long long
#define en endl
using namespace std;

class Shape{
public:
    virtual double area() = 0;
    virtual double volume() = 0;  // but 2D shapes have both are and volume
};

class Square:public Shape{
private:
    double side;

public:
    Square(double s):side(s){}
    
    double area() override{
        return side*side;
    }

    double volume() override{    // forced method and here Interface segregation principle breaks
       throw logic_error("Volume not applicable for square");
    }
    
};

class Rectangle:public Shape{
private: 
    double length , width;

public:
    Rectangle(double l , double w) : length(l) , width(w) {}

    double area() override{
        return length * width;
    }

    double volume() override{    //forced method applied on this class because this method is mentioned in the main abstract class or interface 
        throw logic_error("Volume is not applicable to rectangle ");
    }

};

class Cube:public Shape{
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
    
    Shape* square = new Square(5);
    Shape* rect = new Rectangle(2,4);
    Shape* cube = new Cube(3);

    cout<<"Square "<<endl;
    cout<<"Area of Square "<<square->area()<<endl;
    cout<<"Volume of square "<<square->volume()<<endl;   // throws error

    cout<<"Rectangle"<<endl;
    cout<<"Area of rectangle"<<rect->area()<<endl;
    cout<<"Volume of rectangle"<<rect->volume()<<endl; // throws error 

    cout<<"Cube"<<endl;
    cout<<"Area of cube "<<cube->area()<<endl;
    cout<<"Volume of cube "<<cube->volume()<<endl;

    return 0;
}