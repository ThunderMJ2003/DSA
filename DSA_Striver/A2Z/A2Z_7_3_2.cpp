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
    bool ehelper(vector<vector<char>>& board, string word, int r, int c){
        if (word.size() <= 1){
            return true;
        }
        string tempword = word.substr(1);
        if (((c+1) < board[0].size()) && (board[r][c+1] == word[1])){
            board[r][c+1] = '0';
            if (ehelper(board, tempword, r, c+1)){
                return true;
            }
            board[r][c+1] = word[1];
        }
        if (((r+1) < board.size()) && (board[r+1][c] == word[1])){
            board[r+1][c] = '0';
            if (ehelper(board, tempword, r+1, c)){
                return true;
            }
            board[r+1][c] = word[1];
        }
        if (((c-1) >= 0) && (board[r][c-1] == word[1])){
            board[r][c-1] = '0';
            if (ehelper(board, tempword, r, c-1)){
                return true;
            }
            board[r][c-1] = word[1];
        }
        if (((r-1) >= 0) && (board[r-1][c] == word[1])){
            board[r-1][c] = '0';
            if (ehelper(board, tempword, r-1, c)){
                return true;
            }
            board[r-1][c] = word[1];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word){ // O(m*n*3^L), O(L)
        for (int r=0; r<board.size(); r++){
            for (int c=0; c<board[0].size(); c++){
                if (board[r][c] == word[0]){
                    board[r][c] = '0';
                    if (ehelper(board, word, r, c)){
                        return true;
                    }
                    board[r][c] = word[0];
                }
            }
        }
        return false;
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
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
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
        auto ans = obj.exist(a, input);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
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
