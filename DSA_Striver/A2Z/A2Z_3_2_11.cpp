//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<vector<int>> newmatrix(m);
    //     for (int i=0; i<m; i++){
    //         vector<int> tn(n);
    //         for (int j=0; j<n; j++){
    //             tn[j] = matrix[i][j];
    //         }
    //         newmatrix[i] = tn;
    //     }
    //     for (int i=0; i<m; i++){
    //         for (int j=0; j<n; j++){
    //             if (matrix[i][j] == 0){
    //                 for (int k=0; k<n; k++){
    //                     newmatrix[i][k] = 0;
    //                 }
    //                 for (int k=0; k<m; k++){
    //                     newmatrix[k][j] = 0;
    //                 }
    //             }
    //         }
    //     }
    //     matrix = newmatrix;
    // }

    // void setZeroes(vector<vector<int>>& matrix){
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<bool> rowz(m, false);
    //     vector<bool> colz(n, false);
    //     for (int i=0; i<m; i++){
    //         for (int j=0; j<n; j++){
    //             if (matrix[i][j] == 0){
    //                 rowz[i] = true;
    //                 colz[j] = true;
    //             }
    //         }
    //     }
    //     for (int i=0; i<m; i++){
    //         for (int j=0; j<n; j++){
    //             if ((rowz[i] == true) || (colz[j] == true)){
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<int> zi;
    //     vector<int> zj;
    //     for (int i=0; i<m; i++){
    //         for (int j=0; j<n; j++){
    //             if (matrix[i][j] == 0){
    //                 zi.push_back(i);
    //                 zj.push_back(j);
    //             }
    //         }
    //     }
    //     for (int i=0; i<zi.size(); i++){
    //         for (int j=0; j<n; j++){
    //             matrix[zi[i]][j] = 0;
    //         }
    //     }
    //     for (int i=0; i<zj.size(); i++){
    //         for (int j=0; j<m; j++){
    //             matrix[j][zj[i]] = 0;
    //         }
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix){
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int i, j;
    //     int flg = 0;
    //     for (i=0; i<m; i++){
    //         for (j=0; j<n; j++){
    //             if (matrix[i][j] == 0){
    //                 flg = 1;
    //                 break;
    //             }
    //         }
    //         if (flg){
    //             break;
    //         }
    //     }
    //     for (int k=0; k<m; k++){
    //         for (int l=0; l<n; l++){
    //             if (matrix[k][l] == 0){
    //                 matrix[i][l] = 0;
    //                 matrix[k][j] = 0;
    //             }
    //         }
    //     }
    //     for (int k=0; k<m; k++){
    //         if ((matrix[k][j]==0) && (k!=i)){
    //             for (int l=0; l<n; l++){
    //                 matrix[k][l] = 0;
    //             }
    //         }
    //     }
    //     for (int k=0; k<n; k++){
    //         if ((matrix[i][k]==0) && (k!=j)){
    //             for (int l=0; l<m; l++){
    //                 matrix[l][k] = 0;
    //             }
    //         }
    //     }
    //     for (int k=0; k<m; k++){
    //         matrix[k][j] = 0;
    //     }
    //     for (int k=0; k<n; k++){
    //         matrix[i][k] = 0;
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix){
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int x = 1;
    //     for (int i=0; i<m; i++){
    //         for (int j=0; j<n; j++){
    //             if (matrix[i][j] == 0){
    //                 matrix[0][j] = 0;
    //                 if (i==0){
    //                     x = 0;
    //                 }
    //                 else{
    //                     matrix[i][0] = 0;
    //                 }
    //             }
    //         }
    //     }
    //     for (int i=(m-1); i>=0; i--){
    //         for (int j=(n-1); j>=0; j--){
    //             if ((i!=0) && ((matrix[0][j] == 0) || (matrix[i][0] == 0))){
    //                 matrix[i][j] = 0;
    //             }
    //             if ((i==0) && (x==0)){
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    void setZeroes(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    if (i==0){
                        col0 = 0;
                    }
                    else{
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if ((matrix[i][0] == 0) || (matrix[0][j] == 0)){
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0){
            for (int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
        if (col0 == 0){
            for (int i=0; i<n; i++){
                matrix[0][i] = 0;
            }
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
	    ob.setZeroes(A);
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