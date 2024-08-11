#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums;
        int i=0, j=0;
        while ((i!=m) && (j!=n)){
            if (nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                ++i;
            }
            else{
                nums.push_back(nums2[j]);
                ++j;
            }
        }
        for (i=i; i<m; i++){
            nums.push_back(nums1[i]);
        }
        for (j=j; j<n; j++){
            nums.push_back(nums2[j]);
        }
        if (((n+m)%2) == 0){
            return ((nums[(n+m)/2] + nums[((n+m)/2)-1])/2.0);
        }
        else{
            return (nums[(n+m-1)/2]);
        }
        return -1;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int m, n;
        cin >> m;
        cin >> n;
        vector<int> nums1(m);
        vector<int> nums2(n);
        for (int i=0; i<m; i++){
            cin >> nums1[i];
        }
        for (int i=0; i<n; i++){
            cin >> nums2[i];
        }
        Solution ob;
        double fin = ob.findMedianSortedArrays(nums1, nums2);
        printf("fin = %f \n", fin);
    }
    return 0;
}