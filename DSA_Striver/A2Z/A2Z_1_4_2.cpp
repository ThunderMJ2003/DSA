#include <bits/stdc++.h>
using namespace std;

int reverse(int n){
    int risky = 0;
    if (log10(n)==10){
        risky = 1;
    }
    int fin = 0;
    int neg = 0;
    int digitind = 1;
    if (n==INT_MIN){
        return 0;
    }
    if (n<0){
        n = -n;
        neg = 1;
    }
    while (n>0){
        //printf("fin at digitind %d = %d \n", digitind, fin);
        if ((digitind==10) && (fin > 214748364)){
            return 0;
        }
        if ((digitind==10) && (fin > 214748363)){
            if (((neg==0) && ((n%10)>7)) || ((neg==1) && ((n%10)>8))){
                return 0;
            }
        }
        fin = (fin*10) + (n%10);
        ++digitind;
        n = n/10;
    }
    if (neg){
        return (-fin);
    }
    return fin;
}

int main(){
    int n;
    cin >> n;
    printf("%d \n", reverse(n));
    return 0;
}