//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int isSorted(int n, vector<int> a) {
        for (int i=1; i<n; i++){
            if (a[i-1] > a[i]){
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> nums;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        Solution ob;
        bool ans = ob.isSorted(nums.size(), nums);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends