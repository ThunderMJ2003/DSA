//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // int numberOfBouquetsPossible(vector<int>& bloomDay, int k, int d){
    //     int numberOfContinousBlooms = 0;
    //     int fin = 0;
    //     for (int i : bloomDay){
    //         if (i <= d){
    //             ++numberOfContinousBlooms;
    //         }
    //         else{
    //             fin += (numberOfContinousBlooms/k);
    //             numberOfContinousBlooms = 0;
    //         }
    //     }
    //     fin += (numberOfContinousBlooms/k);
    //     //printf("fin k d = %d %d %d \n", fin, k, d);
    //     return fin;
    // }
    // int minDays(vector<int>& bloomDay, int m, int k){
    //     if (bloomDay.size() < (long long)m*k){
    //         return -1;
    //     }
    //     int low = bloomDay[min_element(bloomDay.begin(), bloomDay.end()) - bloomDay.begin()];
    //     int high = bloomDay[max_element(bloomDay.begin(), bloomDay.end()) - bloomDay.begin()];
    //     int mid;
    //     int fin = INT_MAX;
    //     while (low <= high){
    //         mid = (low+high)/2;
    //         if (numberOfBouquetsPossible(bloomDay, k, mid) >= m){
    //             fin = mid;
    //             high = mid-1;
    //         }
    //         else{
    //             low = mid+1;
    //         }
    //     }
    //     return fin;
    // }

    int numberOfBouquetsPossible(vector<int>& bloomDay, int k, int d){
        int numberOfContinousBlooms = 0;
        int fin = 0;
        for (int i : bloomDay){
            if (i <= d){
                ++numberOfContinousBlooms;
            }
            else{
                fin += (numberOfContinousBlooms/k);
                numberOfContinousBlooms = 0;
            }
        }
        fin += (numberOfContinousBlooms/k);
        //printf("fin k d = %d %d %d \n", fin, k, d);
        return fin;
    }
    int minDays(vector<int>& bloomDay, int m, int k){
        if (bloomDay.size() < (long long)m*k){
            return -1;
        }
        int low = bloomDay[min_element(bloomDay.begin(), bloomDay.end()) - bloomDay.begin()];
        int high = bloomDay[max_element(bloomDay.begin(), bloomDay.end()) - bloomDay.begin()];
        int mid;
        while (low <= high){
            mid = (low+high)/2;
            if (numberOfBouquetsPossible(bloomDay, k, mid) >= m){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
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
        
        int k;
        cin >> k;
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
        int ans = obj.minDays(a, n, k);

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