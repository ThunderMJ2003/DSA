//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    int minRow(vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        int high, low, mid, min1 = m, minind = 0;
        for (int i=0; i<n; i++){
            sort(mat[i].begin(), mat[i].end());
            low = 0, high = m-1;
            while (low <= high){
                mid = (high+low)/2;
                if (((mat[i][mid] == 0) && (mid == (m-1))) || ((mat[i][mid] == 0) && (mat[i][mid+1] == 1))){
                    if ((m-mid-1) < min1){
                        min1 = m - mid - 1;
                        minind = i;
                    }
                    break;
                }
                else if ((mat[i][mid] == 0) && (mat[i][mid+1] == 0)){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return minind+1;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int m;
        cin >> m;
        cin.ignore();
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> a;
        for (int i=0; i<m; i++){
            vector<int> t;
            for (int j=0; j<n; j++){
                int x;
                cin >> x;
                t.push_back(x);
            }
            a.push_back(t);
            t.clear();
        }

        // int n;
        // cin >> n;
        // cin.ignore();

        // vector<int> a;
        // string input;

        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // int num;
        // while (ss >> num)
        //     a.push_back(num); // Read the array elements from input string

        Solution obj;
        auto ans = obj.minRow(a);

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