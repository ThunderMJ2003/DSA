//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int missingNumber(vector<int>& nums) {
    //     vector<int> ifexists(nums.size()+1, 0);
    //     for (int i=0; i<nums.size(); i++){
    //         ifexists[nums[i]] = 1;
    //     }
    //     for (int i=0; i<ifexists.size(); i++){
    //         if (ifexists[i]==0){
    //             return i;
    //         }
    //     }
    // }

    // int missingNumber(vector<int>& nums){
    //     int n = nums.size();
    //     int fin = 0;
    //     for (int i=0; i<nums.size(); i++){
    //         fin += nums[i];
    //     }
    //     return ((n*(n+1)/2) - fin);
    // }

    int missingNumber(vector<int>& nums){
        int xor1=0, xor2=0;
        for (int i=0; i<nums.size(); i++){
            xor1 ^= (i+1);
            xor2 ^= (nums[i]);
        }
        return xor1^xor2;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N;
	    cin >>N;
	    
	    vector<int> arr(N);
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr[i];
	    }
	    
	    Solution ob;
	    auto ans = ob.missingNumber(arr);
        cout << ans;
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends