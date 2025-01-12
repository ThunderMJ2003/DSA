//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //     vector<int> fin;
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for (int i=0; i<=(int)(min(m, n)/2); i++){
    //         for (int j=i; j<=(n-i-1); j++){
    //             if ((m-i-1) < i){
    //                 break;
    //             }
    //             fin.push_back(matrix[i][j]);
    //         }
    //         for (int j=(i+1); j<=(m-i-1); j++){
    //             if ((n-i-1) < i){
    //                 break;
    //             }
    //             fin.push_back(matrix[j][n-i-1]);
    //         }
    //         for (int j=(n-i-2); j>=(i); j--){
    //             if ((m-i-1) <= i){
    //                 break;
    //             }
    //             fin.push_back(matrix[m-i-1][j]);
    //         }
    //         for (int j=(m-i-2); j>=(i+1); j--){
    //             if ((n-i-1) <= i){
    //                 break;
    //             }
    //             fin.push_back(matrix[j][i]);
    //         }
    //     }
    //     return fin;
    // }

    // vector<int> spiralOrder(vector<vector<int>>& matrix){
    //     vector<int> fin;
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     int l=0, r=n-1, t=0, b=m-1;
    //     while ((l<=r) && (t<=b)){
    //         for (int i=l; i<=r; i++){
    //             fin.push_back(matrix[t][i]);
    //         }
    //         for (int i=(t+1); i<=b; i++){
    //             fin.push_back(matrix[i][r]);
    //         }
    //         if (t<b){
    //             for (int i=(r-1); i>=l; i--){
    //                 fin.push_back(matrix[b][i]);
    //             }
    //         }
    //         if (l<r){
    //             for (int i=(b-1); i>t; i--){
    //                 fin.push_back(matrix[i][l]);
    //             }
    //         }
    //         ++l;
    //         --r;
    //         ++t;
    //         --b;
    //     }
    //     return fin;
    // }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0, r=n-1, t=0, b=m-1;
        vector<int> fin;
        while ((l<=r) && (t<=b)){
            //printf("here \n");
            for (int i=l; i<=r; i++){
                fin.push_back(matrix[t][i]);
            }
            ++t;
            for (int i=t; i<=b; i++){
                fin.push_back(matrix[i][r]);
            }
            --r;
            if (t<=b){
                for (int i=r; i>=l; i--){
                    fin.push_back(matrix[b][i]);
                }
                --b;
            }
            if (l<=r){
                for (int i=b; i>=t; i--){
                    fin.push_back(matrix[i][l]);
                }
                ++l;
            }
        }
        //printf("here \n");
        return fin;
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
	    vector<int> fin = ob.spiralOrder(A);
        for (int i=0; i<fin.size(); i++){
            printf("%d ", fin[i]);
        }
        //printf("%d", fin);
        // for (int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
        //         printf("%d ", A[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends