#include <bits/stdc++.h>
using namespace std;

void makepattern(int n){
    for (int j=0; j<n; j++){
        printf("*");
    }
    printf("\n");
    for (int i=0; i<(n-2); i++){
        printf("*");
        for (int j=0; j<(n-2); j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    if (n>1){
        for (int j=0; j<n; j++){
            printf("*");
        }
    }
}

int main(){
    int n;
    cin >> n;
    makepattern(n);
    return 0;
}