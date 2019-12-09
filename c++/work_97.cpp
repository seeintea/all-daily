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
private:
    int num;
    float scorce;
};

int main(){
    Student std(101, 78.5);
    Student *pStd = &std;
    pStd->display();
    pStd->change(101, 80.5);
    pStd->display();
    return 0;
}