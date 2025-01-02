//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // int searchInSorted(int arr[], int N, int K) 
    // { 
    //     int i = 0;
    //     int j = N-1;
    //     int found = -1;
    //     int x;
    //     while ((i<=j) && (found==-1)){
    //         x = (i+j)/2;
    //         if (arr[x]==K){
    //             return 1;
    //         }
    //         else if (arr[x] < K){
    //             i = x+1;
    //         }
    //         else{
    //             j = x-1;
    //         }
    //     }
    //     return found;
    // }
    
    bool searchInSorted(int arr[], int n, int k) {
        int l=0, h=(n-1);
        while (l<=h){
            if (arr[(l+h)/2] == k){
                return true;
            }
            else if (arr[(l+h)/2] > k){
                h = (l+h)/2 - 1;
            }
            else if (arr[(l+h)/2] < k){
                l = (l+h)/2 + 1;
            }
            else{
                printf("some issue \n");
                assert(0);
            }
        }
        return false;
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends