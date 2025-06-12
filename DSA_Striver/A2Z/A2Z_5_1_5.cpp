//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // bool isIsomorphic(string s, string t){ // O(n), O(n), assuming O(1) for finding in unordered_map
    //     if (s.length() != t.length()){
    //         return false;
    //     }
    //     unordered_map<char, char> stot;
    //     unordered_map<char, char> ttos;
    //     for (int i=0; i<s.length(); i++){
    //         if (stot.find(s[i]) == stot.end()){
    //             stot[s[i]] = t[i];
    //         }
    //         else{
    //             if (stot[s[i]] != t[i]){
    //                 return false;
    //             }
    //         }
    //         if (ttos.find(t[i]) == ttos.end()){
    //             ttos[t[i]] = s[i];
    //         }
    //         else{
    //             if (ttos[t[i]] != s[i]){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool isIsomorphic(string s, string t){ // O(n), O(1)
        if (s.length() != t.length()){
            return false;
        }
        vector<char> stot(128, -1);
        vector<char> ttos(128, -1);
        for (int i=0; i<s.length(); i++){
            if (stot[s[i]] == -1){
                stot[s[i]] = t[i];
            }
            else{
                if (stot[s[i]] != t[i]){
                    return false;
                }
            }
            if (ttos[t[i]] == -1){
                ttos[t[i]] = s[i];
            }
            else{
                if (ttos[t[i]] != s[i]){
                    return false;
                }
            }
        }
        return true;
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

        string a, b;
        getline(cin, a);
        getline(cin, b);
        // stringstream ss(input);
        // string st;
        // vector<string> a;
        // while (ss >> st)
        //     a.push_back(st);

        Solution obj;
        auto ans = obj.isIsomorphic(a, b);

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