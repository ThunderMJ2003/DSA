//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<int> moveZeros(int n, vector<int> nums) {
    // Write your code here.
    int i = -1;
        for (int j=0; j<n; j++){
            if (nums[j] == 0){
                i = j;
                break;
            }
        }
        if (i == (-1)){
            return nums;
        }
        int j = -1;
        for (int k=(i+1); k<n; k++){
            if (nums[k] != 0){
                j = k;
                break;
            }
        }
        if (j == (-1)){
            return nums;
        }
        while (j<n){
            swap(nums[i], nums[j]);
            ++i;
            while (j<n){
                ++j;
                if ((j<n) && (nums[j] != 0)){
                    break;
                }
            }
        }
        return nums;
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
        vector<int> ans = ob.moveZeros(arr.size(), arr);
        for (int i=0; i<n; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends