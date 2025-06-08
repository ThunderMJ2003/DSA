//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // int median(vector<vector<int>> &mat){ // O(rows*cols*rows)
    //     vector<int> ind(mat.size(), 0);
    //     int n1 = mat.size(), n2 = mat[0].size();
    //     int curmin;
    //     int curminind;
    //     for (int x=0; x < (((n1*n2)/2)+1); x++){
    //         curmin = INT_MAX;
    //         curminind = -1;
    //         for (int i=0; i<ind.size(); i++){
    //             if ((ind[i] < mat[0].size()) && (mat[i][ind[i]] < curmin)){
    //                 curmin = mat[i][ind[i]];
    //                 curminind = i;
    //             }
    //         }
    //         ++ind[curminind];
    //     }
    //     return curmin;
    // }

    int numberOfElementsSmallerThanEqualTox(vector<vector<int>> &mat, int x){
        int fin = 0;
        for (auto arr : mat){
            fin += upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        }
        return fin;
    }
    int median(vector<vector<int>> &mat){ // O(log(max-min) * rows*log(cols))
        int l = INT_MAX, h = INT_MIN;
        for (auto arr : mat){
            l = min(l, arr[0]);
            h = max(h, arr.back());
        }
        int m;
        int ns;
        int numberOnLeft = (mat.size()*mat[0].size())/2;
        while (l <= h){
            m = (l+h)/2;
            ns = numberOfElementsSmallerThanEqualTox(mat, m);
            if (ns > numberOnLeft){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int m;
        cin >> m;
        cin.ignore();
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> a;
        for (int i=0; i<m; i++){
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
        auto ans = obj.median(a);

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