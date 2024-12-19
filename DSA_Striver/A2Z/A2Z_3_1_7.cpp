//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        int n = nums.size();
        for (i=0; i<n; i++){
            if (nums[i]==0){
                break;
            }
        }
        if (i==(n-1)){
            return;
        }
        int j;
        for (j=i; j<n; j++){
            if (nums[j]!=0){
                break;
            }
        }
        int t;
        while (j<n){
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            for (i=i+1; i<n; i++){
                if (nums[i]==0){
                    break;
                }
            }
            if (i==(n-1)){
                return;
            }
            for (j=j+1; j<n; j++){
                if  (nums[j]!=0){
                    break;
                }
            }
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
        ob.moveZeroes(arr);
        for (int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends