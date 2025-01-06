//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     int curind = 0;
    //     int posi;
    //     int negi;
    //     int n = nums.size();
    //     vector<int> fin(n);
    //     for (int i=0; i<n; i++){
    //         if (nums[i] > 0){
    //             posi = i;
    //             break;
    //         }
    //     }
    //     for (int i=0; i<n; i++){
    //         if (nums[i] < 0){
    //             negi = i;
    //             break;
    //         }
    //     }
    //     while (curind < n){
    //         if ((curind%2) == 0){
    //             fin[curind] = nums[posi];
    //             ++curind;
    //             for (int i=(posi+1); i<n; i++){
    //                 if (nums[i] > 0){
    //                     posi = i;
    //                     break;
    //                 }
    //             }
    //         }
    //         else if ((curind%2) == 1){
    //             fin[curind] = nums[negi];
    //             ++curind;
    //             for (int i=(negi+1); i<n; i++){
    //                 if (nums[i] < 0){
    //                     negi = i;
    //                     break;
    //                 }
    //             }
    //         }
    //         else{
    //             assert(0);
    //         }
    //     }
    //     return fin;
    // }

    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> fin(nums.size());
        int i=0, j=1;
        for (int k=0; k<nums.size(); k++){
            if (nums[k] > 0){
                fin[i] = nums[k];
                i += 2;
            }
            else{
                fin[j] = nums[k];
                j += 2;
            }
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
	    vector<int> A(n);
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    Solution ob;
	    vector<int> fin = ob.rearrangeArray(A);
        for (int i=0; i<fin.size(); i++){
            printf("%d ", fin[i]);
        }
        //printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends