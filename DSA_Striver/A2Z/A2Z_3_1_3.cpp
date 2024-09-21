//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    bool check(vector<int>& nums){
        int n = nums.size();
        int falls = 0;
        for (int i=0; i<(n-1); i++){
            if (nums[i+1] < nums[i]){
                ++falls;
                if (falls>1){
                    return false;
                }
            }
        }
        if (falls==0){
            return true;
        }
        if (nums[0]<nums[n-1]){
            return false;
        }
        else{
            return true;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.check(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends