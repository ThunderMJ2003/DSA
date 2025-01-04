//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        int i=0, j=0;
        int cursum = arr[0];
        int n = arr.size();
        int fin = 0;
        while (j<n){
            if (cursum < k){
                ++j;
                cursum += arr[j];
            }
            else if (cursum > k){
                cursum -= arr[i];
                ++i;
            }
            else if (cursum == k){
                fin = max(fin, j-i+1);
                ++j;
                cursum += arr[j];
            }
            else{
                printf("some issue \n");
                assert(0);
            }
        }
        return fin;
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

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends