//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        if (A<B){
            return lcmAndGcd(B, A);
        }
        vector<long long> fin;
        long long t;
        long long ogA = A;
        long long ogB = B;
        while (B){
            t = B;
            B = A%B;
            A = t;
        }
        long long gcd = A;
        long long lcm = ogA*ogB/gcd;
        fin.push_back(lcm);
        fin.push_back(gcd);
        return fin;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends