//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    int numberOfkPossible(vector<int>& nums, int s){
        int curk = 1;
        int cursum = 0;
        for (int i : nums){
            if ((cursum + i) > s){
                cursum = i;
                ++curk;
            }
            else{
                cursum += i;
            }
        }
        return curk;
    }
    int minTime(vector<int>& arr, int k){
        int l = arr[max_element(arr.begin(), arr.end()) - arr.begin()], h = 0;
        for (int i : arr){
            h += i;
        }
        int m;
        while (l <= h){
            m = (l+h)/2;
            if (numberOfkPossible(arr, m) <= k){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l;
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
        int ans = obj.minTime(a, n);

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