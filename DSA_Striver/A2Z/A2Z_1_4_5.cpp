//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        vector<int> narr;
        int nlen = 0;
        int ogn = n;
        while (n>0){
            narr.push_back(n%10);
            n = n/10;
            ++nlen;
        }
        int fin = 0;
        int tx;
        for (int i=0; i<nlen; i++){
            tx = 1;
            for (int j=0; j<nlen; j++){
                tx = tx * narr[i];
            }
            fin = fin + tx;
        }
        if (fin==ogn){
            return "true";
        }
        else{
            return "false";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends