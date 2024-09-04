#include <bits/stdc++.h>
using namespace std;

void makepattern(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<(n-i); j++){
            printf("* ");
        }
        for (int j=0; j<(2*(i)); j++){
            printf("  ");
        }
        for (int j=0; j<(n-i); j++){
            printf("* ");
        }
        printf("\n");
    }
    for (int i=(n-1); i>=0; i--){
        for (int j=0; j<(n-i); j++){
            printf("* ");
        }
        for (int j=0; j<(2*(i)); j++){
            printf("  ");
        }
        for (int j=0; j<(n-i); j++){
            printf("* ");
        }
        printf("\n");
    }
}

int main(){
    int n;
    cin >> n;
    makepattern(n);
    return 0;
}