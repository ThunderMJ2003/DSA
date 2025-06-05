//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    int numberOfDays(vector<int>& weights, int c){
        int fin = 1;
        int curweight = 0;
        for (int i=0; i<(weights.size()-1); i++){
            if (weights[i] > c){
                return INT_MAX;
            }
            if ((curweight+weights[i]) > c){
                ++fin;
                curweight = weights[i];
            }
            else{
                curweight += weights[i];
            }
        }
        if (weights.back() > c){
            return INT_MAX;
        }
        if ((curweight+weights.back()) > c){
            ++fin;
        }
        return fin;
    }
    int shipWithinDays(vector<int>& weights, int days){
        int weightssum = 0;
        for (int i : weights){
            weightssum += i;
        }
        int l = weightssum/days, h = weightssum;
        int m;
        int tempDays;
        while (l <= h){
            m = (l+h)/2;
            tempDays = numberOfDays(weights, m);
            if (tempDays <= days){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l;
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
        int ans = obj.shipWithinDays(a, n);

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