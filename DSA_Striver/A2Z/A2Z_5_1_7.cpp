//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // bool isAnagram(string s, string t){ // O(n) using unordered_map, O(n)
    //     if (s.size() != t.size()){
    //         return false;
    //     }
    //     unordered_map<char, int> sa;
    //     unordered_map<char, int> ta;
    //     for (int i=0; i<s.size(); i++){
    //         ++sa[s[i]];
    //         ++ta[t[i]];
    //     }
    //     for (auto i : sa){
    //         if (i.second != ta[i.first]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool isAnagram(string s, string t){ // O(n), O(1)
        if (s.size() != t.size()){
            return false;
        }
        vector<int> sa(26, 0);
        vector<int> ta(26, 0);
        for (int i=0; i<s.size(); i++){
            ++sa[s[i]-'a'];
            ++ta[t[i]-'a'];
        }
        if (sa != ta){
            return false;
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
        auto ans = obj.isAnagram(a, b);

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