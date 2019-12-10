#include <iostream>
#include <math.h>
using namespace std;

class Shape {
public:
    virtual float printArea() const = 0;    // 纯虚函数
};

class Circle: public Shape {
private:
    float pi;
    float r;
public:
    Circle(float a = 0): r(a) { pi = 3.14; };   // 构造函数
    virtual float printArea() const { return pow(r,2)*pi; };
};

class Square: public Shape {
private:
    float x; // 定义边长
public:
    Square(float a): x(a) {}; //构造函数
    virtual float printArea() const { return pow(x,2); };
};

class Rectangle: public Shape {
private:
    float x, y; // 定义长宽
public:
    Rectangle(float a, float b): x(a), y(b) {}; //构造函数
    virtual float printArea() const { return x*y; };
};

class Trapezoid: public Shape {
private:
    float x, y, z; // 定义底高
public:
    Trapezoid(float a, float b, float c): x(a), y(b), z(c) {}; //构造函数
    virtual float printArea() const { return (x+y)*z*0.5; };
};

class Triangle: public Shape {
private:
    float x, y; // 定义底高
public:
    Triangle(float a, float b): x(a), y(b) {}; //构造函数
    virtual float printArea() const { return 0.5*x*y; };
};

int main() {
    Circle c(3.0);
    Square s(3);
    Rectangle r(3,5);
    Trapezoid td(3,5,7);
    Triangle te(5,7);
    Shape *p;
    p = &c;
    cout<<"Circle : "<<p->printArea()<<endl;
    p = &s;
    cout<<"Square : "<<p->printArea()<<endl;
    p = &r;
    cout<<"Rectangle : "<<p->printArea()<<endl;
    p = &td;
    cout<<"Trapezoid : "<<p->printArea()<<endl;
    p = &te;
    cout<<"Triangle : "<<p->printArea()<<endl;
    return 0;
}