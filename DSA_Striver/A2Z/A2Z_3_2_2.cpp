//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     vector<int> newnums;
    //     for (int i=0; i<nums.size(); i++){
    //         if (nums[i]==0){
    //             newnums.push_back(nums[i]);
    //         }
    //     }
    //     for (int i=0; i<nums.size(); i++){
    //         if (nums[i]==1){
    //             newnums.push_back(nums[i]);
    //         }
    //     }
    //     for (int i=0; i<nums.size(); i++){
    //         if (nums[i]==2){
    //             newnums.push_back(nums[i]);
    //         }
    //     }
    //     nums = newnums;
    // }

    // void sortColors(vector<int>& nums){
    //     int a=0, b=0, c=0;
    //     for (int i=0; i<nums.size(); i++){
    //         if (nums[i]==0){
    //             ++a;
    //         }
    //         if (nums[i]==1){
    //             ++b;
    //         }
    //         if (nums[i]==2){
    //             ++c;
    //         }
    //     }
    //     int ind = 0;
    //     for (int i=0; i<a; i++){
    //         nums[ind] = 0;
    //         ++ind;
    //     }
    //     for (int i=0; i<b; i++){
    //         nums[ind] = 1;
    //         ++ind;
    //     }
    //     for (int i=0; i<c; i++){
    //         nums[ind] = 2;
    //         ++ind;
    //     }
    // }

    // void sortColors(vector<int>& nums) {
    //     int n = nums.size();
    //     int i=0;
    //     for (int j=i; j<n; j++){
    //         if (nums[j] == 0){
    //             swap(nums[i], nums[j]);
    //             ++i;
    //         }
    //     }
    //     for (int j=i; j<n; j++){
    //         if (nums[j] == 1){
    //             swap(nums[i], nums[j]);
    //             ++i;
    //         }
    //     }
    // }

    // void sortColors(vector<int>& nums){
    //     int l=0, m=0, h=nums.size()-1;
    //     while ((l<=m) && (m<=h)){
    //         if (nums[m] == 0){
    //             int t = nums[m];
    //             nums[m] = nums[l];
    //             nums[l] = t;
    //             ++l;
    //             ++m;
    //         }
    //         else if (nums[m] == 1){
    //             ++m;
    //         }
    //         else if (nums[m] == 2){
    //             int t = nums[m];
    //             nums[m] = nums[h];
    //             nums[h] = t;
    //             --h;
    //         }
    //         else{
    //             assert(0);
    //         }
    //     }
    // }

    void sortColors(vector<int>& nums){
        int n = nums.size();
        int i=0, j=(n-1);
        int k = 0;
        while (k<=j){
            if (nums[k] == 2){
                swap(nums[k], nums[j]);
                --j;
            }
            else if (nums[k] == 0){
                swap(nums[k], nums[i]);
                ++i;
                ++k;
            }
            else if (nums[k] == 1){
                ++k;
            }
            else{
                printf("some issue \n");
                assert(0);
            }
        }
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
        ob.sortColors(A);
        for (int i=0; i<A.size(); i++){
            printf("%d ", A[i]);
        }
        // printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends