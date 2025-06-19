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

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
    public:
    // DLLNode* reverseDLL(DLLNode* head){
    //     DLLNode* l = head;
    //     DLLNode* r = head;
    //     while (r->next != nullptr){
    //         r = r->next;
    //     }
    //     while ((r->next != l) && (l != r)){
    //         swap(l->data, r->data);
    //         l = l->next;
    //         r = r->prev;
    //     }
    //     return head;
    // }

    DLLNode* reverseDLL(DLLNode* head){
        if ((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        head->prev = head->next;
        DLLNode* iterdll = head->next;
        head->next = nullptr;
        while (iterdll->next != nullptr){
            DLLNode* temp = iterdll->prev;
            iterdll->prev = iterdll->next;
            iterdll->next = temp;
            iterdll = iterdll->prev;
        }
        iterdll->next = iterdll->prev;
        iterdll->prev = nullptr;
        return iterdll;
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

        DLLNode* head = new DLLNode(a[0]);
        DLLNode* iterll = head;
        for (int i=1; i<a.size(); i++){
            DLLNode* temp = new DLLNode(a[i]);
            iterll->next = temp;
            iterll->next->prev = iterll;
            iterll = iterll->next;
        }

        Solution obj;
        auto ans = obj.reverseDLL(head);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
        // }
        for (auto i=ans; i!=nullptr; i=i->next){
            printf("%d ", i->data);
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
