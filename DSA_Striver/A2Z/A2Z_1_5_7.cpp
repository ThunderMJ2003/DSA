//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    // string reverseString(string str)
    // {
    //     // Your code goes here
    //     string revstr;
    //     int n = str.length();
    //     for (int i=0; i<n; i++){
    //         revstr.push_back(str[n-i-1]);
    //     }
    //     return revstr;
    // }

    // string reverseString(string& s) {
    //     // code here
    //     reverse(s.begin(), s.end());
    //     return s;
    // }

    string reverseString(string& s) {
        int i=0, j=s.size()-1;
        while (i<j){
            swap(s[i], s[j]);
            ++i;
            --j;
        }
        return s;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseString(s) << endl;
	}
	return 0;
	
}


//  Driver Code Ends