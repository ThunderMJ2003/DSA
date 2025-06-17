//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    int myAtoi(string s){ // O(n), O(1)
        int posorneg = 1;
        int i = 0;
        for (i=0; i<s.size(); i++){
            if ((s[i] == '+') || ((s[i] >= '0') && (s[i] <= '9'))){
                break;
            }
            else if (s[i] == '-'){
                posorneg = -1;
                break;
            }
            else if ((s[i] == '.') || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))){
                return 0;
            }
        }
        if ((s[i] == '+') || (s[i] == '-')){
            ++i;
        }
        long long fin = 0;
        while ((i < s.size()) && (s[i] >= '0') && (s[i] <= '9')){
            if (posorneg == 1){
                fin = fin*10 + (s[i]-'0');
                if (fin != (int)fin){
                    return INT_MAX;
                }
            }
            else{
                fin = fin*10 - (s[i]-'0');
                if (fin != (int)fin){
                    return INT_MIN;
                }
            }
            ++i;
        }
        return (int)fin;
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
        auto ans = obj.myAtoi(a);

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