//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    public:
    int removeDuplicates(vector<int>& nums){
        int i = 1;
        int n = nums.size();
        for (int j=1; j<n; j++){
            if (nums[i-1] != nums[j]){
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
    // int removeDuplicates(vector<int>& nums){
    //     vector<int> onlyuniques;
    //     onlyuniques.push_back(nums[0]);
    //     int fin = 1;
    //     int n = nums.size();
    //     for (int i=1; i<n; i++){
    //         if (nums[i] != *(onlyuniques.end()-1)){
    //             onlyuniques.push_back(nums[i]);
    //             ++fin;
    //         }
    //     }
    //     for (int i=0; i<onlyuniques.size(); i++){
    //         nums[i] = onlyuniques[i];
    //     }
    //     return fin;
    // }
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
        auto ans = ob.removeDuplicates(arr);
        cout << ans << "\n";
        for (int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends