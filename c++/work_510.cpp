#include <iostream>
using namespace std;

int main() {
    int l=0,m=0,n=0,o=0,p=0;
    char str[3][80];
    cout<<"please input string:"<<endl;

    /*for(i=0;i<100;i++){
        str[i] = getchar();
        if(str[i] == '\n'){
            break;
        }
    }*/

    for(int i=0;i<3;i++){
        for(int j=0;j<80;j++){
            str[i][j] = getchar();
            if(str[i][j] == '\n') break;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<80;j++){
            if((65<=str[i][j]) && (str[i][j]<=90)){
            l++;
            continue;
            }else if((97<=str[i][j]) && (str[i][j]<=122)){
                m++;
                continue;
            }else if(str[i][j] == 32){
                n++;
                continue;
            }else if((48<=str[i][j]) && (str[i][j]<=57)){
                o++;
                continue;
            }else if((str[i][j] != '\0') && (str[i][j] != '\n')){
                p++;
                continue;
            }else{
                break;
            }
        }
    }

    /*for(i=0; i<sizeof(str)/sizeof(str[0]);i++){
        if((65<=str[i]) && (str[i]<=90)){
            l++;
            continue;
        }else if((97<=str[i]) && (str[i]<=122)){
            m++;
            continue;
        }else if(str[i] == 32){
            n++;
            continue;
        }else if((48<=str[i]) && (str[i]<=57)){
            o++;
            continue;
        }else if((str[i] != '\0') && (str[i] != '\n')){
            p++;
            continue;
        }else{
            break;
        }
    }*/
    cout<<"bigLetter, smallLetter space, number, other:\t"<<l<<"\t"<<m<<"\t"<<n<<"\t"<<o<<"\t"<<p<<endl;
    return 0;
}