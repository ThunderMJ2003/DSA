//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    public:
    void reversevec(vector<int>& nums, int x, int y){
        int i = x, j = y;
        int t;
        while (i<j){
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            ++i;
            --j;
        }
    }

    void rotate(vector<int>& nums, int k) {
        reversevec(nums, 0, nums.size()-1);
        reversevec(nums, 0, (k%nums.size())-1);
        reversevec(nums, k%nums.size(), nums.size()-1);
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