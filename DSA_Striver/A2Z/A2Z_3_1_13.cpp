//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K){
        map<int, int> presum;
        int tempsum = 0;
        int fin = 0;
        for (int i=0; i<N; i++){
            tempsum += A[i];
            if (tempsum == K) {
                fin = max(fin, i+1);
            }
            int remsum = tempsum - K;
            if (presum.find(remsum) != presum.end()){
                fin = max(fin, i-presum[remsum]);
            }
            if (presum.find(tempsum) == presum.end()){
                presum[tempsum] = i;
            }
        }
        return fin;
    }

    // int lenOfLongSubarr(int A[],  int N, int K){
    //     int isneg = 0;
    //     for (int i=0; i<N; i++){
    //         if (A[i] < 0){
    //             isneg = 1;
    //             break;
    //         }
    //     }
    //     if (isneg==0){

    //     int i = 0;
    //     int j = 0;
    //     int cursum = 0;
    //     int fin = 0;
    //     while (j<N){
    //         if ((cursum==K) && (i<=j)){
    //             fin = max(fin, j-i);
    //             ++i;
    //             cursum -= A[i-1];
    //         }
    //         else if ((cursum > K) && (i<=j)){
    //             ++i;
    //             cursum -= A[i-1];
    //         }
    //         else{
    //             cursum += A[j];
    //             ++j;
    //         }
    //     }
    //     return fin;
    //     }
    //     else{

    //     // Complete the function
    //     int maxdif = 0;
    //     if (A[0]==K){
    //         maxdif = 1;
    //     }
    //     int cursum = A[0];
    //     for (int j=1; j<N; j++){
    //         cursum = cursum + A[j];
    //         if (cursum==K){
    //             maxdif = max(maxdif, j+1);
    //         }
    //     }
    //     for (int i=1; i<N; i++){
    //         for (int j=i; j<N; j++){
    //             if (i==j){
    //                 cursum = A[i];
    //                 if (cursum==K){
    //                     maxdif = max(maxdif, 1);
    //                 }
    //             }
    //             if (i<j){
    //                 cursum = cursum + A[j];
    //                 if (cursum==K){
    //                     maxdif = max(maxdif, j-i+1);
    //                 }
    //             }
    //         }
    //     }
    //     return maxdif;
    //     }
    // } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int A[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(A, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends