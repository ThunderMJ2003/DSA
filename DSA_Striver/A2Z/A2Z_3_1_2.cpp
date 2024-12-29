//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    // int print2largest(int arr[], int n) {
    //     // code here
    //     int max1 = arr[0];
    //     int min1 = arr[0];
    //     for (int i=0; i<n; i++){
    //         max1 = max(max1, arr[i]);
    //         min1 = min(min1, arr[i]);
    //     }
    //     if (max1==min1){
    //         return -1;
    //     }
    //     int max2 = min1;
    //     for (int i=0; i<n; i++){
    //         if ((arr[i]>max2) && (arr[i]<max1)){
    //             max2 = arr[i];
    //         }
    //     }
    //     return max2;
    // }

    int print2largest(int arr[], int n) {
        // Code Here
        if (n < 2){
            return -1;
        }
        int maxind = 0;
        int secondmaxind = -1;
        int i = 1;
        while (i < n){
            if (arr[i] < arr[maxind]){
                secondmaxind = i;
                break;
            }
            else if (arr[i] > arr[maxind]){
                maxind = i;
                secondmaxind = 0;
                break;
            }
            ++i;
        }
        if (secondmaxind == (-1)){
            return -1;
        }
        while (i < n){
            if (arr[i] > arr[maxind]){
                secondmaxind = maxind;
                maxind = i;
            }
            else if ((arr[i] < arr[maxind]) && (arr[i] > arr[secondmaxind])){
                secondmaxind = i;
            }
            ++i;
        }
        return arr[secondmaxind];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends