#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x){
    if (x<0){
        return 0;
    }
    int ogx = x;
    long revx = 0;
    while (x>0){
        revx = (revx*10) + x%10;
        x = x/10;
    }
    return (revx==ogx);
}

int main(){
    int x;
    cin >> x;
    printf("%d \n", isPalindrome(x));
    return 0;
}