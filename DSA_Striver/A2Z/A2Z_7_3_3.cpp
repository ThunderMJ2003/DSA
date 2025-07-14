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
    // vector<string> markX(vector<string> curboard, int r, int c, int n){
    //     for (int i=0; i<n; i++){
    //         if (curboard[i][c] != 'Q'){
    //             curboard[i][c] = 'X';
    //         }
    //     }
    //     for (int i=0; i<n; i++){
    //         if (curboard[r][i] != 'Q'){
    //             curboard[r][i] = 'X';
    //         }
    //     }
    //     int i, j;
    //     i = r+1;
    //     j = c+1;
    //     while ((i < n) && (j < n)){
    //         curboard[i][j] = 'X';
    //         ++i;
    //         ++j;
    //     }
    //     i = r+1;
    //     j = c-1;
    //     while ((i < n) && (j >= 0)){
    //         curboard[i][j] = 'X';
    //         ++i;
    //         --j;
    //     }
    //     i = r-1;
    //     j = c-1;
    //     while ((i >= 0) && (j >= 0)){
    //         curboard[i][j] = 'X';
    //         --i;
    //         --j;
    //     }
    //     i = r-1;
    //     j = c+1;
    //     while ((i >= 0) && (j < n)){
    //         curboard[i][j] = 'X';
    //         --i;
    //         ++j;
    //     }
    //     return curboard;
    // }
    // void sNQhelper(vector<vector<string>>& fin, int queensLeft, int r, int c, vector<string>& curboard, int n){
    //     if (queensLeft == 0){
    //         vector<string> toAddboard;
    //         string tempstr;
    //         for (auto i : curboard){
    //             tempstr = "";
    //             for (auto j : i){
    //                 if (j == 'Q'){
    //                     tempstr += 'Q';
    //                 }
    //                 else{
    //                     tempstr += '.';
    //                 }
    //             }
    //             toAddboard.push_back(tempstr);
    //         }
    //         fin.push_back(toAddboard);
    //         return;
    //     }
    //     vector<string> newboard;
    //     for (int j=c; ((j<n) && (r<n)); j++){
    //         if (curboard[r][j] != 'X'){
    //             curboard[r][j] = 'Q';
    //             newboard = markX(curboard, r, j, n);
    //             if (j != (n-1)){
    //                 sNQhelper(fin, queensLeft-1, r, j+1, newboard, n);
    //             }
    //             else{
    //                 sNQhelper(fin, queensLeft-1, r+1, 0, newboard, n);
    //             }
    //             curboard[r][j] = '.';
    //         }
    //     }
    //     for (int i=(r+1); i<n; i++){
    //         for (int j=0; j<n; j++){
    //             if (curboard[i][j] != 'X'){
    //                 curboard[i][j] = 'Q';
    //                 newboard = markX(curboard, i, j, n);
    //                 if (j != (n-1)){
    //                     sNQhelper(fin, queensLeft-1, i, j+1, newboard, n);
    //                 }
    //                 else{
    //                     sNQhelper(fin, queensLeft-1, i+1, 0, newboard, n);
    //                 }
    //                 curboard[i][j] = '.';
    //             }
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n){
    //     vector<vector<string>> fin;
    //     vector<string> curboard;
    //     string tempstr;
    //     for (int i=0; i<n; i++){
    //         tempstr += '.';
    //     }
    //     for (int i=0; i<n; i++){
    //         curboard.push_back(tempstr);
    //     }
    //     sNQhelper(fin, n, 0, 0, curboard, n);
    //     return fin;
    // }

    // bool doesThisWork(vector<pair<int, int>>& queensPos, int r, int c){
    //     for (auto rc : queensPos){
    //         if (rc == queensPos.back()){
    //             break;
    //         }
    //         if ((rc.first == r) || (rc.second == c) || (abs(rc.first - r) == abs(rc.second - c))){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // void sNQhelper(vector<vector<string>>& fin, int queensLeft, vector<pair<int, int>> queensPos, int n){
    //     if (queensLeft == 0){
    //         vector<string> toAddboard;
    //         string tempstr(n, '.');
    //         for (int i=0; i<n; i++){
    //             toAddboard.push_back(tempstr);
    //         }
    //         for (auto rc : queensPos){
    //             toAddboard[rc.first][rc.second] = 'Q';
    //         }
    //         fin.push_back(toAddboard);
    //         return;
    //     }
    //     int r, c;
    //     if (queensPos.empty()){
    //         r = 0;
    //         c = 0;
    //     }
    //     else{
    //         r = queensPos.back().first;
    //         c = queensPos.back().second;
    //     }
    //     queensPos.push_back({-1, -1});
    //     for (int j=c; j<n; j++){
    //         if (doesThisWork(queensPos, r, j)){
    //             queensPos.back() = {r, j};
    //             sNQhelper(fin, queensLeft-1, queensPos, n);
    //         }
    //     }
    //     for (int i=(r+1); i<n; i++){
    //         for (int j=0; j<n; j++){
    //             if (doesThisWork(queensPos, i, j)){
    //                 queensPos.back() = {i, j};
    //                 sNQhelper(fin, queensLeft-1, queensPos, n);
    //             }
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n){
    //     vector<vector<string>> fin;
    //     sNQhelper(fin, n, {}, n);
    //     return fin;
    // }

    void sNQhelper(int n, vector<vector<string>>& fin, int currow, vector<bool>& colEmpty, vector<bool>& upRightEmpty, vector<bool>& downRightEmpty, vector<string>& curboard){
        if (currow == n){
            fin.push_back(curboard);
            return;
        }
        for (int i=0; i<n; i++){
            if (colEmpty[i] & upRightEmpty[currow+i] & downRightEmpty[n-1-i+currow]){
                curboard[currow][i] = 'Q';
                colEmpty[i] = false;
                upRightEmpty[currow+i] = false;
                downRightEmpty[n-1-i+currow] = false;
                sNQhelper(n, fin, currow+1, colEmpty, upRightEmpty, downRightEmpty, curboard);
                curboard[currow][i] = '.';
                colEmpty[i] = true;
                upRightEmpty[currow+i] = true;
                downRightEmpty[n-1-i+currow] = true;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> fin;
        vector<bool> colEmpty(n, true);
        vector<bool> upRightEmpty(2*n-1, true);
        vector<bool> downRightEmpty(2*n-1, true);
        string tempstr(n, '.');
        vector<string> curboard;
        for (int i=0; i<n; i++){
            curboard.push_back(tempstr);
        }
        sNQhelper(n, fin, 0, colEmpty, upRightEmpty, downRightEmpty, curboard);
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

        int n;
        cin >> n;
        cin.ignore();

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
        auto ans = obj.solveNQueens(n);

        // cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // for (auto i=ans; i!=nullptr; i=i->next){
        //     printf("%d ", i->data);
        // }
        for (int i=0; i<ans.size(); i++){
            for (int j=0; j<ans[i].size(); j++){
                cout << ans[i][j] << endl;
            }
            cout << endl;
        }
        cout << "~\n";
    }
    return 0;
}
