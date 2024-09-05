#include <bits/stdc++.h>
using namespace std;

void makepattern(int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d", max((n-i), (n-j)));
        }
        if (i<(n-1)){
            for (int j=0; j<(n-1); j++){
                printf("%d", max((n-i), j+2));
            }
        }
        
        if (i==(n-1)){
            for (int j=0; j<(n-1); j++){
                printf("%d", (j+2));
            }
        }
        printf("\n");
    }
    for (int i=0; i<(n-1); i++){
        for (int j=0; j<(n-1); j++){
            printf("%d", max((i+2), (n-j)));
        }
        printf("%d", (i+2));
        for (int j=0; j<(n-1); j++){
            printf("%d", max((i+2), (j+2)));
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