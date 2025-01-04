//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int lenOfLongestSubarr(vector<int>& arr, int k) {
    //     int i=0, j=0;
    //     int cursum;
    //     int n = arr.size();
    //     int fin = 0;
    //     for (int i=0; i<n; i++){
    //         cursum = 0;
    //         for (int j=i; j<n; j++){
    //             cursum += arr[j];
    //             //printf("%d \n", cursum);
    //             if (cursum == k){
    //                 fin = max(fin, j-i+1);
    //             }
    //         }
    //     }
    //     return fin;
    // }

    int lenOfLongestSubarr(vector<int>& arr, int k) {
        map<int, int> presum;
        int cursum = 0;
        int n = arr.size();
        int fin = 0;
        for (int i=0; i<n; i++){
            cursum += arr[i];
            if (cursum == k){
                fin = i+1;
            }
            else{
                if (presum.find(cursum-k) != presum.end()){
                    fin = max(fin, i-presum[cursum-k]);
                }
            }
            if (presum.find(cursum) == presum.end()){
                presum[cursum] = i;
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