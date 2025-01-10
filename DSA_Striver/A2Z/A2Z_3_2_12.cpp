//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> newmatrix(n);
    //     for (int i=0; i<n; i++){
    //         vector<int> tn(n, 0);
    //         newmatrix[i] = tn;
    //     }
    //     for (int i=0; i<n; i++){
    //         for (int j=0; j<n; j++){
    //             newmatrix[j][n-1-i] = matrix[i][j];
    //         }
    //     }
    //     matrix = newmatrix;
    // }

    // void rotate(vector<vector<int>>& matrix){
    //     int n = matrix.size();
    //     for (int i=0; i<n; i++){
    //         for (int j=(i+1); j<n; j++){
    //             swap(matrix[i][j], matrix[j][i]);
    //         }
    //     }
    //     for (int i=0; i<n; i++){
    //         int j = 0;
    //         int k = n-1;
    //         while (j<k){
    //             swap(matrix[i][j], matrix[i][k]);
    //             ++j;
    //             --k;
    //         }
    //     }
    // }

    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     for (int i=0; i<(int)(n/2); i++){
    //         for (int j=i; j<(n-i-1); j++){
    //             swap(matrix[i][j], matrix[j][n-i-1]);
    //             swap(matrix[i][j], matrix[n-i-1][n-j-1]);
    //             swap(matrix[i][j], matrix[n-j-1][i]);
    //         }
    //     }
    // }
    //my method
    //starting from outer loop and going to every next loop and rotating that specific loop

    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        for (int i=0; i<n; i++){
            for (int j=(i+1); j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
    cin>>t;
	while(t--)
	{
        int m;
        cin >> m;
        int n;
        cin >> n;
	    vector<vector<int>> A(m);
        for (int i=0; i<m; i++){
            vector<int> tA(n);
            for (int j=0; j<n; j++){
                cin >> tA[j];
            }
            A[i] = tA;
        }
	    Solution ob;
	    ob.rotate(A);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        //printf("%d", fin);
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends