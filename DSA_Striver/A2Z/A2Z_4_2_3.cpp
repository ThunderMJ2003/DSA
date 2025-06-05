//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    long long totalTime(vector<int>& piles, int k){
        long long fin = 0;
        for (int i : piles){
            fin += ceil((double)i/k);
        }
        return fin;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int low = ceil((double)totalTime(piles, 1)/h), high = piles[max_element(piles.begin(), piles.end()) - piles.begin()];
        cout << totalTime(piles, 1)/h << endl;
        int mid;
        int fin = (low + high)/2;
        int temp;
        while (low <= high){
            mid = (low + high)/2;
            temp = totalTime(piles, mid);
            if (temp <= h){
                fin = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return fin;
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
        int ans = obj.minEatingSpeed(a, n);

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