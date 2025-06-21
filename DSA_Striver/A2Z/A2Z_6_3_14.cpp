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

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
    // int isCarry(Node* head){
    //     if (head == nullptr){
    //         return 1;
    //     }
    //     if (isCarry(head->next)){
    //         ++head->data;
    //     }
    //     if (head->data > 9){
    //         head->data = head->data % 10;
    //         return 1;
    //     }
    //     return 0;
    // }
    // Node* addOne(Node* head){ // O(n), O(n)
    //     if (isCarry(head)){
    //         Node* temp = new Node(1);
    //         temp->next = head;
    //         head = temp;
    //     }
    //     return head;
    // }

    Node* addOne(Node* head){ // O(n), O(1)
        if (head == nullptr){
            head->data = 1;
            return head;
        }
        if (head->next == nullptr){
            ++head->data;
            if (head->data > 9){
                Node* temp = new Node(head->data % 10);
                head->data = head->data / 10;
                head->next = temp;
            }
            return head;
        }
        Node* l = head;
        Node* m = head->next;
        Node* r = head->next->next;
        l->next = nullptr;
        while (r != nullptr){
            m->next = l;
            l = m;
            m = r;
            r = r->next;
        }
        m->next = l;
        ++m->data;
        l = m;
        while ((m->data > 9) && (m->next != nullptr)){
            m->next->data += m->data / 10;
            m->data = m->data % 10;
            m = m->next;
        }
        if ((m->next == nullptr) && (m->data > 9)){
            Node* temp = new Node(m->data / 10);
            m->data = m->data % 10;
            m->next = temp;
        }
        m = l->next;
        r = l->next->next;
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

        Node* head = new Node(a[0]);
        Node* iterll = head;
        for (int i=1; i<a.size(); i++){
            Node* temp = new Node(a[i]);
            iterll->next = temp;
            iterll = iterll->next;
        }

        Solution obj;
        auto ans = obj.addOne(head);

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
