//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals){
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> fin;
            int lowerbound = intervals[0][0], upperbound = intervals[0][1];
            vector<int> tempvec(2);
            for (int i=1; i<intervals.size(); i++){
                if (intervals[i][0] > upperbound){
                    tempvec[0] = lowerbound;
                    tempvec[1] = upperbound;
                    fin.push_back(tempvec);
                    lowerbound = intervals[i][0];
                    upperbound = intervals[i][1];
                }
                else{
                    if (intervals[i][1] > upperbound){
                        upperbound = intervals[i][1];
                    }
                }
            }
            tempvec[0] = lowerbound;
            tempvec[1] = upperbound;
            fin.push_back(tempvec);
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
        vector<vector<int>> a;
        for (int i=0; i<n; i++){
            vector<int> t;
            for (int j=0; j<2; j++){
                int x;
                cin >> x;
                t.push_back(x);
            }
            a.push_back(t);
            t.clear();
        }

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

        Solution obj;
        vector<vector<int>> ans = obj.merge(a);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        for (int i=0; i<ans.size(); i++){
            for (int j=0; j<ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends