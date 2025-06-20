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
    // ListNode* mergeSortLL(ListNode* a, ListNode* b){
    //     if ((a == b) || (a->next == b)){
    //         return a;
    //     }
    //     ListNode* slowiter = a;
    //     ListNode* fastiter = a;
    //     while ((fastiter != b) && (fastiter->next != b)){
    //         slowiter = slowiter->next;
    //         fastiter = fastiter->next->next;
    //     }
    //     a = mergeSortLL(a, slowiter);
    //     slowiter = mergeSortLL(slowiter, b);
    //     fastiter = a;
    //     ListNode* midLL = slowiter;
    //     vector<int> temp;
    //     while ((fastiter != midLL) && (slowiter != b)){
    //         if (fastiter->val < slowiter->val){
    //             temp.push_back(fastiter->val);
    //             fastiter = fastiter->next;
    //         }
    //         else{
    //             temp.push_back(slowiter->val);
    //             slowiter = slowiter->next;
    //         }
    //     }
    //     while (fastiter != midLL){
    //         temp.push_back(fastiter->val);
    //         fastiter = fastiter->next;
    //     }
    //     while (slowiter != b){
    //         temp.push_back(slowiter->val);
    //         slowiter = slowiter->next;
    //     }
    //     slowiter = a;
    //     for (int i : temp){
    //         slowiter->val = i;
    //         slowiter = slowiter->next;
    //     }
    //     return a;
    // }
    // ListNode* sortList(ListNode* head){ // O(nlogn), O(n)
    //     return mergeSortLL(head, nullptr);
    // }

    // ListNode* sortList(ListNode* head){ // O(nlogn), O(n)
    //     vector<int> templl;
    //     ListNode* iterll = head;
    //     while (iterll != nullptr){
    //         templl.push_back(iterll->val);
    //         iterll = iterll->next;
    //     }
    //     sort(templl.begin(), templl.end());
    //     iterll = head;
    //     int i = 0;
    //     while (iterll != nullptr){
    //         iterll->val = templl[i];
    //         ++i;
    //         iterll = iterll->next;
    //     }
    //     return head;
    // }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if (list1 == nullptr){
            return list2;
        }
        if (list2 == nullptr){
            return list1;
        }
        ListNode* iter1 = list1;
        ListNode* iter2 = list2;
        ListNode* iter;
        if (iter1->val < iter2->val){
            iter = iter1;
            iter1 = iter1->next;
        }
        else{
            iter = iter2;
            iter2 = iter2->next;
        }
        while ((iter1 != nullptr) && (iter2 != nullptr)){
            if (iter1->val < iter2->val){
                iter->next = iter1;
                iter1 = iter1->next;
            }
            else{
                iter->next = iter2;
                iter2 = iter2->next;
            }
            iter = iter->next;
        }
        while (iter1 != nullptr){
            iter->next = iter1;
            iter1 = iter1->next;
            iter = iter->next;
        }
        while (iter2 != nullptr){
            iter->next = iter2;
            iter2 = iter2->next;
            iter = iter->next;
        }
        if (list1->val < list2->val){
            return list1;
        }
        return list2;
    }
    ListNode* sortList(ListNode* head){ // O(nlogn), O(1)
        if ((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        ListNode* slowiter = head;
        ListNode* fastiter = head;
        while ((fastiter->next != nullptr) && (fastiter->next->next != nullptr)){
            slowiter = slowiter->next;
            fastiter = fastiter->next->next;
        }
        ListNode* end1 = slowiter;
        slowiter = slowiter->next;
        end1->next = nullptr;
        head = sortList(head);
        slowiter = sortList(slowiter);
        return mergeTwoLists(head, slowiter);
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

        Solution obj;
        auto ans = obj.sortList(head);

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
