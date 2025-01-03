//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // int findMaxConsecutiveOnes(vector<int>& nums){
    //     int fin = 0;
    //     int n = nums.size();
    //     int j=-1;
    //     for (int i=0; i<n; i++){
    //         if (nums[i]==1){
    //             j = i;
    //             break;
    //         }
    //     }
    //     if (j==(-1)){
    //         return fin;
    //     }
    //     int tempfin = 0;
    //     for (int i=j; i<n; i++){
    //         if (nums[i]==1){
    //             ++tempfin;
    //             fin = max(fin, tempfin);
    //         }
    //         else{
    //             tempfin = 0;
    //         }
    //     }
    //     return fin;
    // }

    // int findMaxConsecutiveOnes(vector<int>& nums) {
    //     int i = 0;
    //     int j = 0;
    //     int fin = 0;
    //     for (; j<nums.size(); j++){
    //         if (nums[j] == 0){
    //             break;
    //         }
    //     }
    //     fin = max(fin, j-i);
    //     for (int k=j; k<nums.size(); k++){
    //         if (nums[k] == 0){
    //             i = j;
    //             j = k;
    //             fin = max(fin, j-i-1);
    //         }
    //     }
    //     return max(fin, (int)(nums.size()-1-j));
    // }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt=0, curcnt=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 0){
                maxcnt = max(maxcnt, curcnt);
                curcnt = 0;
            }
            else{
                ++curcnt;
            }
        }
        return max(maxcnt, curcnt);
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
	    auto ans = ob.findMaxConsecutiveOnes(arr);
        cout << ans;
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends