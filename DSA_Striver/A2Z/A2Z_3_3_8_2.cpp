//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // void mergeArrays(vector<int>& a, vector<int>& b) {
        //     int i=a.size()-1, j=0;
        //     while ((i>=0) && (j<b.size())){
        //         if (a[i] > b[j]){
        //             swap(a[i], b[j]);
        //             --i;
        //             ++j;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     sort(a.begin(), a.end());
        //     sort(b.begin(), b.end());
        // }

        void mergeArrays(vector<int>& a, vector<int>& b){
            int as = a.size(), bs = b.size();
            int gap = ceil((as+bs)/2.0);
            while (1){
                for (int i=0; (i+gap)<(as+bs); i++){
                    if ((i+gap) < as){
                        if (a[i] > a[i+gap]){
                            swap(a[i], a[i+gap]);
                        }
                    }
                    else if (i < as){
                        if (a[i] > b[i+gap-as]){
                            swap(a[i], b[i+gap-as]);
                        }
                    }
                    else{
                        if (b[i-as] > b[i+gap-as]){
                            swap(b[i-as], b[i+gap-as]);
                        }
                    }
                }
                if (gap == 1){
                    break;
                }
                gap = ceil(gap/2.0);
            }
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

        // int n;
        // cin >> n;
        // cin.ignore();

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        vector<int> b;
        string input2;

        // Input format: first number n followed by the array elements
        getline(cin, input2);
        stringstream ss2(input2);
        while (ss2 >> num)
            b.push_back(num); // Read the array elements from input string

        Solution obj;
        // vector<vector<int>> ans = obj.merge(a);
        obj.mergeArrays(a, b);

        // cout << ans << endl;
        for (int i=0; i<a.size(); i++){
            printf("%d ", a[i]);
        }
        cout << endl;
        for (int i=0; i<b.size(); i++){
            printf("%d ", b[i]);
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