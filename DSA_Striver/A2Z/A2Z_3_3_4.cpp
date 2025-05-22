//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //     set<vector<int>> finset;
        //     int n = nums.size();
        //     for (int i=0; i<n; i++){
        //         for (int j=(i+1); j<n; j++){
        //             for (int k=(j+1); k<n; k++){
        //                 for (int l=(k+1); l<n; l++){
        //                     if (((long)nums[i]+nums[j]+nums[k]+nums[l]) == target){
        //                         vector<int> tempvec = {nums[i], nums[j], nums[k], nums[l]};
        //                         sort(tempvec.begin(), tempvec.end());
        //                         finset.insert(tempvec);
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     vector<vector<int>> fin(finset.begin(), finset.end());
        //     return fin;
        // }

        // vector<vector<int>> fourSum(vector<int>& nums, int target){
        //     set<vector<int>> finset;
        //     set<int> numsset;
        //     for (int i=0; i<nums.size(); i++){
        //         for (int j=(i+1); j<nums.size(); j++){
        //             numsset.clear();
        //             for (int k=(j+1); k<nums.size(); k++){
        //                 if (((target - ((long long)nums[i]+nums[j]+nums[k])) == (int)(target - ((long long)nums[i]+nums[j]+nums[k]))) && (numsset.find(target - ((long long)nums[i]+nums[j]+nums[k])) != numsset.end())){
        //                     vector<int> tempvec = {nums[i], nums[j], nums[k], (int)(target - ((long long)nums[i]+nums[j]+nums[k]))};
        //                     sort(tempvec.begin(), tempvec.end());
        //                     finset.insert(tempvec);
        //                 }
        //                 numsset.insert(nums[k]);
        //             }
        //         }
        //     }
        //     vector<vector<int>> fin(finset.begin(), finset.end());
        //     return fin;
        // }

        vector<vector<int>> fourSum(vector<int>& nums, int target){
            vector<vector<int>> fin;
            vector<int> tempvec;
            int n = nums.size();
            int i=0, j=1, k=2, l=n-1;
            sort(nums.begin(), nums.end());
            for (i=0; i<n; i++){
                if ((i != 0) && (nums[i] == nums[i-1])){
                    continue;
                }
                for (int j=(i+1); j<n; j++){
                    if ((j != (i+1)) && (nums[j] == nums[j-1])){
                        continue;
                    }
                    k=j+1, l=n-1;
                    while (k < l){
                        if (((long)nums[i]+nums[j]+nums[k]+nums[l] == target)){
                            tempvec.push_back(nums[i]);
                            tempvec.push_back(nums[j]);
                            tempvec.push_back(nums[k]);
                            tempvec.push_back(nums[l]);
                            fin.push_back(tempvec);
                            tempvec.clear();
                            ++k;
                            while((k < n) && (nums[k] == nums[k-1]) && (k <= l)){
                                ++k;
                            }
                            --l;
                            while ((l >= 0) && (nums[l] == nums[l+1]) && (k <= l)){
                                --l;
                            }
                        }
                        else if ((long)nums[i]+nums[j]+nums[k]+nums[l] < target){
                            ++k;
                            while((k < n) && (nums[k] == nums[k-1]) && (k <= l)){
                                ++k;
                            }
                        }
                        else{
                            --l;
                            while ((l >= 0) && (nums[l] == nums[l+1]) && (k <= l)){
                                --l;
                            }
                        }
                    }
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
        vector<vector<int>> ans = obj.fourSum(a, n);

        //cout << ans << endl;
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