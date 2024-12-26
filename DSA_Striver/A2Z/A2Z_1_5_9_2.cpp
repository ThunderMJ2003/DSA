//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
        if (N < 2){
            return N;
        }
        long long a=0, b=1;
        long long c;
        long long fin = 1;
        for (int i=2; i<(N+1); i++){
            c = a+b;
            fin += c;
            a = b%1000000007;
            b = c%1000000007;
        }
        return fin%1000000007;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends