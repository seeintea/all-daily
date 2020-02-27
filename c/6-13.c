#include <stdio.h>

#define MAXN 10

// O(n^2)
double pow(double x, int y) {
    while(--y){
        x *= x;
    }
    return x;
}

double f( int n, double a[], double x ){
    double sum = 0;
    // 若 n=0 时, 返回常数
    if(!n) return a[0];
    do{
        sum += (pow(x, n))*a[n];
    }while(--n);
    return sum+a[0];
}

// 20200227 O(n)
// double f( int n, double a[], double x ){
//     double sum = 0;
//     // 若 n=0 时, 返回常数
//     if(!n) return a[0];
//     double m = 1.0; // 幂次计算
//     for(int i=1; i<=n; i++){
//         m *= x;
//         sum += a[i]*m;
//     }
//     return sum+a[0];
// }

int main()
{
    int n, i;
    double a[MAXN], x;
    
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}
