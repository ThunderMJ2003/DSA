//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // string frequencySort(string s){ // O(nlogn) using unordered_map, O(n)
    //     unordered_map<char, int> ctoi;
    //     for (char c : s){
    //         ++ctoi[c];
    //     }
    //     vector<pair<int, char>> itoc;
    //     for (auto i : ctoi){
    //         itoc.push_back({i.second, i.first});
    //     }
    //     sort(itoc.rbegin(), itoc.rend());
    //     string fin = "";
    //     for (auto i : itoc){
    //         fin.append(i.first, i.second);
    //     }
    //     return fin;
    // }

    // string frequencySort(string s){ // O(nlogn), O(n)
    //     vector<pair<int, char>> ctoi(62, {0, 'a'});
    //     for (char c : s){
    //         if ((c >= 'a') && (c <= 'z')){
    //             ctoi[c-'a'] = {ctoi[c-'a'].first+1, c};
    //         }
    //         else if ((c >= 'A') && (c <= 'Z')){
    //             ctoi[c-'A'+26] = {ctoi[c-'A'+26].first+1, c};
    //         }
    //         else{
    //             ctoi[c-'0'+52] = {ctoi[c-'0'+52].first+1, c};
    //         }
    //     }
    //     sort(ctoi.rbegin(), ctoi.rend());
    //     string fin = "";
    //     for (auto i : ctoi){
    //         if (i.first == 0){
    //             break;
    //         }
    //         fin.append(i.first, i.second);
    //     }
    //     return fin;
    // }

    // string frequencySort(string s){ // O(n) using map, O(n)
    //     vector<pair<int, char>> ctoi(62, {0, 'a'});
    //     for (char c : s){
    //         if ((c >= 'a') && (c <= 'z')){
    //             ctoi[c-'a'] = {ctoi[c-'a'].first+1, c};
    //         }
    //         else if ((c >= 'A') && (c <= 'Z')){
    //             ctoi[c-'A'+26] = {ctoi[c-'A'+26].first+1, c};
    //         }
    //         else{
    //             ctoi[c-'0'+52] = {ctoi[c-'0'+52].first+1, c};
    //         }
    //     }
    //     map <int, vector<char>> itoc;
    //     for (auto i : ctoi){
    //         if (i.first == 0){
    //             continue;
    //         }
    //         itoc[i.first].push_back(i.second);
    //     }
    //     string fin = "";
    //     for (auto i=itoc.rbegin(); i!=itoc.rend(); i++){
    //         for (char c : (*i).second){
    //             fin.append((*i).first, c);
    //         }
    //     }
    //     return fin;
    // }

    string frequencySort(string s){ // O(n), O(n)
        vector<pair<int, char>> ctoi(62, {0, 'a'});
        for (char c : s){
            if ((c >= 'a') && (c <= 'z')){
                ctoi[c-'a'] = {ctoi[c-'a'].first+1, c};
            }
            else if ((c >= 'A') && (c <= 'Z')){
                ctoi[c-'A'+26] = {ctoi[c-'A'+26].first+1, c};
            }
            else{
                ctoi[c-'0'+52] = {ctoi[c-'0'+52].first+1, c};
            }
        }
        vector<vector<char>> itoc(s.size()+1);
        for (auto i : ctoi){
            itoc[i.first].push_back(i.second);
        }
        string fin = "";
        for (int i=(itoc.size()-1); i>0; i--){
            for (char c : itoc[i]){
                fin.append(i, c);
            }
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

        string a;
        getline(cin, a);
        // string b;
        // getline(cin, b);
        // stringstream ss(input);
        // string st;
        // vector<string> a;
        // while (ss >> st)
        //     a.push_back(st);

        Solution obj;
        auto ans = obj.frequencySort(a);

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