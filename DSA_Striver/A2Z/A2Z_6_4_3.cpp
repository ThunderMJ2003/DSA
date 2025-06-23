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
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class Solution {
    public:
    // Node *removeDuplicates(struct Node *head){ // O(n), O(1)
    //     if (head == nullptr){
    //         return head;
    //     }
    //     Node* iterll = head->next;
    //     while (iterll != nullptr){
    //         if (iterll->data == iterll->prev->data){
    //             iterll->prev->next = iterll->next;
    //             if (iterll->next){
    //                 iterll->next->prev = iterll->prev;
    //             }
    //             Node* temp = iterll;
    //             iterll = iterll->next;
    //             delete temp;
    //         }
    //         else{
    //             iterll = iterll->next;
    //         }
    //     }
    //     return head;
    // }

    Node *removeDuplicates(struct Node *head){ // O(n), O(1)
        if ((head == nullptr) || (head->next == nullptr)){
            return head;
        }
        Node* iterll = head;
        Node* iterll2 = head->next;
        while (iterll2->next != nullptr){
            if (iterll2->data == iterll->data){
                iterll2 = iterll2->next;
                delete iterll2->prev;
                continue;
            }
            iterll->next = iterll2;
            iterll2->prev = iterll;
            iterll = iterll2;
            iterll2 = iterll2->next;
        }
        if (iterll2->data == iterll->data){
            delete iterll2;
            iterll->next = nullptr;
        }
        else{
            iterll->next = iterll2;
            iterll2->prev = iterll;
        }
        return head;
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

        Node* head = new Node(a[0]);
        Node* iterll = head;
        for (int i=1; i<a.size(); i++){
            Node* temp = new Node(a[i]);
            iterll->next = temp;
            temp->prev = iterll;
            iterll = iterll->next;
        }

        Solution obj;
        auto ans = obj.removeDuplicates(head);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans);
        // }
        for (auto i=head; i!=nullptr; i=i->next){
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
