#include <iostream>
using namespace std;

class Date;
class Time {
public:
    Time(int, int ,int);
    friend void display(Time &);
private:
    int hour;
    int minute;
    int sec;
};

class Date {
public:
    Date(int, int, int);
    friend void display(Date &);
private:
    int month;
    int day;
    int year;
};

Time::Time(int a, int b, int c) {
    hour = a;
    minute = b;
    sec = c;
}

void display(Date &d){
    cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
}

void display(Time &t){
    cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}

void display(Date &d, Time &t) {
    display(d);
    display(t);
}

Date::Date(int a, int b, int c){
    month = a;
    day = b;
    year = c;
}

int main(){
    Time t(10,13,56);
    Date d(12,25,2019);
    display(d,t);
    return 0;
}
