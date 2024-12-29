//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
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

    int getSecondSmallest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        if (n < 2){
            return -1;
        }
        int minind = 0;
        int secondminind = -1;
        int i = 1;
        while (i < n){
            if (arr[i] > arr[minind]){
                secondminind = i;
                break;
            }
            else if (arr[i] < arr[minind]){
                minind = i;
                secondminind = 0;
                break;
            }
            ++i;
        }
        if (secondminind == (-1)){
            return -1;
        }
        while (i < n){
            if (arr[i] < arr[minind]){
                secondminind = minind;
                minind = i;
            }
            else if ((arr[i] > arr[minind]) && (arr[i] < arr[secondminind])){
                secondminind = i;
            }
            ++i;
        }
        return arr[secondminind];
    }

    vector<int> getSecondOrderElements(int n, vector<int> a) {
        // Write your code here.
        vector<int> fin;
        fin.push_back(getSecondLargest(a));
        fin.push_back(getSecondSmallest(a));
        return fin;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        vector<int> ans = ob.getSecondOrderElements(arr.size(), arr);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends