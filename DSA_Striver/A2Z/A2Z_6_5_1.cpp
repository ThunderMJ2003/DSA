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
    ListNode* reverseLL(ListNode* head){
        if ((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        ListNode* l = head;
        ListNode* m = head->next;
        ListNode* r = head->next->next;
        l->next = nullptr;
        while (r != nullptr){
            m->next = l;
            l = m;
            m = r;
            r = r->next;
        }
        m->next = l;
        return m;
    }
    ListNode* reverseKGroup(ListNode* head, int k){ // O(n), O(1)
        ListNode* curhead = head;
        ListNode* nexthead;
        ListNode* iterll = head;
        ListNode* newhead = head;
        ListNode* prevtail = nullptr;
        int curk = 0;
        int firsttime = 1;
        while (iterll != nullptr){
            ++curk;
            if (curk == k){
                if (firsttime){
                    firsttime = 0;
                    newhead = iterll;
                }
                curk = 0;
                nexthead = iterll->next;
                iterll->next = nullptr;
                iterll = reverseLL(curhead);
                if (prevtail){
                    prevtail->next = iterll;
                }
                prevtail = curhead;
                iterll = curhead;
                iterll->next = nexthead;
                curhead = nexthead;
            }
            iterll = iterll->next;
        }
        return newhead;
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
        for (int i=1; i<a.size(); i++){
            ListNode* temp = new ListNode(a[i]);
            iterll->next = temp;
            iterll = iterll->next;
        }

        Solution obj;
        auto ans = obj.reverseKGroup(head, n);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans);
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
