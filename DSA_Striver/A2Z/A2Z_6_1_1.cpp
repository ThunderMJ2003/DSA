#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node (int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node (int data1){
        data = data1;
        next = nullptr;
    }
};

class Solution {
    public:
};

int main(){
    vector<int> arr = {2, 4, 6, 8, 9, 11, 13, 14};
    Node* head = new Node(arr[0]);
    Node* iterll = head;
    for (int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        iterll->next = temp;
        iterll = iterll->next;
    }
    // iterll = head;
    // while (iterll != nullptr){
    //     printf("%d ", iterll->data);
    //     iterll = iterll->next;
    // }
    // cout << endl;

    // iterll = head;
    // int llsize = 0;
    // while (iterll != nullptr){
    //     ++llsize;
    //     iterll = iterll->next;
    // }
    // printf("%d \n", llsize);
    // return 0;

    iterll = head;
    int target = 11;
    int found = 0;
    int fin = 0;
    while (iterll != nullptr){
        if (iterll->data == target){
            found = 1;
            printf("%d \n", fin);
            break;
        }
        ++fin;
        iterll = iterll->next;
    }
    if (!found){
        printf("not found \n");
    }
}

// int main() {
//     int t; // Number of test cases
//     cin >> t;
//     cin.ignore(); // Ignore the newline after the integer input
//     while (t--) {
//         // int m;
//         // cin >> m;
//         // cin.ignore();
//         // int n;
//         // cin >> n;
//         // cin.ignore();
//         // vector<vector<int>> a;
//         // for (int i=0; i<m; i++){
//         //     vector<int> t;
//         //     for (int j=0; j<n; j++){
//         //         int x;
//         //         cin >> x;
//         //         t.push_back(x);
//         //     }
//         //     a.push_back(t);
//         //     t.clear();
//         // }

//         // int n;
//         // cin >> n;
//         // cin.ignore();

//         // vector<int> a;
//         // string input;

//         // // Input format: first number n followed by the array elements
//         // getline(cin, input);
//         // stringstream ss(input);
//         // int num;
//         // while (ss >> num)
//         //     a.push_back(num); // Read the array elements from input string

//         string a;
//         getline(cin, a);
//         // string b;
//         // getline(cin, b);
//         // stringstream ss(input);
//         // string st;
//         // vector<string> a;
//         // while (ss >> st)
//         //     a.push_back(st);

//         // Solution obj;
//         // auto ans = obj.beautySum(a);

//         // cout << ans << endl;
//         // for (int i=0; i<ans.size(); i++){
//         //     printf("%d ", ans[i]);
//         // }
//         // for (int i=0; i<ans.size(); i++){
//         //     for (int j=0; j<ans[i].size(); j++){
//         //         cout << ans[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         cout << "~\n";
//     }
//     return 0;
// }
