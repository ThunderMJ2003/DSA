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

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
    // Node* segregate(Node* head){ // O(n), O(1)
    //     int n0 = 0, n1 = 0, n2 = 0;
    //     Node* iterll = head;
    //     while (iterll != nullptr){
    //         if (iterll->data == 0){
    //             ++n0;
    //         }
    //         else if (iterll->data == 1){
    //             ++n1;
    //         }
    //         else{
    //             ++n2;
    //         }
    //         iterll = iterll->next;
    //     }
    //     iterll = head;
    //     while (iterll != nullptr){
    //         if (n0 != 0){
    //             iterll->data = 0;
    //             --n0;
    //         }
    //         else if (n1 != 0){
    //             iterll->data = 1;
    //             --n1;
    //         }
    //         else{
    //             iterll->data = 2;
    //             --n2;
    //         }
    //         iterll = iterll->next;
    //     }
    //     return head;
    // }

    Node* segregate(Node* head){ // O(n), O(1)
        Node* h0;
        Node* h1;
        Node* h2;
        Node* i0;
        Node* i1;
        Node* i2;
        Node* iterll = head;
        int found0 = 0, found1 = 0, found2 = 0;
        while (iterll != nullptr){
            if (iterll->data == 0){
                if (found0){
                    i0->next = iterll;
                    i0 = iterll;
                }
                else{
                    found0 = 1;
                    i0 = iterll;
                    h0 = iterll;
                }
            }
            else if (iterll->data == 1){
                if (found1){
                    i1->next = iterll;
                    i1 = iterll;
                }
                else{
                    found1 = 1;
                    i1 = iterll;
                    h1 = iterll;
                }
            }
            else{
                if (found2){
                    i2->next = iterll;
                    i2 = iterll;
                }
                else{
                    found2 = 1;
                    i2 = iterll;
                    h2 = iterll;
                }
            }
            iterll = iterll->next;
        }
        if (found0){
            if (found1){
                if (found2){
                    i0->next = h1;
                    i1->next = h2;
                    i2->next = nullptr;
                    return h0;
                }
                else{
                    i0->next = h1;
                    i1->next = nullptr;
                    return h0;
                }
            }
            else{
                if (found2){
                    i0->next = h2;
                    i2->next = nullptr;
                    return h0;
                }
                else{
                    i0->next = nullptr;
                    return h0;
                }
            }
        }
        else{
            if (found1){
                if (found2){
                    i1->next = h2;
                    i2->next = nullptr;
                    return h1;
                }
                else{
                    i1->next = nullptr;
                    return h1;
                }
            }
            else{
                if (found2){
                    i2->next = nullptr;
                    return h2;
                }
                else{
                    return nullptr;
                }
            }
        }
        return nullptr;
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
            iterll = iterll->next;
        }

        Solution obj;
        auto ans = obj.segregate(head);

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
