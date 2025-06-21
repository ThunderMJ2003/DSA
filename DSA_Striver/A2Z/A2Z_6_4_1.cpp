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
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
};

class Solution {
    public:
    void deleteAllOccurOfX(struct Node** head_ref, int x){
        Node* head = *head_ref;
        Node* iterdll = head->next;
        while (iterdll != nullptr){
            if (iterdll->data == x){
                iterdll->prev->next = iterdll->next;
                if (iterdll->next){
                    iterdll->next->prev = iterdll->prev;
                }
                Node* temp = iterdll;
                iterdll = iterdll->next;
                delete temp;
                continue;
            }
            iterdll = iterdll->next;
        }
        if (head->data == x){
            head->data = head->next->data;
            iterdll = head->next;
            head->next = head->next->next;
            if (iterdll->next){
                iterdll->next->prev = head;
            }
            delete iterdll;
        }
        return;
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

        Node* head = new Node(a[0]);
        Node* iterll = head;
        for (int i=1; i<a.size(); i++){
            Node* temp = new Node(a[i]);
            iterll->next = temp;
            temp->prev = iterll;
            iterll = iterll->next;
        }

        Solution obj;
        obj.deleteAllOccurOfX(&head, n);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
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
