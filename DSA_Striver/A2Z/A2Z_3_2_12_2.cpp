//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // void rotateby90(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     for (int i=0; i<(int)(n/2); i++){
    //         for (int j=i; j<(n-i-1); j++){
    //             swap(matrix[i][j], matrix[n-j-1][i]);
    //             swap(matrix[i][j], matrix[n-i-1][n-j-1]);
    //             swap(matrix[i][j], matrix[j][n-i-1]);
    //         }
    //     }
    // }
    //my method
    //starting from outer loop and going to every next loop and rotating that specific loop

    // void rotateby90(vector<vector<int>>& matrix){
    //     int n = matrix.size();
    //     for (int i=0; i<n; i++){
    //         for (int j=0; j<(n-i-1); j++){
    //             swap(matrix[i][j], matrix[n-j-1][n-i-1]);
    //         }
    //     }
    //     for (int i=0; i<n; i++){
    //         reverse(matrix[i].begin(), matrix[i].end());
    //     }
    // }
    //tranposing on the other diagonal, then reversing the rows

    // void rotateby90(vector<vector<int>>& matrix){
    //     int n = matrix.size();
    //     for (int i=0; i<n; i++){
    //         for (int j=(i+1); j<n; j++){
    //             swap(matrix[i][j], matrix[j][i]);
    //         }
    //     }
    //     for (int j=0; j<n; j++){
    //         int i=0, k=n-1;
    //         while (i<k){
    //             swap(matrix[i][j], matrix[k][j]);
    //             ++i;
    //             --k;
    //         }
    //     }
    // }
    //transposing, then reversing the columns

    void rotateby90(vector<vector<int>>& matrix){
        int n = matrix.size();
        for (int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        for (int i=0; i<n; i++){
            for (int j=(i+1); j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    //reversing the rows, then transposing
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> a;
        for (int i=0; i<n; i++){
            vector<int> t;
            for (int j=0; j<n; j++){
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
        obj.rotateby90(a);
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends