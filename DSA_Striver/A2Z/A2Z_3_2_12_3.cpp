//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void rotateMatrix(vector<vector<int>> &mat, int n, int m){
        for (int i=0; i<(int)(min(m,n)/2); i++){
            int x = mat[i][m-i-1];
            for (int j=(m-i-1); j>i; j--){
                mat[i][j] = mat[i][j-1];
            }
            int y = mat[n-i-1][m-i-1];
            for (int j=(n-i-1); j>(i+1); j--){
                mat[j][m-i-1] = mat[j-1][m-i-1];
            }
            mat[i+1][m-i-1] = x;
            x = mat[n-i-1][i];
            for (int j=i; j<(m-i-2); j++){
                mat[n-i-1][j] = mat[n-i-1][j+1];
            }
            mat[n-i-1][m-i-2] = y;
            for (int j=i; j<(n-i-2); j++){
                mat[j][i] = mat[j+1][i];
            }
            mat[n-i-2][i] = x;
        }
    }
    //going through rings and moving them forward
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int n;
        int m;
        cin >> n >> m;
        cin.ignore();
        vector<vector<int>> a;
        for (int i=0; i<n; i++){
            vector<int> t;
            for (int j=0; j<m; j++){
                int x;
                cin >> x;
                t.push_back(x);
            }
            a.push_back(t);
            t.clear();
        }

        // vector<int> a;
        // string input;

        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // int num;
        // while (ss >> num)
        //     a.push_back(num); // Read the array elements from input string

        Solution obj;
        obj.rotateMatrix(a, n, m);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends