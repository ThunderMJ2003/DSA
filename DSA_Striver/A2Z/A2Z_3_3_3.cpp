//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // vector<vector<int>> threeSum(vector<int>& nums) {
        //     int n = nums.size();
        //     set<vector<int>> fin;
        //     for (int i=0; i<n; i++){
        //         for (int j=(i+1); j<n; j++){
        //             for (int k=(j+1); k<n; k++){
        //                 if (nums[i]+nums[j]+nums[k] == 0){
        //                     vector<int> temparr;
        //                     temparr.push_back(nums[i]);
        //                     temparr.push_back(nums[j]);
        //                     temparr.push_back(nums[k]);
        //                     sort(temparr.begin(), temparr.end());
        //                     if (fin.find(temparr) == fin.end()){
        //                         fin.insert(temparr);
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     vector<vector<int>> finvec;
        //     for (auto i : fin){
        //         finvec.push_back(i);
        //     }
        //     return finvec;
        // }

        // vector<vector<int>> threeSum(vector<int>& nums){
        //     set<vector<int>> finset;
        //     set<int> numsset;
        //     for (int i=0; i<nums.size(); i++){
        //         numsset.clear();
        //         for (int j=(i+1); j<nums.size(); j++){
        //             if (numsset.find(-(nums[i]+nums[j])) != numsset.end()){
        //                 vector<int> tempvec = {nums[i], nums[j], -(nums[i]+nums[j])};
        //                 sort(tempvec.begin(), tempvec.end());
        //                 finset.insert(tempvec);
        //             }
        //             numsset.insert(nums[j]);
        //         }
        //     }
        //     vector<vector<int>> fin;
        //     for (auto i : finset){
        //         fin.push_back(i);
        //     }
        //     return fin;
        // }

        vector<vector<int>> threeSum(vector<int>& nums){
            vector<vector<int>> fin;
            vector<int> tempvec;
            int n = nums.size();
            int i=0, j=1, k=n-1;
            sort(nums.begin(), nums.end());
            for (i=0; i<(n-1); i++){
                if ((i != 0) && (nums[i] == nums[i-1])){
                    continue;
                }
                j=i+1, k=n-1;
                while (j < k){
                    if ((nums[i]+nums[j]+nums[k]) == 0){
                        tempvec.push_back(nums[i]);
                        tempvec.push_back(nums[j]);
                        tempvec.push_back(nums[k]);
                        fin.push_back(tempvec);
                        tempvec.clear();
                        ++j;
                        while((j < n) && (nums[j] == nums[j-1]) && (j <= k)){
                            ++j;
                        }
                        --k;
                        while ((k >= 0) && (nums[k] == nums[k+1]) && (j <= k)){
                            --k;
                        }
                    }
                    else if ((nums[i]+nums[j]+nums[k]) < 0){
                        ++j;
                        while((j < n) && (nums[j] == nums[j-1]) && (j <= k)){
                            ++j;
                        }
                    }
                    else{
                        --k;
                        while ((k >= 0) && (nums[k] == nums[k+1]) && (j <= k)){
                            --k;
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
        vector<vector<int>> ans = obj.threeSum(a);

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