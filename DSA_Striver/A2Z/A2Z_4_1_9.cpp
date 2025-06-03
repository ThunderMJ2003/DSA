//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    bool search(vector<int>& nums, int target){
        int l = 0, h = nums.size()-1;
        int m;
        while (l<=h){
            m = (l+h)/2;
            if (nums[m] == target){
                return true;
            }
            else if (nums[m] < target){
                if ((nums[l] == nums[m]) && (nums[m] == nums[h])){
                    ++l;
                    --h;
                }
                else if (nums[m] <= nums[h]){
                    if (target <= nums[h]){
                        l = m+1;
                    }
                    else{
                        h = m-1;
                    }
                }
                else{
                    l = m+1;
                }
            }
            else{
                if ((nums[l] == nums[m]) && (nums[m] == nums[h])){
                    ++l;
                    --h;
                }
                else if (nums[l] <= nums[m]){
                    if (nums[l] <= target){
                        h = m-1;
                    }
                    else{
                        l = m+1;
                    }
                }
                else{
                    h = m-1;
                }
            }
        }
        return false;
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