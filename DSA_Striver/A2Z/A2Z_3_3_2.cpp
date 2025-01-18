//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // vector<int> majorityElement(vector<int>& nums) {
    //     map<int, int> freqmap;
    //     for (int i=0; i<nums.size(); i++){
    //         ++freqmap[nums[i]];
    //     }
    //     vector<int> fin;
    //     for (auto i=freqmap.begin(); i!=freqmap.end(); i++){
    //         if (i->second > (nums.size()/3)){
    //             fin.push_back(i->first);
    //         }
    //         if (fin.size() == 2){
    //             break;
    //         }
    //     }
    //     return fin;
    // }

    // vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> freqmap;
    //     for (int i=0; i<nums.size(); i++){
    //         ++freqmap[nums[i]];
    //     }
    //     vector<int> fin;
    //     for (auto i=freqmap.begin(); i!=freqmap.end(); i++){
    //         if (i->second > (nums.size()/3)){
    //             fin.push_back(i->first);
    //         }
    //         if (fin.size() == 2){
    //             break;
    //         }
    //     }
    //     return fin;
    // }

    vector<int> majorityElement(vector<int>& nums){
        int n = nums.size();
        if (n==1){
            vector<int> fin;
            fin.push_back(nums[0]);
            return fin;
        }
        int x = nums[0];
        int cntx = 1;
        int y, cnty=-1;
        int i = 1;
        for (; i<n; i++){
            if (nums[i] == x){
                ++cntx;
            }
            else{
                y = nums[i];
                cnty = 1;
                break;
            }
        }
        ++i;
        for (; i<n; i++){
            if (x == nums[i]){
                ++cntx;
            }
            else if (y == nums[i]){
                ++cnty;
            }
            else{
                if (cntx == 0){
                    x = nums[i];
                    cntx = 1;
                }
                else if (cnty == 0){
                    y = nums[i];
                    cnty = 1;
                }
                else{
                    --cntx;
                    --cnty;
                }
            }
        }
        vector<int> fin;
        cntx = 0;
        cnty = 0;
        for (i=0; i<n; i++){
            if (x == nums[i]){
                ++cntx;
            }
            if (y == nums[i]){
                ++cnty;
            }
        }
        if (cntx > n/3){
            fin.push_back(x);
        }
        if (cnty > n/3){
            fin.push_back(y);
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
        vector<int> ans = obj.majorityElement(a);

        //cout << ans << endl;
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