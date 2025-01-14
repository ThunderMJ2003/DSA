//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int subarraySum(vector<int>& nums, int k) {
    //     int cursum = nums[0];
    //     int fin = 0;
    //     int n = nums.size();
    //     for (int i=0; i<n; i++){
    //         cursum = nums[i];
    //         if (cursum == k){
    //             ++fin;
    //         }
    //         for (int j=(i+1); j<n; j++){
    //             cursum += nums[j];
    //             if (cursum == k){
    //                 ++fin;
    //             }
    //         }
    //     }
    //     return fin;
    // }

    // int subarraySum(vector<int>& nums, int k){
    //     map<int, int> presum;
    //     int cursum = 0;
    //     int fin = 0;
    //     for (int i=0; i<nums.size(); i++){
    //         cursum += nums[i];
    //         ++presum[cursum];
    //         if (k!=0){
    //             fin += (!(bool)(cursum-k)) + presum[cursum-k]; //adding 1 only if cursum==k
    //         }
    //         else{
    //             fin += (!(bool)(cursum-k)) + presum[cursum-k]-1; //not counting empty subarrays
    //         }
    //         //printf("i fin = %d %d \n", i, fin);
    //     }
    //     return fin;
    // }

    // int subarraySum(vector<int>& nums, int k){
    //     unordered_map<int, int> presum;
    //     int cursum = 0;
    //     int fin = 0;
    //     for (int i=0; i<nums.size(); i++){
    //         cursum += nums[i];
    //         ++presum[cursum];
    //         if (k!=0){
    //             fin += (!(bool)(cursum-k)) + presum[cursum-k]; //adding 1 only if cursum==k
    //         }
    //         else{
    //             fin += (!(bool)(cursum-k)) + presum[cursum-k]-1; //not counting empty subarrays
    //         }
    //         //printf("i fin = %d %d \n", i, fin);
    //     }
    //     return fin;
    // }

    // int subarraySum(vector<int>& nums, int k){
    //     map<int, int> presum;
    //     int cursum = 0;
    //     int fin = 0;
    //     presum[0] = 1;
    //     for (int i=0; i<nums.size(); i++){
    //         cursum += nums[i];
    //         fin += presum[cursum-k];
    //         ++presum[cursum];
    //     }
    //     return fin;
    // }

    int subarraySum(vector<int>& nums, int k){
        unordered_map<int, int> presum;
        int cursum = 0;
        int fin = 0;
        presum[0] = 1;
        for (int i=0; i<nums.size(); i++){
            cursum += nums[i];
            fin += presum[cursum-k];
            ++presum[cursum];
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
        int k;
        cin >> k;
	    vector<int> A(n);
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    Solution ob;
	    int fin = ob.subarraySum(A, k);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends