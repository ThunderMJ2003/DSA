//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // string longestPalindrome(string s){ // O(n^3), O(n)
    //     int x, y;
    //     string fin = "";
    //     int isPalindrome = 1;
    //     for (int i=0; i<s.size(); i++){
    //         for (int j=i; j<s.size(); j++){
    //             x = i;
    //             y = j;
    //             isPalindrome = 1;
    //             while (x < y){
    //                 if (s[x] != s[y]){
    //                     isPalindrome = 0;
    //                     break;
    //                 }
    //                 ++x;
    //                 --y;
    //             }
    //             if (isPalindrome && ((j-i+1) > fin.size())){
    //                 fin = s.substr(i, j-i+1);
    //             }
    //         }
    //     }
    //     return fin;
    // }

    string longestPalindrome(string s){ // O(n^2), O(n)
        string fin = "";
        int x, y;
        for (int i=0; i<s.size(); i++){
            x = i;
            y = i;
            while ((x>=0) && (y<s.size())){
                if (s[x] != s[y]){
                    break;
                }
                --x;
                ++y;
            }
            if (fin.size() < (y-x-1)){
                fin = s.substr(x+1, y-x-1);
            }
            if (i == (s.size()-1)){
                continue;
            }
            x = i;
            y = i+1;
            while ((x>=0) && (y<s.size())){
                if (s[x] != s[y]){
                    break;
                }
                --x;
                ++y;
            }
            if (fin.size() < (y-x-1)){
                fin = s.substr(x+1, y-x-1);
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

        string a;
        getline(cin, a);
        // string b;
        // getline(cin, b);
        // stringstream ss(input);
        // string st;
        // vector<string> a;
        // while (ss >> st)
        //     a.push_back(st);

        Solution obj;
        auto ans = obj.longestPalindrome(a);

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