#include <iostream>
using namespace std;

class  Str{
private:
    int Length;
    char *Sp;
public:
    Str(char *string){
        if(string){
            Length=strlen(string);
            Sp=new char[Length+1];
            strcpy(Sp,string);
        } else {
            Sp=0;
        }   
    } 
    void Show(void){cout<<Sp<<endl;}
    ~Str() {
        if(Sp) {
            delete []Sp;
        }      
    }
};

int main() {
    Str s1("Study C++");
    Str s2(s1);
    s1.Show ();       
    s2.Show ();
    return 0;
}