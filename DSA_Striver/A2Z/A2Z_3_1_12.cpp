//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     if (nums.size()==1){
    //         return nums[0];
    //     }
    //     if (nums[0]!=nums[1]){
    //         return nums[0];
    //     }
    //     for (int i=1; i<(nums.size()-1); i++){
    //         if ((nums[i-1] != nums[i]) && (nums[i] != nums[i+1])){
    //             return nums[i];
    //         }
    //     }
    //     return nums.back();
    // }
    
    int singleNumber(vector<int>& nums){
        int fin = nums[0];
        for (int i=1; i<nums.size(); i++){
            fin ^= nums[i];
        }
        return fin;
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
	    auto ans = ob.singleNumber(arr);
        cout << ans;
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends