//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // long subarrayXor(vector<int> &arr, int k) {
        //     long fin = 0;
        //     int curxor = 0;
        //     for (int i=0; i<arr.size(); i++){
        //         curxor = 0;
        //         for (int j=i; j<arr.size(); j++){
        //             curxor = curxor ^ arr[j];
        //             if (curxor == k){
        //                 ++fin;
        //             }
        //         }
        //     }
        //     return fin;
        // }

        long subarrayXor(vector<int> &arr, int k){
            unordered_map<int, int> presumset;
            int curxor = 0;
            int fin = 0;
            ++presumset[0];
            for (int i=0; i<arr.size(); i++){
                curxor = curxor ^ arr[i];
                if (presumset[curxor^k] != 0){
                    fin = fin + presumset[curxor^k];
                }
                ++presumset[curxor];
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
        long ans = obj.subarrayXor(a, n);

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