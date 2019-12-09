#include <iostream>
using namespace std;

int isYearFunc(int year);

int main() {
    int year,month,day;
    int comYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int isYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int isYearState,monthState;
    int daySum = 0;
    cout<<"please input year,month,day:";
    cin>>year>>month>>day;
    monthState = month;
    isYearState = isYearFunc(year);
    if(isYearState){
        for(int i=0;i<=month-2;i++){
            daySum += isYear[i];
        }
        daySum += day;
        cout<<year<<"-"<<monthState<<"-"<<day<<" is "<<daySum<<" day in this year(leap)";
    } else {
        for(int i=0;i<=month-2;i++){
            daySum += comYear[i];
        }
        daySum += day;
        cout<<year<<"-"<<monthState<<"-"<<day<<" is "<<daySum<<" day in this year";
    }
    cout<<endl;
    return 0;
}

int isYearFunc(int year){
    bool leap;
    if(year%4 == 0){
        if(year%100 == 0){
            if(year%400 == 0){
                leap = true;
            }else {
                leap = false;
            }
        }else {
            leap = true;
        }
    }else {
        leap = false;
    }

    if(leap) {
        return 1;
    }else {
        return 0;
    }
}