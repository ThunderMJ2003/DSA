//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
        // vector<int> findTwoElement(vector<int>& arr){
        //     int arrsum = 0;
        //     unordered_set<int> arrset;
        //     vector<int> fin;
        //     for (int i=0; i<arr.size(); i++){
        //         arrsum = arrsum + arr[i];
        //         arrset.insert(arr[i]);
        //     }
        //     for (int i=0; i<arr.size(); i++){
        //         if (arrset.find(i+1) == arrset.end()){
        //             fin.push_back(arrsum + i+1 - (arr.size()*(arr.size()+1)/2));
        //             fin.push_back(i+1);
        //             break;
        //         }
        //     }
        //     return fin;
        // }

        // vector<int> findTwoElement(vector<int>& arr){
        //     int arrnxor = 0;
        //     for (int i=0; i<arr.size(); i++){
        //         arrnxor = arrnxor ^ arr[i] ^ (i+1);
        //     }
        //     int onebitpos = 0;
        //     while (1){
        //         if ((arrnxor & (1<<onebitpos)) != 0){
        //             break;
        //         }
        //         ++onebitpos;
        //     }
        //     int zeroxor = 0, onexor = 0;
        //     for (int i=0; i<arr.size(); i++){
        //         if ((arr[i] & (1<<onebitpos)) == 0){
        //             zeroxor = zeroxor ^ arr[i];
        //         }
        //         else{
        //             onexor = onexor ^ arr[i];
        //         }
        //         if (((i+1) & (1<<onebitpos)) == 0){
        //             zeroxor = zeroxor ^ (i+1);
        //         }
        //         else{
        //             onexor = onexor ^ (i+1);
        //         }
        //     }
        //     vector<int> fin;
        //     for (int i : arr){
        //         if (i == onexor){
        //             fin = {onexor, zeroxor};
        //             break;
        //         }
        //         if (i == zeroxor){
        //             fin = {zeroxor, onexor};
        //             break;
        //         }
        //     }
        //     return fin;
        // }

        vector<int> findTwoElement(vector<int>& arr){
            int arrsum = 0, arrsqsum = 0, Sn = arr.size()*(arr.size()+1)/2, Sn2 = arr.size()*(arr.size()+1)*(2*arr.size()+1)/6;
            for (auto i : arr){
                arrsum += i;
                arrsqsum += (i*i);
            }
            return {(-Sn + arrsum + ((Sn2 - arrsqsum)/(Sn - arrsum)))/2, (Sn - arrsum + ((Sn2 - arrsqsum)/(Sn - arrsum)))/2};
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

        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> ans = obj.findTwoElement(a);

        // cout << ans << endl;
        for (int i=0; i<ans.size(); i++){
            printf("%d ", ans[i]);
        }
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