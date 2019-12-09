#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int b=0,m=0,n=0,o=0,p=0;
    char str[100];
    cout<<"please input string(char<100 & over by enter):"<<endl;
    for(i=0;i<100;i++){
        *(str+i) = getchar();
        if(*(str+i) == '\n'){
            break;
        }
    }

    for(i=0; i<sizeof(str)/sizeof(str[0]);i++){
        if((65<=*(str+i)) && (*(str+i)<=90)){
            b++;
            continue;
        }else if((97<=*(str+i)) && (*(str+i)<=122)){
            m++;
            continue;
        }else if(*(str+i) == 32){
            n++;
            continue;
        }else if((48<=*(str+i)) && (*(str+i)<=57)){
            o++;
            continue;
        }else if((*(str+i) != '\0') && (*(str+i) != '\n')){
            p++;
            continue;
        }else{
            break;
        }
    }

    cout<<"bigLetter, letter, space, number, other:\t"<<b<<"\t"<<m<<"\t"<<n<<"\t"<<o<<"\t"<<p<<endl;
    return 0;
}