//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // string longestCommonPrefix(vector<string>& strs){ // O(n*w), O(w), n = strs.size(), w = strs[0].size()
    //     string prefix = strs[0];
    //     for (int i=0; i<strs.size(); i++){
    //         int j;
    //         for (j=0; j<min(strs[i].length(), prefix.length()); j++){
    //             if (prefix[j] != strs[i][j]){
    //                 break;
    //             }
    //         }
    //         prefix = prefix.substr(0, min(j, (int)strs[i].length()));
    //         if (prefix == ""){
    //             break;
    //         }
    //     }
    //     return prefix;
    // }

    string longestCommonPrefix(vector<string>& strs){ // O(nlogn+w), O(1), n = strs.size(), w = strs[0].size()
        sort(strs.begin(), strs.end());
        int i;
        for (i=0; i<min(strs[0].length(), strs.back().length()); i++){
            if (strs[0][i] != strs.back()[i]){
                break;
            }
        }
        return strs[0].substr(0, i);
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        // int m;
        // cin >> m;
        // cin.ignore();
        // int n;
        // cin >> n;
        // cin.ignore();
        // vector<vector<int>> a;
        // for (int i=0; i<m; i++){
        //     vector<int> t;
        //     for (int j=0; j<n; j++){
        //         int x;
        //         cin >> x;
        //         t.push_back(x);
        //     }
        //     a.push_back(t);
        //     t.clear();
        // }

        // int n;
        // cin >> n;
        // cin.ignore();

        // vector<int> a;
        // string input;

        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // int num;
        // while (ss >> num)
        //     a.push_back(num); // Read the array elements from input string

        string input;
        getline(cin, input);
        stringstream ss(input);
        string st;
        vector<string> a;
        while (ss >> st)
            a.push_back(st);

        Solution obj;
        auto ans = obj.longestCommonPrefix(a);

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