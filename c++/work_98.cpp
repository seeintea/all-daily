#include <iostream>
using namespace std;

class Student{
public:
    Student(int n, float s): num(n),scorce(s) {}
    void change(int a, float s) {
        num = a;
        scorce =s;
    }
    void display(){
        cout<<num<<" "<<scorce<<endl;
    }
    // add fun func
    void fun(Student &std);
private:
    int num;
    float scorce;
};

void Student::fun(Student &std){
    std.display();
    std.change(101, 80.5);
    std.display();
    std.change(101, 90.5);
    std.display();
}

int main(){
    Student std(101, 78.5);
    Student &rStd = std;
    rStd.fun(rStd);
    return 0;
}