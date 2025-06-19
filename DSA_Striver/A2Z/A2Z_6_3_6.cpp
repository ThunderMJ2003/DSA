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
    int countNodesinLoop(Node *head){ // O(n), O(1)
        Node* slowiter = head;
        Node* fastiter = head;
        int found = 0;
        int fin = 0;
        while ((fastiter != nullptr) && (fastiter->next != nullptr)){
            fastiter = fastiter->next->next;
            slowiter = slowiter->next;
            if (fastiter == slowiter){
                found = 1;
                break;
            }
        }
        if (found == 0){
            return 0;
        }
        fastiter = fastiter->next;
        ++fin;
        while (slowiter != fastiter){
            slowiter = slowiter->next;
            fastiter = fastiter->next->next;
            ++fin;
        }
        return fin;
    }
};

int main() { // issues with stdin, use the leetcode/gfg ide
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
        int pos = 0;
        Node* temp2;
        for (int i=1; i<a.size(); i++){
            Node* temp = new Node(a[i]);
            iterll->next = temp;
            iterll = iterll->next;
            if ((n >= 0) && (pos >= (n-1))){
                temp2 = temp;
                n = -2;
            }
            ++pos;
        }
        if (n == -2){
            iterll->next = temp2;
        }

        Solution obj;
        auto ans = obj.countNodesinLoop(head);

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
