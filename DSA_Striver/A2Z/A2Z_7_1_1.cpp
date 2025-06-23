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
    long long recursiveAtoi(string s, long long x, int ispos){
        if (((s[0] == '+') && (s[1] >= '0') && (s[1] <= '9')) || (s[0] == ' ')){
            return recursiveAtoi(s.substr(1), x, ispos);
        }
        if ((s[0] == '-') && (s[1] >= '0') && (s[1] <= '9')){
            return recursiveAtoi(s.substr(1), x, 0);
        }
        if ((s[0] >= '0') && (s[0] <= '9')){
            if ((s[1] < '0') || (s[1] > '9')){
                x = (10*x) + (s[0]-'0');
                if (x != ((int)x)){
                    return (ispos) ? INT_MAX : INT_MIN;
                }
                cout << s.substr(1) << " " << x << " " << ispos << endl;
                return (ispos) ? x : (-1)*x;
            }
            else{;
                x = (10*x) + (s[0]-'0');
                if (x != ((int)x)){
                    return (ispos) ? INT_MAX : INT_MIN;
                }
                cout << s.substr(1) << " " << x << " " << ispos << endl;
                return recursiveAtoi(s.substr(1), x, ispos);
            }
        }
        return 0;
    }
    int myAtoi(string s){ // O(n), O(n) of stack space
        return (int)recursiveAtoi(s, 0, 1);
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

        // vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
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
        auto ans = obj.myAtoi(input);

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
