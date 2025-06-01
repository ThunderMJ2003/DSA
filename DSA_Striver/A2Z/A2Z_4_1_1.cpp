//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // int recursive_binary_search(vector<int>& nums, int target, int l, int h){
    //     if (h<l){
    //         return -1;
    //     }
    //     int m = (l+h)/2;
    //     if (nums[m] == target){
    //         return m;
    //     }
    //     else if (nums[m] < target){
    //         return recursive_binary_search(nums, target, m+1, h);
    //     }
    //     else{
    //         return recursive_binary_search(nums, target, l, m-1);
    //     }
    // }
    // int search(vector<int>& nums, int target){
    //     return recursive_binary_search(nums, target, 0, nums.size()-1);
    // }

    int search(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        int m = (l+h)/2;
        while (l<=h){
            m = (l+h)/2;
            if (nums[m] == target){
                return m;
            }
            else if (nums[m] < target){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        // int n;
        // cin >> n;
        // cin.ignore();
        // vector<vector<int>> a;
        // for (int i=0; i<n; i++){
        //     vector<int> t;
        //     for (int j=0; j<n; j++){
        //         int x;
        //         cin >> x;
        //         t.push_back(x);
        //     }
        //     a.push_back(t);
        //     t.clear();
        // }

        int n;
        cin >> n;
        cin.ignore();

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        int ans = obj.search(a, n);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        // for (int i=0; i<ans.size(); i++){
        //     for (int j=0; j<ans[i].size(); j++){
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends