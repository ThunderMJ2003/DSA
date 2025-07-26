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
    // vector<int> singleNumber(vector<int>& nums){
    //     sort(nums.begin(), nums.end());
    //     vector<int> fin;
    //     for (int i = 1; i<nums.size(); i=i+2){
    //         if (nums[i] != nums[i-1]){
    //             if (fin.empty()){
    //                 fin.push_back(nums[i-1]);
    //                 i = i-1;
    //             }
    //             else{
    //                 fin.push_back(nums[i-1]);
    //                 return fin;
    //             }
    //         }
    //     }
    //     fin.push_back(nums.back());
    //     return fin;
    // }

    vector<int> singleNumber(vector<int>& nums){
        int allxor = 0;
        for (int i : nums){
            allxor = allxor ^ i;
        }
        int lastsetbit = (allxor & (allxor-1)) ^ allxor;
        int lastbit1 = 0;
        int lastbit0 = 0;
        for (int i : nums){
            if (i & lastsetbit){
                lastbit1 = lastbit1 ^ i;
            }
            else{
                lastbit0 = lastbit0 ^ i;
            }
        }
        return {lastbit0, lastbit1};
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
        // vector<vector<char>> a;
        // for (int i=0; i<m; i++){
        //     vector<char> t;
        //     for (int j=0; j<n; j++){
        //         char x;
        //         cin >> x;
        //         t.push_back(x);
        //     }
        //     a.push_back(t);
        //     t.clear();
        // }
        // cin.ignore();

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

        // int k;
        // cin >> k;
        // cin.ignore();
        // vector<string> vecstr;
        // string st;
        // for (int i=0; i<k; i++){
        //     getline(cin, st);
        //     vecstr.push_back(st);
        // }
        // string st2;
        // getline(cin, st2);

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
        auto ans = obj.singleNumber(a);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
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
