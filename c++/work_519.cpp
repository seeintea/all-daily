#include <iostream>
using namespace std;

int main() {
    int num = 0;
    int j;
    char str[100];
    cout<<"please input words:";
    cin.getline(str,100);
    for(int i=1;i<100;i++){
        if(str[i] == 32 || str[i] == '\n' || str[i] == '\0') {
            j = i-1;
            if((str[j]!=32) && (((97<=str[j]) && (str[j]<=122)) || ((65<=str[j]) && (str[j]<=90)))) {
                num++;
            }
        }
    }
    cout<<"total words:"<<num<<endl;
    
    return 0;
}