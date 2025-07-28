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
    // vector<int> findPrimeFactors(int n){
    //     vector<bool> primeseive(n, true);
    //     primeseive[0] = false;
    //     primeseive[1] = false;
    //     int curind = 2;
    //     long long i;
    //     vector<int> fin;
    //     while (curind <= n){
    //         if (primeseive[curind]){
    //             i = (long long)curind*curind;
    //             while (i < n){
    //                 primeseive[i] = false;
    //                 i = i + curind;
    //             }
    //             while ((n % curind) == 0){
    //                 fin.push_back(curind);
    //                 n = n / curind;
    //             }
    //         }
    //         ++curind;
    //     }
    //     return fin;
    // }

    vector<int> findPrimeFactors(int n){
        vector<int> primeseive(n+1, INT_MAX);
        primeseive[0] = 0;
        primeseive[1] = 1;
        int curind = 2;
        long long i;
        while (curind <= n){
            if (primeseive[curind] == INT_MAX){
                primeseive[curind] = curind;
                i = (long long)curind*curind;
                while (i <= n){
                    primeseive[i] = min(primeseive[i], curind);
                    i = i + curind;
                }
            }
            ++curind;
        }
        vector<int> fin;
        while (n != 1){
            fin.push_back(primeseive[n]);
            n = n/primeseive[n];
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
        auto ans = obj.findPrimeFactors(n);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
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
