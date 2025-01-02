//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:\
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> fin;
        int i=0, j=0;
        if (m==0){
            i = 1;
            fin.push_back(arr1[0]);
        }
        else if (n==0){
            j = 1;
            fin.push_back(arr2[0]);
        }
        else if ((m==0) && (n==0)){
            return fin;
        }
        else{
            if (arr1[i] < arr2[j]){
                fin.push_back(arr1[i]);
                ++i;
            }
            else{
                fin.push_back(arr2[j]);
                ++j;
            }
        }
        while ((i<n) && (j<m)){
            if ((arr1[i] < arr2[j]) && (arr1[i] != *(fin.end()-1))){
                fin.push_back(arr1[i]);
                ++i;
            }
            else if ((arr1[i] >= arr2[j]) && (arr2[j] != *(fin.end()-1))){
                fin.push_back(arr2[j]);
                ++j;
            }
            else if ((arr1[i] < arr2[j]) && (arr1[i] == *(fin.end()-1))){
                ++i;
            }
            else if ((arr1[i] >= arr2[j]) && (arr2[j] == *(fin.end()-1))){
                ++j;
            }
        }
        if (i != n){
            for (i=i; i<n; i++){
                if (arr1[i] != *(fin.end()-1)){
                    fin.push_back(arr1[i]);
                }
            }
            return fin;
        }
        if (j != m){
            for (j=j; j<m; j++){
                if (arr2[j] != *(fin.end()-1)){
                    fin.push_back(arr2[j]);
                }
            }
            return fin;
        }
    }

    // vector<int> findUnion(vector<int> &a, vector<int> &b) {
    //     vector<int> fin;
    //     int i=0, j=0;
    //     fin.push_back(min(a[i], b[j]));
    //     while ((i < a.size()) && (j < b.size())){
    //         if (a[i] < b[j]){
    //             if (fin.back() != a[i]){
    //                 fin.push_back(a[i]);
    //             }
    //             ++i;
    //         }
    //         else if (a[i] > b[j]){
    //             if (fin.back() != b[j]){
    //                 fin.push_back(b[j]);
    //             }
    //             ++j;
    //         }
    //         else if (a[i] == b[j]){
    //             if (fin.back() != a[i]){
    //                 fin.push_back(a[i]);
    //             }
    //             ++i;
    //             ++j;
    //         }
    //         else{
    //             printf("some issue \n");
    //             assert(0);
    //         }
    //     }
    //     if (i == a.size()){
    //         for (; j<b.size(); j++){
    //             if (fin.back() != b[j]){
    //                 fin.push_back(b[j]);
    //             }
    //         }
    //     }
    //     if (j == b.size()){
    //         for (; i<a.size(); i++){
    //             if (fin.back() != a[i]){
    //                 fin.push_back(a[i]);
    //             }
    //         }
    //     }
    //     return fin;
    // }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends