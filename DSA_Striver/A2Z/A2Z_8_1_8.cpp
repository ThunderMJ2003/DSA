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
    // int divide(int dividend, int divisor){
    //     if (divisor == INT_MIN){
    //         if (dividend == INT_MIN){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if (dividend == 0){
    //         return 0;
    //     }
    //     bool isMin = false;
    //     bool isNeg = false;
    //     if (dividend < 0){
    //         if (dividend == INT_MIN){
    //             isMin = true;
    //             dividend = INT_MAX;
    //             isNeg = !isNeg;
    //         }
    //         else{
    //             dividend = abs(dividend);
    //             isNeg = !isNeg;
    //         }
    //     }
    //     if (divisor < 0){
    //         divisor = abs(divisor);
    //         isNeg = !isNeg;
    //     }
    //     int curpower = log2(dividend);
    //     int mnpltr = 1 << curpower;
    //     int curdnd = (dividend & mnpltr) >> curpower;
    //     int fin = 0;
    //     while (curpower > 0){
    //         if (curdnd < divisor){
    //             --curpower;
    //             mnpltr = mnpltr >> 1;
    //             curdnd = (curdnd << 1) + ((dividend & mnpltr) >> curpower);
    //             fin = fin << 1;
    //         }
    //         else{
    //             curdnd = curdnd - divisor;
    //             --curpower;
    //             mnpltr = mnpltr >> 1;
    //             curdnd = (curdnd << 1) + ((dividend & mnpltr) >> curpower);
    //             fin = (fin << 1) + 1;
    //         }
    //     }
    //     if (curdnd < divisor){
    //         fin = fin << 1;
    //     }
    //     else{
    //         fin = (fin << 1) + 1;
    //         curdnd = curdnd - divisor;
    //     }
    //     if (isNeg){
    //         if (isMin){
    //             return fin*(-1) + divide(-(curdnd+1), divisor);
    //         }
    //         return fin*(-1);
    //     }
    //     return fin;
    // }

    int divide(int dividend, int divisor){
        bool isNeg = false;
        long long dvdend = dividend;
        long long dvsor = divisor;
        if (dividend < 0){
            dvdend -= dividend;
            dvdend -= dividend;
            isNeg = !isNeg;
        }
        if (divisor < 0){
            dvsor -= divisor;
            dvsor -= divisor;
            isNeg = !isNeg;
        }
        int cur2power = 0;
        while ((dvsor << (cur2power+1)) <= dvdend){
            ++cur2power;
        }
        long long fin = 0;
        while ((cur2power >= 0) && (dvdend != 0)){
            if ((dvsor << cur2power) > dvdend){
                --cur2power;
                continue;
            }
            fin += ((long long)1 << cur2power);
            dvdend = dvdend - (dvsor << cur2power);
            --cur2power;
        }
        if (isNeg){
            if (fin > INT_MAX){
                return INT_MIN;
            }
            return 0-fin;
        }
        if (fin > INT_MAX){
            return INT_MAX;
        }
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
        auto ans = obj.divide(n, k);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
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
