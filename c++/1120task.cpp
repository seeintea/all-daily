/*#include <iostream>
#include <string>
using namespace std;

void func(char *s[],int n){
	char *t;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strlen(s[i])>strlen(s[j])){
				t=s[i];
				s[i]=s[j];
				s[j]=s[i];
                cout<<"func:"<<i<<j<<s[i]<<"-"<<s[j]<<endl;
			}
		}
	}
}

int main(){
	char *ss[]={"bcc","bbcc","xy","aaaacc","aabcc"};
	func(ss,5);
	cout<<ss[0]<<endl;
    cout<<ss[4]<<endl;
}*/

#include <iostream>
using namespace std;

void func(int *a,int *b){
	int *c;
	c=a;
	a=b;
	b=c;
	cout<<"cs:"<<*a<<*b<<*c<<endl;
}

int main()
{
	int x=3,y=5,*p=&x,*q=&y;
	cout<<*p<<*q<<endl;
	func(p,q);
	cout<<*p<<*q<<endl;
	func(&x,&y);
	cout<<*p<<*q;
   return 0;
}