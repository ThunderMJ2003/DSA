//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    //     vector<int> merged12;
    //     merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged12.begin());
    //     if ((merged12.size()%2) == 0){
    //         return (merged12[merged12.size()/2] + merged12[(merged12.size()/2) - 1])/2.0;
    //     }
    //     return merged12[(merged12.size()-1)/2];
    // }

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    //     int cnt = 0;
    //     int n = nums1.size(), m = nums2.size();
    //     int med1, med2;
    //     int i=0, j=0;
    //     while ((i < n) && (j < m)){
    //         if (nums1[i] < nums2[j]){
    //             if (cnt == ((n+m)/2)-1){
    //                 med1 = nums1[i];
    //             }
    //             if (cnt == (n+m)/2){
    //                 med2 = nums1[i];
    //                 ++cnt;
    //                 break;
    //             }
    //             ++i;
    //         }
    //         else{
    //             if (cnt == ((n+m)/2)-1){
    //                 med1 = nums2[j];
    //             }
    //             if (cnt == (n+m)/2){
    //                 med2 = nums2[j];
    //                 ++cnt;
    //                 break;
    //             }
    //             ++j;
    //         }
    //         ++cnt;
    //     }
    //     while (i < n){
    //         if (cnt == ((n+m)/2)-1){
    //             med1 = nums1[i];
    //         }
    //         if (cnt == (n+m)/2){
    //             med2 = nums1[i];
    //             ++cnt;
    //             break;
    //         }
    //         ++i;
    //         ++cnt;
    //     }
    //     while (j < m){
    //         if (cnt == ((n+m)/2)-1){
    //             med1 = nums2[j];
    //         }
    //         if (cnt == (n+m)/2){
    //             med2 = nums2[j];
    //             break;
    //         }
    //         ++j;
    //         ++cnt;
    //     }
    //     if ((n+m)%2 == 0){
    //         return (med1+med2)/2.0;
    //     }
    //     return med2;
    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int l = 0, h = nums1.size();
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        int requiredOnLeftSide = (n1+n2)/2;
        int m, m2;
        while (l <= h){
            m = (l+h)/2;
            m2 = requiredOnLeftSide - m;
            if (((m-1) >= 0) && (m2 < n2) && (nums1[m-1] > nums2[m2])){
                h = m-1;
            }
            else if (((m2-1) >= 0) && (m < n1) && (nums2[m2-1] > nums1[m])){
                l = m+1;
            }
            else{
                break;
            }
        }
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if ((m >= 0) && (m < n1)){
            r1 = nums1[m];
        }
        if ((m2 >= 0) && (m2 < n2)){
            r2 = nums2[m2];
        }
        if (((m-1) >= 0) && ((m-1) < n1)){
            l1 = nums1[m-1];
        }
        if (((m2-1) >= 0) && ((m2-1) < n2)){
            l2 = nums2[m2-1];
        }
        if ((n1+n2)%2 == 1){
            return min(r1, r2);
        }
        return (max(l1, l2) + min(r1, r2)) / 2.0;
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

        vector<int> b;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            b.push_back(num); // Read the array elements from input string

        Solution obj;
        auto ans = obj.findMedianSortedArrays(a, b);

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