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
    void sShelper(vector<vector<char>>& board, int r, int c, vector<vector<bool>>& rowsLeft, vector<vector<bool>>& colsLeft, vector<vector<bool>>& blcksLeft, bool& foundAns){
        if (foundAns){
            return;
        }
        while ((r < 9) && (c < 9)){
            if (board[r][c] == '.'){
                break;
            }
            if (c < 8){
                ++c;
            }
            else{
                c = 0;
                ++r;
            }
        }
        if ((r >= 9) || (c >= 9)){
            foundAns = true;
            return;
        }
        for (int i=1; i<=9; i++){
            if (rowsLeft[r][i-1] && colsLeft[c][i-1] && blcksLeft[3*(r/3) + (c/3)][i-1]){
                board[r][c] = '0'+i;
                rowsLeft[r][i-1] = false;
                colsLeft[c][i-1] = false;
                blcksLeft[3*(r/3) + (c/3)][i-1] = false;
                sShelper(board, r, c, rowsLeft, colsLeft, blcksLeft, foundAns);
                if (foundAns){
                    return;
                }
                blcksLeft[3*(r/3) + (c/3)][i-1] = true;
                colsLeft[c][i-1] = true;
                rowsLeft[r][i-1] = true;
                board[r][c] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board){ // O(9^81), O(81)
        vector<vector<bool>> rowsLeft;
        vector<vector<bool>> colsLeft;
        vector<vector<bool>> blcksLeft;
        vector<bool> tempvec(9, true);
        for (int i=0; i<9; i++){
            rowsLeft.push_back(tempvec);
            colsLeft.push_back(tempvec);
            blcksLeft.push_back(tempvec);
        }
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] != '.'){
                    rowsLeft[i][board[i][j]-'1'] = false;
                    colsLeft[j][board[i][j]-'1'] = false;
                    blcksLeft[3*(i/3)+(j/3)][board[i][j]-'1'] = false;
                }
            }
        }
        bool foundAns = false;
        sShelper(board, 0, 0, rowsLeft, colsLeft, blcksLeft, foundAns);
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
        vector<vector<char>> a;
        for (int i=0; i<m; i++){
            vector<char> t;
            for (int j=0; j<n; j++){
                char x;
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
        obj.solveSudoku(a);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // for (auto i=ans; i!=nullptr; i=i->next){
        //     printf("%d ", i->data);
        // }
        for (int i=0; i<a.size(); i++){
            for (int j=0; j<a[i].size(); j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~\n";
    }
    return 0;
}
