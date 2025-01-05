//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    long long maxSubarraySum(vector<int> nums, int n){
        long long cursum=0, maxsum=nums[0];
        for (int i=0; i<n; i++){
            cursum += nums[i];
            if (cursum < 0){
                cursum = 0;
            }
            maxsum = max(maxsum, cursum);
        }
        return maxsum;
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

        Solution ob;
        cout << ob.maxSubarraySum(arr, arr.size());
        // for (int i=0; i<arr.size(); i++){
        //     cout << arr[i] << " ";
        // }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends