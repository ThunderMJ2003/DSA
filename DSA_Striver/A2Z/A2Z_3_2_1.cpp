//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     vector<int> fin(2);
    //     for (int i=0; i<(n-1); i++){
    //         for (int j=(i+1); j<n; j++){
    //             if ((nums[i]+nums[j]) == target){
    //                 fin[0] = i;
    //                 fin[1] = j;
    //                 return fin;
    //             }
    //         }
    //     }
    //     printf("some issue \n");
    //     assert(0);
    // }
    // this took O(n^2) time complexity

    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> newnums;
        vector<int> fin = {-1, -1};
        for (int i=0; i<nums.size(); i++){
            if (newnums.find(target - nums[i]) != newnums.end()){
                fin[0] = newnums[target - nums[i]];
                fin[1] = i;
                return fin;
            }
            newnums[nums[i]] = i;
        }
        return fin;
    }
    // this took O(nlogn) time complexity
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
    cin>>t;
	while(t--)
	{
        int target;
        int n;
        cin >> n;
        cin >> target;
	    vector<int> A(n);
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    Solution ob;
	    vector<int> fin = ob.twoSum(A, target);
        for (int i=0; i<fin.size(); i++){
            printf("%d ", fin[i]);
        }
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends