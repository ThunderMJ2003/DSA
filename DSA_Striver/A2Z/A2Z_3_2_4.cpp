//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int tsum = nums[0];
    //     int maxsum = nums[0];
    //     int n = nums.size();
    //     for (int i=1; i<n; i++){
    //         if (tsum < 0){
    //             tsum = 0;
    //             tsum += nums[i];
    //         }
    //         else{
    //             tsum += nums[i];
    //         }
    //         maxsum = max(maxsum, tsum);
    //     }
    //     return maxsum;
    // }

    int maxSubArray(vector<int>& nums) {
        int cursum=0, maxsum=nums[0];
        for (int i=0; i<nums.size(); i++){
            cursum += nums[i];
            if (cursum < 0){
                cursum = 0;
            }
            else{
                maxsum = max(maxsum, cursum);
            }
            maxsum = max(maxsum, nums[i]);
        }
        return maxsum;
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
	    int fin = ob.maxSubArray(A);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends