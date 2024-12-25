//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int maxreach = 0;
        int jumps = 0;
        int lastindexwithsamejumps = 0;
        int n = arr.size();
        for (int i=0; i<n; i++){
            maxreach = max(maxreach, arr[i]+i);
            if (maxreach >= (n-1)){
                return jumps+1;
            }
            if (i == lastindexwithsamejumps){
                if (lastindexwithsamejumps == maxreach){
                    return -1;
                }
                lastindexwithsamejumps = maxreach;
                ++jumps;
            }
        }
        return -2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends