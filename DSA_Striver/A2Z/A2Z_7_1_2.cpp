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
    double myPow(double x, int n){ // O(logn), O(logn) of stack space
        if (n == 0){
            return 1;
        }
        if (n > 0){
            if ((n%2) == 0){
                return myPow(x*x, n/2);
            }
            return x * myPow(x*x, (n-1)/2);
        }
        if (n == INT_MIN){
            return myPow(x*x, n/2);
        }
        n = (-1) * n;
        if ((n%2) == 0){
            return 1 / (myPow(x*x, n/2));
        }
        return 1 / (x * myPow(x*x, (n-1)/2));
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

        double x;
        cin >> x;
        cin.ignore();

        // vector<int> a;
        // string input;

        // // Input format: first number n followed by the array elements
        // getline(cin, input);
        // stringstream ss(input);
        // int num;
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
        auto ans = obj.myPow(x, n);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans);
        // }
        // for (auto i=ans; i!=nullptr; i=i->next){
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
