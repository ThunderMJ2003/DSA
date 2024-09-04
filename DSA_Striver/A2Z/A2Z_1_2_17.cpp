#include <bits/stdc++.h>
using namespace std;

void makepattern(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<(2*(n-i-1)); j++){
            printf(" ");
        }
        for (int j=0; j<(i+1); j++){
            printf("%c ", ('A'+j));
        }
        for (int j=0; j<i; j++){
            printf("%c ", ('A'+i-j-1));
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