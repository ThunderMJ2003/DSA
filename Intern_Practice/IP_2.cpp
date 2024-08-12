#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p){
            return true;
        }
        
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        string p;
        cin >> s;
        cin >> p;
        Solution ob;
        bool fin = ob.isMatch(s, p);
        printf("fin = %d \n", fin);
    }
    return 0;
}