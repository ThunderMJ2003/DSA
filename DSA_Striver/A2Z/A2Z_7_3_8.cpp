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
    void aOhelper(string& num, int& target, vector<string>& fin, string cureqn, int curind, long long lastnum, long long curans){
        if (curind == num.size()){
            // cout << cureqn << " " << curans << endl;
            if (curans == target){
                fin.push_back(cureqn);
            }
            return;
        }
        long long curnum = 0;
        if (curind != 0){
            cureqn += '+';
        }
        for (int i=curind; i<num.size(); i++){
            curnum = curnum * 10 + (num[i] - '0');
            cureqn += num[i];
            if (curind != 0){
                cureqn[cureqn.size()-(i-curind+1)-1] = '+';
            }
            aOhelper(num, target, fin, cureqn, i+1, curnum, curans+curnum);
            if (curind == 0){
                if (num[curind] == '0'){
                    break;
                }
                continue;
            }
            cureqn[cureqn.size()-(i-curind+1)-1] = '-';
            aOhelper(num, target, fin, cureqn, i+1, curnum*(-1), curans-curnum);
            cureqn[cureqn.size()-(i-curind+1)-1] = '*';
            aOhelper(num, target, fin, cureqn, i+1, lastnum*curnum, curans-lastnum+(lastnum*curnum));
            if (num[curind] == '0'){
                break;
            }
        }
    }
    vector<string> addOperators(string num, int target){ // O(n*4^n), O(n*4^n)
        vector<string> fin;
        aOhelper(num, target, fin, "", 0, 0, 0);
        return fin;
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
        // vector<vector<char>> a;
        // for (int i=0; i<m; i++){
        //     vector<char> t;
        //     for (int j=0; j<n; j++){
        //         char x;
        //         cin >> x;
        //         t.push_back(x);
        //     }
        //     a.push_back(t);
        //     t.clear();
        // }
        // cin.ignore();

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
        auto ans = obj.addOperators(input, k);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        // for (auto i=ans; i!=nullptr; i=i->next){
        //     printf("%d ", i->data);
        // }
        // for (int i=0; i<a.size(); i++){
        //     for (int j=0; j<a[i].size(); j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "~\n";
    }
    return 0;
}
