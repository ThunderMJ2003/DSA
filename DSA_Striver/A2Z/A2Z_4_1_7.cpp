//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // int countFreq(vector<int>& arr, int target){
    //     int l = 0, h = arr.size()-1;
    //     int m = (l+h)/2;
    //     int found = 0;
    //     while (l<=h){
    //         m = (l+h)/2;
    //         if (arr[m] == target){
    //             found = 1;
    //             break;
    //         }
    //         else if (arr[m] < target){
    //             l = m+1;
    //         }
    //         else{
    //             h = m-1;
    //         }
    //     }
    //     if (found == 0){
    //         return 0;
    //     }
    //     int fin = 1;
    //     for (int i=(m-1); i>=0; i--){
    //         if (arr[i] != target){
    //             break;
    //         }
    //         ++fin;
    //     }
    //     for (int i=(m+1); i<arr.size(); i++){
    //         if (arr[i] != target){
    //             break;
    //         }
    //         ++fin;
    //     }
    //     return fin;
    // }

    // int countFreq(vector<int>& arr, int target){
    //     if (arr.size() == 0){
    //         return 0;
    //     }
    //     int x = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    //     int y = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    //     if ((x>=0) && (x<arr.size()) && (arr[x] == target)){
    //         return y-x;
    //     }
    //     return 0;
    // }

    int countFreq(vector<int>& arr, int target){
        int l = 0, h = arr.size()-1;
        int m = (l+h)/2;
        int fin0 = -1, fin1 = -1;
        while (l<=h){
            m = (l+h)/2;
            if ((arr[m] == target) && ((m == 0) || (arr[m-1] != target))){
                fin0 = m;
                break;
            }
            else if (arr[m] < target){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        l = 0;
        h = arr.size()-1;
        while (l<=h){
            m = (l+h)/2;
            if ((arr[m] == target) && ((m == (arr.size()-1)) || (arr[m+1] != target))){
                fin1 = m;
                break;
            }
            else if (arr[m] > target){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        if (fin1 == -1){
            return 0;
        }
        return (fin1-fin0+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        // int n;
        // cin >> n;
        // cin.ignore();
        // vector<vector<int>> a;
        // for (int i=0; i<n; i++){
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

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        int ans = obj.countFreq(a, n);

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