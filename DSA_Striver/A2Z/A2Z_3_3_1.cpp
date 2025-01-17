//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> fin(numRows);
    //     for (int i=0; i<numRows; i++){
    //         vector<int> tn(i+1, 1);
    //         for (int j=1; j<i; j++){
    //             tn[j] = fin[i-1][j-1] + fin[i-1][j];
    //         }
    //         fin[i] = tn;
    //     }
    //     return fin;
    // }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> fin;
        for (int i=0; i<numRows; i++){
            vector<int> temp(i+1, 1);
            for (int j=1; j<i; j++){
                temp[j] = fin.back()[j-1] + fin.back()[j];
            }
            fin.push_back(temp);
            temp.clear();
        }
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
        int n;
        cin >> n;
	    // vector<int> A(n);
	    // for(int i=0;i<n;i++)
	    //     cin>>A[i];
	    Solution ob;
	    vector<vector<int>> fin = ob.generate(n);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        //printf("%d", fin);
        for (int i=0; i<fin.size(); i++){
            for (int j=0; j<fin[i].size(); j++){
                printf("%d ", fin[i][j]);
            }
            printf("\n");
        }
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends