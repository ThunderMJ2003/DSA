//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    int kthElement(vector<int>& a, vector<int>& b, int k){
        int as = a.size(), bs = b.size();
        if (as > bs){
            return kthElement(b, a, k);
        }
        int l = 0, h = as;
        int ma, mb;
        while (l <= h){
            ma = (l+h)/2;
            mb = k-1-ma;
            if (mb < 0){
                h = ma-1;
                continue;
            }
            if (mb > bs){
                l = ma+1;
                continue;
            }
            if (((ma-1) >= 0) && (mb < bs) && (a[ma-1] > b[mb])){
                h = ma-1;
            }
            else if (((mb-1) >= 0) && ((mb-1) < bs) && (ma < as) && (b[mb-1] > a[ma])){
                l = ma+1;
            }
            else{
                break;
            }
        }
        int r1 = INT_MAX, r2 = INT_MAX;
        if ((ma >= 0) && (ma < as)){
            r1 = a[ma];
        }
        if ((mb >= 0) && (mb < bs)){
            r2 = b[mb];
        }
        return min(r1, r2);
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

        vector<int> b;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            b.push_back(num); // Read the array elements from input string

        Solution obj;
        auto ans = obj.kthElement(a, b, n);

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