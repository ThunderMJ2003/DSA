#include <bits/stdc++.h>
using namespace std;

// int fib(int n){
//     if (n<2){
//         return n;
//     }
//     return (fib(n-1) + fib(n-2));
// }

int fib(int n) {
    if (n<2){
        return n;
    }
    int a=0, b=1;
    int c = a+b;
    for (int i=2; i<n; i++){
        a = b;
        b = c;
        c = a+b;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    printf("%d \n", fib(n));
    return 0;
}