//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int maxprof = 0;
    //     int minp = prices[0];
    //     for (int i=1; i<prices.size(); i++){
    //         if (prices[i] < minp){
    //             minp = prices[i];
    //         }
    //         else{
    //             maxprof = max(maxprof, prices[i] - minp);
    //         }
    //     }
    //     return maxprof;
    // }

    int maxProfit(vector<int>& prices) {
        int buyprice=prices[0];
        int maxfin = 0;
        for (int i=0; i<prices.size(); i++){
            buyprice = min(buyprice, prices[i]);
            maxfin = max(maxfin, prices[i] - buyprice);
        }
        return maxfin;
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
	    vector<int> A(n);
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    Solution ob;
	    int fin = ob.maxProfit(A);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends