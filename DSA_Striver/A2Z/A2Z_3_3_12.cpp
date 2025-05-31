//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // int maxProduct(vector<int>& nums){
    //     int fin = nums[0];
    //     int curprod = 1;
    //     for (int i=0; i<nums.size(); i++){
    //         curprod = nums[i];
    //         fin = max(fin, curprod);
    //         for (int j=(i+1); j<nums.size(); j++){
    //             curprod *= nums[j];
    //             fin = max(fin, curprod);
    //         }
    //     }
    //     return fin;
    // }

    // int maxProduct(vector<int>& nums){
    //     int fin = nums[0];
    //     int curprod = 1;
    //     for (int i=0; i<nums.size(); i++){
    //         if (nums[i] == 0){
    //             fin = max(fin, 0);
    //             curprod = 1;
    //             continue;
    //         }
    //         curprod *= nums[i];
    //         fin = max(fin, curprod);
    //     }
    //     curprod = 1;
    //     for (int i=(nums.size()-1); i>=0; i--){
    //         if (nums[i] == 0){
    //             fin = max(fin, 0);
    //             curprod = 1;
    //             continue;
    //         }
    //         curprod *= nums[i];
    //         fin = max(fin, curprod);
    //     }
    //     return fin;
    // }

    int maxProduct(vector<int>& nums){
        int fin = nums[0];
        int curprod1 = 1;
        int curprod2 = 1;
        for (int i=0; i<nums.size(); i++){
            if (curprod1 == 0){
                curprod1 = 1;
            }
            if (curprod2 == 0){
                curprod2 = 1;
            }
            curprod1 *= nums[i];
            curprod2 *= nums[nums.size()-i-1];
            fin = max(fin, curprod1);
            fin = max(fin, curprod2);
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
        // for (int i=0; i<n; i++){
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

        Solution obj;
        int ans = obj.maxProduct(a);

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