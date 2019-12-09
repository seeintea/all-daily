#include <iostream>
using namespace std;

class Saleman {
private:
    int num;
    int quantity;  
    float price;
    float allRevenue;
    float realPrice;
    static int allNums;
    static float allFee;
    static float discout;
public:
    Saleman(int, int, float);
    void salemanDiscout(int);
    static void average();
    static void display();
};

int Saleman::allNums = 0;
float Saleman::allFee = 0;
float Saleman::discout = 0.98;

Saleman::Saleman(int a, int b, float c) {
    num = a;
    quantity = b;
    price = c;
    allRevenue = quantity * price;
    realPrice = price;
    allNums += quantity;
    allFee += allRevenue;
}

void Saleman::salemanDiscout(int a){
    if(a>10){
        allRevenue += price * a * discout;
    } else{
        allRevenue += price * a;   
    }
    num += a;
    realPrice = allRevenue / a;
    allNums += a;
    allFee += price * a;
}

void Saleman::average() {
    float a = allFee / allNums;
    cout<<"average price : "<<a<<endl;
}

void Saleman::display() {
    cout<<"allQuantity : "<<allNums<<" ; allFee : "<<allFee<<endl;
}


int main() {
    Saleman s101(101,5,23.5);
    Saleman s102(102,12,24.56);
    Saleman s103(103,100,21.5);
    s101.average();
    s101.display();
    //s102.average();
    //s102.display();
    //s103.average();
    //s103.display();
    s101.salemanDiscout(12);
    s102.salemanDiscout(8);
    s103.salemanDiscout(1);
    s101.average();
    s101.display();
    //s102.average();
    //s102.display();
    //s103.average();
    //s103.display();
    return 0;
}