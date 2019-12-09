#include <iostream>
using namespace std;

class Date {
public:
    Date(int, int, int);
    friend class Time;
private:
    int month;
    int day;
    int year;
};

class Time {
public:
    Time(int, int ,int);
    void display(Date &);
private:
    int hour;
    int minute;
    int sec;
};

Date::Date(int a, int b, int c){
    month = a;
    day = b;
    year = c;
}

Time::Time(int a, int b, int c) {
    hour = a;
    minute = b;
    sec = c;
}

void Time::display(Date &d) {
    cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
    cout<<hour<<":"<<minute<<":"<<sec<<endl;
}

int main(){
    Time t(10,13,56);
    Date d(12,25,2004);
    t.display(d);
    return 0;
}
