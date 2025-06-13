//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // bool rotateString(string s, string goal){ // O(n*n), O(1)
    //     if (s.size() != goal.size()){
    //         return false;
    //     }
    //     for (int k=0; k<s.size(); k++){
    //         if ((s.substr(k, s.size())+s.substr(0, k)) == goal){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // bool rotateString(string s, string goal){ // O(n*n), O(1)
    //     if (s.size() != goal.size()){
    //         return false;
    //     }
    //     int istrue;
    //     for (int i=0; i<goal.size(); i++){
    //         if (goal[i] == s[0]){
    //             istrue = 1;
    //             for (int j=0; j<s.size(); j++){
    //                 if (s[j] != goal[(j+i)%goal.size()]){
    //                     istrue = 0;
    //                     break;
    //                 }
    //             }
    //             if (istrue == 1){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // bool rotateString(string s, string goal){ // O(s.size()*goal.size()), O(s.size())
    //     if (s.size() != goal.size()){
    //         return false;
    //     }
    //     string ss = s + s;
    //     if (ss.find(goal) == -1){
    //         return false;
    //     }
    //     return true;
    // }

    bool rotateString(string s, string goal){ // O(s.size()+goal.size()) supposedly when using KMP algo, O(s.size()+goal.size())
        if (s.size() != goal.size()){
            return false;
        }
        vector<int> lps;
        int curlen = 0;
        lps.push_back(0);
        for (int i=1; i<goal.size(); i++){
            if (goal[i] == goal[curlen]){
                ++curlen;
                lps.push_back(curlen);
            }
            else{
                while (curlen != 0){
                    curlen = lps[curlen-1];
                    if (goal[i] == goal[curlen]){
                        ++curlen;
                        lps.push_back(curlen);
                        break;
                    }
                }
                if (curlen == 0){
                    lps.push_back(curlen);
                }
            }
        }
        int j = 0;
        s = s + s;
        for (int i=0; i<s.size(); i++){
            if (s[i] == goal[j]){
                ++j;
            }
            else{
                if (j != 0){
                    j = lps[j-1];
                    --i;
                }
            }
            if (j >= goal.size()){
                return true;
            }
        }
        return false;
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
        auto ans = obj.rotateString(a, b);

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