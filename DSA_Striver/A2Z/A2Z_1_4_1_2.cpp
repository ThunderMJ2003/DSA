//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long reverseBits(long n) {
        string binaryn = bitset<32>(n).to_string();
        if (n==0){
            return 0;
        }
        string fin = "";
        for (int i=0; i<32; i++){
            fin.push_back(binaryn[32-i-1]);
        }
        return stol(fin, nullptr, 2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.reverseBits(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends