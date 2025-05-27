//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
        //     int gridsum = 0;
        //     int n = grid.size();
        //     unordered_set<int> gridset;
        //     vector<int> fin;
        //     for (int i=0; i<n; i++){
        //         for (int j=0; j<n; j++){
        //             gridsum = gridsum + grid[i][j];
        //             gridset.insert(grid[i][j]);
        //         }
        //     }
        //     int x = 1;
        //     for (int i=0; i<n; i++){
        //         for (int j=0; j<n; j++){
        //             if (gridset.find(x) == gridset.end()){
        //                 fin.push_back(gridsum + x - (n*n)*((n*n)+1)/2);
        //                 fin.push_back(x);
        //                 return fin;
        //             }
        //             ++x;
        //         }
        //     }
        //     return fin;
        // }

        // vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
        //     int n = grid.size();
        //     int N = n*n;
        //     long long gridsum = 0, gridsqsum = 0, SN = (long long)N*(N+1)/2, SN2 = (long long)N*(N+1)*(2*N+1)/6;
        //     for (auto i : grid){
        //         for (auto j : i){
        //             gridsum += j;
        //             gridsqsum += (j*j);
        //         }
        //     }
        //     return {(int)(-SN + gridsum + ((SN2 - gridsqsum) / (SN - gridsum)))/2, (int)(SN - gridsum + ((SN2 - gridsqsum) / (SN - gridsum)))/2};
        // }
        
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
            int n = grid.size();
            int gridnxor = 0;
            int x = 1;
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    gridnxor = gridnxor ^ grid[i][j] ^ x;
                    ++x;
                }
            }
            int onebitpos = 0;
            while (1){
                if ((gridnxor & (1<<onebitpos)) != 0){
                    break;
                }
                ++onebitpos;
            }
            int zeroxor = 0, onexor = 0;
            x = 1;
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if ((grid[i][j] & (1<<onebitpos)) == 0){
                        zeroxor = zeroxor ^ grid[i][j];
                    }
                    else{
                        onexor = onexor ^ grid[i][j];
                    }
                    if ((x & (1<<onebitpos)) == 0){
                        zeroxor = zeroxor ^ x;
                    }
                    else{
                        onexor = onexor ^ x;
                    }
                    ++x;
                }
            }
            for (auto i : grid){
                for (auto j : i){
                    if (j == onexor){
                        return {onexor, zeroxor};
                    }
                    if (j == zeroxor){
                        return {zeroxor, onexor};
                    }
                }
            }
            return {-1, -1};
        }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> a;
        for (int i=0; i<n; i++){
            vector<int> t;
            for (int j=0; j<n; j++){
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
        vector<int> ans = obj.findMissingAndRepeatedValues(a);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            printf("%d ", ans[i]);
        }
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