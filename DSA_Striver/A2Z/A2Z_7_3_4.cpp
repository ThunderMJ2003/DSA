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
    void sMhelper(vector<vector<int>>& arr, int n, vector<string>& fin, string& curstr, int r, int c){
        if (arr[r][c] == 0){
            return;
        }
        if ((r == (n-1)) && (c == (n-1))){
            fin.push_back(curstr);
            return;
        }
        curstr += 'A';
        arr[r][c] = 0;
        if (((r+1) < n) && (arr[r+1][c] == 1)){
            curstr.back() = 'D';
            sMhelper(arr, n, fin, curstr, r+1, c);
        }
        if (((c-1) >= 0) && (arr[r][c-1] == 1)){
            curstr.back() = 'L';
            sMhelper(arr, n, fin, curstr, r, c-1);
        }
        if (((c+1) < n) && (arr[r][c+1] == 1)){
            curstr.back() = 'R';
            sMhelper(arr, n, fin, curstr, r, c+1);
        }
        if (((r-1) >= 0) && (arr[r-1][c] == 1)){
            curstr.back() = 'U';
            sMhelper(arr, n, fin, curstr, r-1, c);
        }
        arr[r][c] = 1;
        curstr.erase(curstr.end()-1);
    }
    vector<string> searchMaze(vector<vector<int>> & arr, int n){ // O(4^(n*n)), O(n*n)
        vector<string> fin;
        string tempstr;
        sMhelper(arr, n, fin, tempstr, 0, 0);
        return fin;
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

        // int k;
        // cin >> k;
        // cin.ignore();

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
        auto ans = obj.searchMaze(a, n);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
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
