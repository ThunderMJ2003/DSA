//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // string reverseWords(string s){ // O(n), O(n)
    //     stringstream ss(s);
    //     string st;
    //     vector<string> vecs;
    //     string fin = "";
    //     while (ss >> st){
    //         vecs.push_back(st);
    //     }
    //     for (int i=(vecs.size()-1); i>=0; i--){
    //         fin.append(vecs[i]);
    //         fin.append(" ");
    //     }
    //     return fin.substr(0, fin.size()-1);
    // }

    string reverseWords(string s){ // O(n), O(n)
        string tempword = "";
        string fin = "";
        for (char c : s){
            if (c != ' '){
                tempword += c;
            }
            else if (tempword != ""){
                fin = tempword + " " + fin;
                tempword = "";
            }
        }
        if (tempword != ""){
            fin = tempword + " " + fin;
        }
        return fin.substr(0, fin.size()-1);
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

        Solution obj;
        auto ans = obj.reverseWords(a);

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