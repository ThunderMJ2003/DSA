#include <bits/stdc++.h>
using namespace std;

void makepattern(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<(i+1); j++){
            printf("%d ", (j+1));
        }
        for (int j=0; j<(4*(n-i-1)); j++){
            printf(" ");
        }
        for (int j=0; j<(i+1); j++){
            printf("%d ", (i+1-j));
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