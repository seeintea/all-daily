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

class Rectangle: public Shape {
private:
    float x, y; // 定义长宽
public:
    Rectangle(float a, float b): x(a), y(b) {}; //构造函数
    virtual float printArea() const { return x*y; };
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
    Rectangle r(3,5);
    Triangle t(5,7);
    cout<<"Circle : "<<c.printArea()<<endl;
    cout<<"Rectangle : "<<r.printArea()<<endl;
    cout<<"Triangle : "<<t.printArea()<<endl;
    return 0;
}