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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    // bool hasCycle(ListNode *head){ // O(n) using unordered_set, O(n)
    //     ListNode* iterll = head;
    //     unordered_set<ListNode*> llset;
    //     while (iterll != nullptr){
    //         if (llset.find(iterll) == llset.end()){
    //             llset.insert(iterll);
    //         }
    //         else{
    //             return true;
    //         }
    //         iterll = iterll->next;
    //     }
    //     return false;
    // }

    bool hasCycle(ListNode *head){ // O(n), O(1)
        ListNode* slowiter = head;
        ListNode* fastiter = head;
        while ((fastiter != nullptr) && (fastiter->next != nullptr)){
            fastiter = fastiter->next->next;
            slowiter = slowiter->next;
            if (fastiter == slowiter){
                return true;
            }
        }
        return false;
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

        // string a;
        // getline(cin, a);
        // string b;
        // getline(cin, b);
        // stringstream ss(input);
        // string st;
        // vector<string> a;
        // while (ss >> st)
        //     a.push_back(st);

        ListNode* head = new ListNode(a[0]);
        ListNode* iterll = head;
        int pos = 0;
        ListNode* temp2;
        for (int i=1; i<a.size(); i++){
            ListNode* temp = new ListNode(a[i]);
            iterll->next = temp;
            iterll = iterll->next;
            if ((n != -1) && (pos == n)){
                temp2 = temp;
            }
            ++pos;
        }
        if (n != -1){
            iterll->next = temp2;
        }

        Solution obj;
        auto ans = obj.hasCycle(head);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        // for (auto i=ans; i!=nullptr; i=i->next){
        //     printf("%d ", i->val);
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
