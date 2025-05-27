//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i=m-1, j=n-1, k=m+n-1;
            while ((i>=0) && (j>=0)){
                if (nums1[i] > nums2[j]){
                    nums1[k] =  nums1[i];
                    --k;
                    --i;
                }
                else{
                    nums1[k] = nums2[j];
                    --k;
                    --j;
                }
            }
            if (j>=0){
                while (j>=0){
                    nums1[k] = nums2[j];
                    --k;
                    --j;
                }
            }
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
        // for (int i=0; i<m; i++){
        //     vector<int> t;
        //     for (int j=0; j<n; j++){
        //         int x;
        //         cin >> x;
        //         t.push_back(x);
        //     }
        //     a.push_back(t);
        //     t.clear();
        // }

        int m;
        cin >> m;
        cin.ignore();

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

        vector<int> b;
        string input2;

        // Input format: first number n followed by the array elements
        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> num)
            b.push_back(num); // Read the array elements from input string

        Solution obj;
        // vector<vector<int>> ans = obj.merge(a);
        obj.merge(a, m, b, n);

        // cout << ans << endl;
        for (int i=0; i<a.size(); i++){
            printf("%d ", a[i]);
        }
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