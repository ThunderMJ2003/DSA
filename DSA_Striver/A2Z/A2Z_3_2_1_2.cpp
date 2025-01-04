//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // string read(int n, vector<int> nums, int target){
    //     map<int, int> mppnums;
    //     mppnums[nums[0]] = 0;
    //     for (int i=1; i<n; i++){
    //         if (mppnums.find(target - nums[i]) != mppnums.end()){
    //             return "YES";
    //         }
    //         mppnums[nums[i]] = i;
    //     }
    //     return "NO";
    // }

    string read(int n, vector<int> nums, int target){
        sort(nums.begin(), nums.end());
        int i=0, j=n-1;
        vector<int> fin(2);
        while (i<j){
            if ((nums[i]+nums[j]) == target){
                return "YES";
            }
            else if ((nums[i]+nums[j]) > target){
                --j;
            }
            else{
                ++i;
            }
        }
        return "NO";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution ob;
        string ans = ob.read(arr.size(), arr, k);
        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends