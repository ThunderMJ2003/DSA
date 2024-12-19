//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        vector <int> fin(nums.size());
        for (int i=0; i<nums.size(); i++){
            fin[(i+k)%(nums.size())] = nums[i];
        }
        nums = fin;
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
        int k;
        cin >> k;
        Solution ob;
        ob.rotate(arr, k);
        for (int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends