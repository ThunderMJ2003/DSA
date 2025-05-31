//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // int reversePairs(vector<int>& nums){
        //     int fin = 0;
        //     for (int i=0; i<nums.size(); i++){
        //         for (int j=(i+1); j<nums.size(); j++){
        //             if (nums[i] > ((long long)2*nums[j])){
        //                 ++fin;
        //             }
        //         }
        //     }
        //     return fin;
        // }

        int merge_sort_reverse_pairs(vector<int> &c, int l, int h){
            if ((h-l+1) < 2){
                return 0;
            }
            int m = (h+l)/2;
            int x = merge_sort_reverse_pairs(c, l, m);
            int y = merge_sort_reverse_pairs(c, m+1, h);
            int fin = x + y;
            int i=l, j=m+1, i2=l, j2=m+1;
            vector<int> temparr;
            while ((i2<=m) && (j2<=h)){
                if (c[i2] > ((long long)2*c[j2])){
                    fin += (m-i2+1);
                    ++j2;
                }
                else{
                    ++i2;
                }
            }
            while ((i<=m) && (j<=h)){
                if (c[i] <= c[j]){
                    temparr.push_back(c[i]);
                    ++i;
                }
                else{
                    temparr.push_back(c[j]);
                    ++j;
                }
            }
            if (i<=m){
                while (i<=m){
                    temparr.push_back(c[i]);
                    ++i;
                }
            }
            if (j<=h){
                while (j<=h){
                    temparr.push_back(c[j]);
                    ++j;
                }
            }
            for (int i=0; i<temparr.size(); i++){
                c[i+l] = temparr[i];
            }
            return fin;
        }
        int reversePairs(vector<int>& nums){
            vector<int> temparr;
            for (int i : nums){
                temparr.push_back(i);
            }
            return merge_sort_reverse_pairs(temparr, 0, nums.size()-1);
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

        // int n;
        // cin >> n;
        // cin.ignore();

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        int ans = obj.reversePairs(a);

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