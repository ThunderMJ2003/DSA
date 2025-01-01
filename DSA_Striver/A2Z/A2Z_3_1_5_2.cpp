//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    public:
    // void rotate(vector<int>& nums, int k) {
    //     vector <int> fin(nums.size());
    //     for (int i=0; i<nums.size(); i++){
    //         fin[(i+k)%(nums.size())] = nums[i];
    //     }
    //     nums = fin;
    // }

    // void rotate(vector<int>& nums, int k) {
    //     vector<int> tempnums;
    //     int n = nums.size();
    //     k = k % n;
    //     for (int i=0; i<k; i++){
    //         tempnums.push_back(nums[n-k+i]);
    //     }
    //     for (int i=(n-k-1); i>=0; i--){
    //         nums[i+k] = nums[i];
    //     }
    //     for (int i=0; i<k; i++){
    //         nums[i] = tempnums[i];
    //     }
    // }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }

    vector<int> rotateArray(vector<int>& arr, int n) {
        // Write your code here.
        rotate(arr, n-1);
        return arr;
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
        vector<int> ans = ob.rotateArray(arr, n);
        for (int i=0; i<n; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends