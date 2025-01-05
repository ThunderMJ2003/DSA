//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     map<int, int> freqmap;
    //     for (int i=0; i<nums.size(); i++){
    //         ++freqmap[nums[i]];
    //         if (freqmap[nums[i]] > (nums.size()/2)){
    //             return nums[i];
    //         }
    //     }
    //     return 0;
    // }

    int majorityElement(vector<int>& nums){
        int x = nums[0];
        int cnt = 1;
        for (int i=1; i<nums.size(); i++){
            if (cnt == 0){
                x = nums[i];
                ++cnt;
            }
            else if (nums[i] == x){
                ++cnt;
            }
            else if (nums[i] != x){
                --cnt;
            }
            else{
                assert(0);
            }
        }
        return x;
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
	    int fin = ob.majorityElement(A);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends