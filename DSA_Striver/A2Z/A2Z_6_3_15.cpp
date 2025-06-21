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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){ // O(n), O(1)
    //     ListNode* iter1 = l1;
    //     ListNode* iter2 = l2;
    //     int curcarry = 0;
    //     while ((iter1->next != nullptr) && (iter2->next != nullptr)){
    //         iter1->val = iter1->val + iter2->val + curcarry;
    //         curcarry = iter1->val / 10;
    //         iter1->val = iter1->val % 10;
    //         iter1 = iter1->next;
    //         iter2 = iter2->next;
    //     }
    //     iter1->val = iter1->val + iter2->val + curcarry;
    //     curcarry = iter1->val / 10;
    //     iter1->val = iter1->val % 10;
    //     if ((iter1->next == nullptr) && (iter2->next == nullptr)){
    //         if (curcarry != 0){
    //             ListNode* temp = new ListNode(curcarry);
    //             iter1->next = temp;
    //         }
    //     }
    //     else if (iter1->next != nullptr){
    //         iter1 = iter1->next;
    //         while (iter1->next != nullptr){
    //             iter1->val += curcarry;
    //             curcarry = iter1->val / 10;
    //             iter1->val = iter1->val % 10;
    //             iter1 = iter1->next;
    //         }
    //         iter1->val += curcarry;
    //         curcarry = iter1->val / 10;
    //         iter1->val = iter1->val % 10;
    //         if (curcarry != 0){
    //             ListNode* temp = new ListNode(curcarry);
    //             iter1->next = temp;
    //         }
    //     }
    //     else{
    //         iter1->next = iter2->next;
    //         iter2 = iter2->next;
    //         while (iter2->next != nullptr){
    //             iter2->val += curcarry;
    //             curcarry = iter2->val / 10;
    //             iter2->val = iter2->val % 10;
    //             iter2 = iter2->next;
    //         }
    //         iter2->val += curcarry;
    //         curcarry = iter2->val / 10;
    //         iter2->val = iter2->val % 10;
    //         if (curcarry != 0){
    //             ListNode* temp = new ListNode(curcarry);
    //             iter2->next = temp;
    //         }
    //     }
    //     return l1;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){ // O(n), O(n) (avoid input modification)
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        ListNode* head = new ListNode();
        ListNode* iter = head;
        int curcarry = 0;
        int cursum = 0;
        while ((iter1 != nullptr) || (iter2 != nullptr)){
            cursum = curcarry;
            if (iter1){
                cursum += iter1->val;
            }
            if (iter2){
                cursum += iter2->val;
            }
            curcarry = cursum / 10;
            ListNode* temp = new ListNode(cursum % 10);
            iter->next = temp;
            iter = iter->next;
            if (iter1){
                iter1 = iter1->next;
            }
            if (iter2){
                iter2 = iter2->next;
            }
        }
        if (curcarry != 0){
            ListNode* temp = new ListNode(curcarry);
            iter->next = temp;
        }
        return head->next;
    }
};

int main() { // ignore int main, use leetcode/gfg ide
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
        for (int i=1; i<a.size(); i++){
            ListNode* temp = new ListNode(a[i]);
            iterll->next = temp;
            iterll = iterll->next;
        }

        a.clear();
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            a.push_back(num); // Read the array elements from input string
        ListNode* head2 = new ListNode(a[0]);
        iterll = head2;
        for (int i=1; i<a.size(); i++){
            ListNode* temp = new ListNode(a[i]);
            iterll->next = temp;
            iterll = iterll->next;
        }

        Solution obj;
        auto ans = obj.addTwoNumbers(head, head2);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        for (auto i=ans; i!=nullptr; i=i->next){
            printf("%d ", i->val);
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
