//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    int findFloor(vector<int>& arr, int x){
        int l = 0, h = arr.size()-1;
        int m = (l+h)/2;
        int fin = -1;
        while (l<=h){
            m = (l+h)/2;
            if (arr[m] <= x){
                fin = max(fin, m);
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        if (fin == -1){
            return fin;
        }
        return arr[fin];
    }
    int findCeil(vector<int>& arr, int x){
        int l = 0, h = arr.size()-1;
        int m = (l+h)/2;
        int fin = arr.size();
        while (l<=h){
            m = (l+h)/2;
            if (arr[m] >= x){
                fin = min(fin, m);
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        if (fin == arr.size()){
            return -1;
        }
        return arr[fin];
    }
    pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x){
        return {findFloor(a, x), findCeil(a, x)};
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
        auto ans = obj.getFloorAndCeil(a, a.size(), n);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        // for (int i=0; i<ans.size(); i++){
        //     for (int j=0; j<ans[i].size(); j++){
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        printf("%d %d \n", ans.first, ans.second);
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends