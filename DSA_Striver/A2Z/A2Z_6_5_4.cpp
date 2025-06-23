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

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    public:
    // Node* copyRandomList(Node* head){ // O(n^2), O(n)
    //     if (head == nullptr){
    //         return nullptr;
    //     }
    //     Node* newhead = new Node(head->val);
    //     Node* olditer = head->next;
    //     Node* newiter = newhead;
    //     while (olditer != nullptr){
    //         Node* temp = new Node(olditer->val);
    //         newiter->next = temp;
    //         olditer = olditer->next;
    //         newiter = newiter->next;
    //     }
    //     newiter->next = nullptr;
    //     olditer = head;
    //     newiter = newhead;
    //     Node* olditer2;
    //     Node* newiter2;
    //     while (olditer != nullptr){
    //         olditer2 = head;
    //         newiter2 = newhead;
    //         while ((olditer2 != nullptr) && (olditer2 != olditer->random)){
    //             olditer2 = olditer2->next;
    //             newiter2 = newiter2->next;
    //         }
    //         newiter->random = newiter2;
    //         newiter = newiter->next;
    //         olditer = olditer->next;
    //     }
    //     return newhead;
    // }

    // Node* copyRandomList(Node* head){ // O(n) using unordered_map, O(n)
    //     if (head == nullptr){
    //         return nullptr;
    //     }
    //     Node* iterll = head->next;
    //     Node* newhead = new Node(head->val);
    //     Node* newiter = newhead;
    //     unordered_map<Node*, Node*> mpp;
    //     mpp[head] = newhead;
    //     while (iterll != nullptr){
    //         Node* temp = new Node(iterll->val);
    //         newiter->next = temp;
    //         newiter = newiter->next;
    //         mpp[iterll] = newiter;
    //         iterll = iterll->next;
    //     }
    //     iterll = head;
    //     newiter = newhead;
    //     while (iterll != nullptr){
    //         newiter->random = mpp[iterll->random];
    //         iterll = iterll->next;
    //         newiter = newiter->next;
    //     }
    //     return newhead;
    // }

    Node* copyRandomList(Node* head){ // O(n), O(n) for answer
        if (head == nullptr){
            return nullptr;
        }
        Node* iterll = head;
        while (iterll != nullptr){
            Node* tempnode = new Node(iterll->val);
            tempnode->next = iterll->next;
            iterll->next = tempnode;
            iterll = tempnode->next;
        }
        Node* newhead = head->next;
        iterll = head;
        while (iterll != nullptr){
            if (iterll->random){
                iterll->next->random = iterll->random->next;
            }
            iterll = iterll->next->next;
        }
        iterll = head;
        Node* newiter = newhead;
        while (newiter->next != nullptr){
            iterll->next = newiter->next;
            iterll = iterll->next;
            newiter->next = newiter->next->next;
            newiter = iterll->next;
        }
        iterll->next = nullptr;
        return newhead;
    }
};

int main() { // ignore int main, use leetcode/gfg ide
    // int t; // Number of test cases
    // cin >> t;
    // cin.ignore(); // Ignore the newline after the integer input
    // while (t--) {
    //     // int m;
    //     // cin >> m;
    //     // cin.ignore();
    //     // int n;
    //     // cin >> n;
    //     // cin.ignore();
    //     // vector<vector<int>> a;
    //     // for (int i=0; i<m; i++){
    //     //     vector<int> t;
    //     //     for (int j=0; j<n; j++){
    //     //         int x;
    //     //         cin >> x;
    //     //         t.push_back(x);
    //     //     }
    //     //     a.push_back(t);
    //     //     t.clear();
    //     // }

    //     int n;
    //     cin >> n;
    //     cin.ignore();

    //     vector<int> a;
    //     string input;

    //     // Input format: first number n followed by the array elements
    //     getline(cin, input);
    //     stringstream ss(input);
    //     int num;
    //     while (ss >> num)
    //         a.push_back(num); // Read the array elements from input string

    //     // string a;
    //     // getline(cin, a);
    //     // string b;
    //     // getline(cin, b);
    //     // stringstream ss(input);
    //     // string st;
    //     // vector<string> a;
    //     // while (ss >> st)
    //     //     a.push_back(st);

    //     Node* head = new Node(a[0]);
    //     Node* iterll = head;
    //     for (int i=1; i<a.size(); i++){
    //         Node* temp = new Node(a[i]);
    //         iterll->next = temp;
    //         iterll = iterll->next;
    //     }

    //     Solution obj;
    //     auto ans = obj.rotateRight(head, n);

    //     // cout << ans << endl;
    //     // for (int i=0; i<ans.size(); i++){
    //     //     printf("%d ", ans);
    //     // }
    //     for (auto i=ans; i!=nullptr; i=i->next){
    //         printf("%d ", i->data);
    //     }
    //     // for (int i=0; i<ans.size(); i++){
    //     //     for (int j=0; j<ans[i].size(); j++){
    //     //         cout << ans[i][j] << " ";
    //     //     }
    //     //     cout << endl;
    //     // }
    //     cout << "~\n";
    // }
    return 0;
}
