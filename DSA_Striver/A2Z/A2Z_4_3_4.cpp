//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // vector<int> findPeakGrid(vector<vector<int>>& mat){ // O(rows+cols)
    //     int at, ab, al, ar;
    //     for (int i=0; i<mat.size(); i++){
    //         for (int j=0; j<mat[0].size(); j++){
    //             if (i == 0){
    //                 at = -1;
    //             }
    //             else{
    //                 at = mat[i-1][j];
    //             }
    //             if (i == (mat.size()-1)){
    //                 ab = -1;
    //             }
    //             else{
    //                 ab = mat[i+1][j];
    //             }
    //             if (j == 0){
    //                 al = -1;
    //             }
    //             else{
    //                 al = mat[i][j-1];
    //             }
    //             if (j == (mat[0].size()-1)){
    //                 ar = -1;
    //             }
    //             else{
    //                 ar = mat[i][j+1];
    //             }
    //             if (mat[i][j] > max({at, ab, al, ar})){
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {-1, -1};
    // }

    vector<int> findPeakGrid(vector<vector<int>>& mat){ //O(log(rows)*cols)
        int l = 0, h = mat.size()-1;
        int m;
        int maxind;
        int at, ab;
        while (l <= h){
            m = (l+h)/2;
            maxind = max_element(mat[m].begin(), mat[m].end()) - mat[m].begin();
            if (m == 0){
                at = -1;
            }
            else{
                at = mat[m-1][maxind];
            }
            if (m == (mat.size()-1)){
                ab = -1;
            }
            else{
                ab = mat[m+1][maxind];
            }
            if (mat[m][maxind] > max(at, ab)){
                return {m, maxind};
            }
            else if (mat[m][maxind] < ab){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return {-1, -1};
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
        auto ans = obj.findPeakGrid(a);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            printf("%d ", ans[i]);
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