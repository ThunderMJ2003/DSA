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

class Solution {
    public:
    string gChelper(vector<vector<int>>& adjMatrix, int n, int m, int curNode, vector<int>& nodeColor){
        if (curNode == n){
            return "Yes";
        }
        bool isColorPossible;
        for (int i=0; i<m; i++){
            isColorPossible = true;
            for (int j=0; j<curNode; j++){
                if ((adjMatrix[curNode][j] == 1) && (nodeColor[j] == i)){
                    isColorPossible = false;
                    break;
                }
            }
            if (isColorPossible){
                nodeColor[curNode] = i;
                if (gChelper(adjMatrix, n, m, curNode+1, nodeColor) == "Yes"){
                    return "Yes";
                }
                nodeColor[curNode] = -1;
            }
        }
        return "No";
    }
    string graphColoring(vector<vector<int>>& adjMatrix, int n, int m){ // O(n*m^n), O(n)
        vector<int> NodeColor(n, -1);
        NodeColor[0] = 0;
        return gChelper(adjMatrix, n, m, 1, NodeColor);
    }
};

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int m;
        cin >> m;
        cin.ignore();
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> a;
        for (int i=0; i<m; i++){
            vector<int> t;
            for (int j=0; j<n; j++){
                int x;
                cin >> x;
                t.push_back(x);
            }
            a.push_back(t);
            t.clear();
        }
        cin.ignore();

        // int n;
        // cin >> n;
        // cin.ignore();

        // vector<int> a;
        // string input;

        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // int num;
        // while (ss >> num)
        //     a.push_back(num); // Read the array elements from input string

        int k;
        cin >> k;
        cin.ignore();
        // vector<string> vecstr;
        // string st;
        // for (int i=0; i<k; i++){
        //     getline(cin, st);
        //     vecstr.push_back(st);
        // }
        // string st2;
        // getline(cin, st2);

        // vector<string> a;
        // string input;
        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // string num;
        // while (ss >> num)
        //     a.push_back(num); // Read the array elements from input string

        // string a;
        // getline(cin, a);
        // string b;
        // getline(cin, b);
        // stringstream ss(input);
        // string st;
        // vector<string> a;
        // while (ss >> st)
        //     a.push_back(st);

        // Node* head = new Node(a[0]);
        // Node* iterll = head;
        // for (int i=1; i<a.size(); i++){
        //     Node* temp = new Node(a[i]);
        //     iterll->next = temp;
        //     iterll = iterll->next;
        // }

        Solution obj;
        auto ans = obj.graphColoring(a, n, k);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // for (auto i=ans; i!=nullptr; i=i->next){
        //     printf("%d ", i->data);
        // }
        // for (int i=0; i<ans.size(); i++){
        //     for (int j=0; j<ans[i].size(); j++){
        //         cout << ans[i][j] << endl;
        //     }
        //     cout << endl;
        // }
        cout << "~\n";
    }
    return 0;
}
