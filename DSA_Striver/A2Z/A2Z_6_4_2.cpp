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

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution {
    public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){ // O(n), O(1) ignoring answer space
        vector<pair<int, int>> fin;
        Node* l = head;
        Node* r = head;
        while ((r->next != nullptr) && ((l->data + r->data) < target)){
            r = r->next;
        }
        while ((l != r) && (r->next != l)){
            if ((l->data + r->data) == target){
                fin.push_back({l->data, r->data});
                l = l->next;
                r = r->prev;
            }
            else if ((l->data + r->data) > target){
                r = r->prev;
            }
            else{
                l = l->next;
            }
        }
        return fin;
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
        auto ans = obj.findPairsWithGivenSum(head, n);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            printf("%d %d \n", ans[i].first, ans[i].second);
        }
        // for (auto i=head; i!=nullptr; i=i->next){
        //     printf("%d ", i->data);
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
