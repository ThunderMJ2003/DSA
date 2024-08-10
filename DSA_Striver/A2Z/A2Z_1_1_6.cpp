#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
    int n;
    cin >> n;
    int a = 1, b = 1;
    int fin;
    for (int i=2; i<n; i++){
        fin = a + b;
        a = b;
        b = fin;
    }
    if ((n==1) || (n==2)){
        printf("1 \n");
    }
    else{
        printf("%d \n", fin);
    }
    return 0;
}