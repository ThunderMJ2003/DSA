#include <bits/stdc++.h>
using namespace std;

void makepattern(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
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