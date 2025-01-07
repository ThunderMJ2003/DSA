//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // void nextPermutation(vector<int>& nums) {
    //     int n = nums.size();
    //     int xi;
    //     for (xi=(n-2); xi>=0; xi--){
    //         if (nums[xi] < nums[xi+1]){
    //             break;
    //         }
    //     }
    //     if (xi == -1){
    //         int i = 0;
    //         int j = n-1;
    //         while(i<j){
    //             swap(nums[i], nums[j]);
    //             ++i;
    //             --j;
    //         }
    //         return;
    //     }
    //     int nxi;
    //     for (nxi=(n-1); nxi>=0; nxi--){
    //         if (nums[nxi] > nums[xi]){
    //             break;
    //         }
    //     }
    //     //printf("here1 \n");
    //     //printf("xi, nxi = %d, %d \n", xi, nxi);
    //     swap(nums[xi], nums[nxi]);
    //     //printf("here2 \n");
    //     int i = xi + 1;
    //     int j = n - 1;
    //     while (i<j){
    //         swap(nums[i], nums[j]);
    //         ++i;
    //         --j;
    //     }
    //     return;
    // }

    // void nextPermutation(vector<int>& nums) {
    //     for (int i=nums.size()-1; i>0; i--){
    //         if (nums[i-1] < nums[i]){
    //             int minind = i-1;
    //             for (int j=i; j<nums.size(); j++){
    //                 int minel = INT_MAX;
    //                 if ((nums[i-1] < nums[j]) && (nums[j] < minel)){
    //                     minel = nums[j];
    //                     minind = j;
    //                 }
    //             }
    //             swap(nums[i-1], nums[minind]);
    //             reverse(nums.begin()+i, nums.end());
    //             return;
    //         }
    //     }
    //     reverse(nums.begin(), nums.end());
    //     return;
    // }

    void nextPermutation(vector<int>& nums){
        next_permutation(nums.begin(), nums.end());
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
	    ob.nextPermutation(A);
        for (int i=0; i<A.size(); i++){
            printf("%d ", A[i]);
        }
        //printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends