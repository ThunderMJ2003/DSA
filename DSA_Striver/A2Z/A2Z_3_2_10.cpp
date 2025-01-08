//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int prevmin = INT_MIN;
    //     int curcnt = 0;
    //     int cntmax = 0;
    //     for (int i=0; i<nums.size(); i++){
    //         //printf("%d ", prevmin);
    //         if (nums[i] == (prevmin+1)){
    //             prevmin = nums[i];
    //             ++curcnt;
    //             cntmax = max(cntmax, curcnt);
    //         }
    //         else if (nums[i] != prevmin){
    //             prevmin = nums[i];
    //             curcnt = 1;
    //             cntmax = max(cntmax, curcnt);
    //         }
    //     }
    //     //printf("\n");
    //     return cntmax;
    // }

    // int longestConsecutive(vector<int>& nums) {
    //     if (nums.size() == 0){
    //         return 0;
    //     }
    //     sort(nums.begin(), nums.end());
    //     int maxcnt=1, curcnt=1;
    //     for (int i=1; i<nums.size(); i++){
    //         if ((nums[i]-nums[i-1]) <= 1){
    //             ++curcnt;
    //         }
    //         else{
    //             curcnt = 1;
    //         }
    //         maxcnt = max(maxcnt, curcnt);
    //     }
    //     return maxcnt;
    // }

    int longestConsecutive(vector<int>& nums){
        unordered_set<int> setnums;
        for (int i=0; i<nums.size(); i++){
            setnums.insert(nums[i]);
        }
        int maxcnt=0, curcnt=0;
        for (int i : setnums){
            if (setnums.find(i-1) == setnums.end()){
                cout << i << endl;
                curcnt = 1;
                int x = i+1;
                while (1){
                    if (setnums.find(x) != setnums.end()){
                        ++curcnt;
                        ++x;
                    }
                    else{
                        break;
                    }
                }
                maxcnt = max(maxcnt, curcnt);
            }
        }
        return maxcnt;
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
	    int fin = ob.longestConsecutive(A);
        // for (int i=0; i<fin.size(); i++){
        //     printf("%d ", fin[i]);
        // }
        printf("%d", fin);
        printf("\n");
	}
	
	return 0;
}
// } Driver Code Ends