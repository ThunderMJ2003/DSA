//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    bool isPossible(vector<int> &stalls, int k, int g){
        int numberOfCowsPlaced = 1;
        int lastCowPlacedAt = stalls[0];
        for (int i : stalls){
            if ((i-lastCowPlacedAt) >= g){
                lastCowPlacedAt = i;
                ++numberOfCowsPlaced;
                if (numberOfCowsPlaced >= k){
                    break;
                }
            }
        }
        if (numberOfCowsPlaced >= k){
            return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k){
        sort(stalls.begin(), stalls.end());
        int l = 1, h = ceil((double)(stalls.back()-stalls[0])/(k-1));
        int m;
        while (l <= h){
            m = (l+h)/2;
            if (isPossible(stalls, k, m)){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        // int n;
        // cin >> n;
        // cin.ignore();
        // vector<vector<int>> a;
        // for (int i=0; i<n; i++){
        //     vector<int> t;
        //     for (int j=0; j<n; j++){
        //         int x;
        //         cin >> x;
        //         t.push_back(x);
        //     }
        //     a.push_back(t);
        //     t.clear();
        // }

        int n;
        cin >> n;
        cin.ignore();

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        int ans = obj.aggressiveCows(a, n);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        // for (int i=0; i<ans.size(); i++){
        //     for (int j=0; j<ans[i].size(); j++){
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends