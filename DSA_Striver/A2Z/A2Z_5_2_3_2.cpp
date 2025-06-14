//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    string intToRoman(int num){ // O(1), O(1)
        string fin = "";
        fin.append(num/1000, 'M');
        num = num % 1000;
        if ((num/100) <= 3){
            fin.append(num/100, 'C');
        }
        else if ((num/100) == 4){
            fin += "CD";
        }
        else if ((num/100) <= 8){
            fin += "D";
            fin.append((num/100)-5, 'C');
        }
        else{
            fin += "CM";
        }
        num = num % 100;
        if ((num/10) <= 3){
            fin.append(num/10, 'X');
        }
        else if ((num/10) == 4){
            fin += "XL";
        }
        else if ((num/10) <= 8){
            fin += "L";
            fin.append((num/10)-5, 'X');
        }
        else{
            fin += "XC";
        }
        num = num % 10;
        if (num <= 3){
            fin.append(num, 'I');
        }
        else if (num == 4){
            fin += "IV";
        }
        else if (num <= 8){
            fin += "V";
            fin.append(num-5, 'I');
        }
        else{
            fin += "IX";
        }
        return fin;
    }
};

//{ Driver Code Starts.

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

        Solution obj;
        auto ans = obj.intToRoman(n);

        cout << ans << endl;
        // for (int i=0; i<ans.size(); i++){
        //     printf("%d ", ans[i]);
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

// } Driver Code Ends