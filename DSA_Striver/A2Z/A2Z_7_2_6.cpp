#include <bits/stdc++.h>
using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node (int data1, Node* next1){
//         data = data1;
//         next = next1;
//     }

//     public:
//     Node (int data1){
//         data = data1;
//         next = nullptr;
//     }
// };

class Solution {
    public:
    // vector<vector<int>> subsetsWithGivenSum(vector<int>& nums, int k){ // O(n*2^n), O(n*2^n)
    //     long long n = pow(2, nums.size());
    //     vector<vector<int>> fin;
    //     for (long long i=0; i<n; i++){
    //         vector<int> tempvec;
    //         int cursum = 0;
    //         for (int j=0; j<nums.size(); j++){
    //             if (i & (1 << j)){
    //                 cursum += nums[j];
    //                 tempvec.push_back(nums[j]);
    //             }
    //         }
    //         if (cursum == k){
    //             fin.push_back(tempvec);
    //         }
    //     }
    //     return fin;
    // }

    bool cSShelper(vector<int> nums, int k, int cursum){
        if (nums.empty()){
            if (cursum == k){
                return true;
            }
            return false;
        }
        int x = nums[0];
        nums.erase(nums.begin());
        return (cSShelper(nums, k, cursum+x) || cSShelper(nums, k, cursum));
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k){
        return cSShelper(arr, k, 0);
    }
};

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

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        int k;
        cin >> k;
        cin.ignore();

        // vector<string> a;
        // string input;
        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // string num;
        // while (ss >> num)
        //     a.push_back(num); // Read the array elements from input string

        // string a;
        // getline(cin, a);
        // string b;
        // getline(cin, b);
        // stringstream ss(input);
        // string st;
        // vector<string> a;
        // while (ss >> st)
        //     a.push_back(st);

        // Node* head = new Node(a[0]);
        // Node* iterll = head;
        // for (int i=1; i<a.size(); i++){
        //     Node* temp = new Node(a[i]);
        //     iterll->next = temp;
        //     iterll = iterll->next;
        // }

        Solution obj;
        auto ans = obj.checkSubsequenceSum(a.size(), a, k);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // for (auto i=ans; i!=nullptr; i=i->next){
        //     printf("%d ", i->data);
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
