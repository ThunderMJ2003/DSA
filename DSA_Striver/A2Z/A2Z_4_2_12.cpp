//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    // double findSmallestMaxDist(vector<int> &stations, int k){
    //     vector<int> newStations(stations.size()-1, 0);
    //     double maxd;
    //     int maxdind;
    //     for (int i=0; i<k; i++){
    //         maxd = INT_MIN;
    //         maxdind = 0;
    //         for (int j=0; j<newStations.size(); j++){
    //             if (((double)stations[j+1]-stations[j])/(1+newStations[j]) > maxd){
    //                 maxd = ((double)stations[j+1]-stations[j])/(1+newStations[j]);
    //                 maxdind = j;
    //             }
    //         }
    //         ++newStations[maxdind];
    //     }
    //     double fin = -1;
    //     maxd = INT_MIN;
    //     maxdind = 0;
    //     for (int i=0; i<newStations.size(); i++){
    //         if (((double)stations[i+1]-stations[i])/(1+newStations[i]) > maxd){
    //             maxd = ((double)stations[i+1]-stations[i])/(1+newStations[i]);
    //             maxdind = i;
    //         }
    //     }
    //     return maxd;
    // }

    // double findSmallestMaxDist(vector<int> &stations, int k){
    //     vector<int> newStations(stations.size()-1, 0);
    //     priority_queue<pair<double, int>> distances;
    //     for (int i=0; i<newStations.size(); i++){
    //         distances.push({stations[i+1]-stations[i], i});
    //     }
    //     int maxdind;
    //     for (int i=0; i<k; i++){
    //         maxdind = distances.top().second;
    //         distances.pop();
    //         ++newStations[maxdind];
    //         distances.push({((double)stations[maxdind+1]-stations[maxdind])/(1+newStations[maxdind]), maxdind});
    //     }
    //     double fin = -1;
    //     return round(distances.top().first*100)/100.0;
    // }

    // int numberOfkPossible(vector<int>& stations, double g){
    //     int totalk = 0;
    //     for (int i=0; i<(stations.size()-1); i++){
    //         totalk += (ceil)((stations[i+1]-stations[i])/g-1);
    //     }
    //     return totalk;
    // }
    // double findSmallestMaxDist(vector<int> &stations, int k){
    //     double lc = 0.0000001;
    //     double l = lc, h = stations.back()-stations[0];
    //     double m;
    //     while (l <= h){
    //         m = (l+h)/2;
    //         if (numberOfkPossible(stations, m) <= k){
    //             h = m-lc;
    //         }
    //         else{
    //             l = m+lc;
    //         }
    //     }
    //     return round(100*l)/100.0;
    // }

    int numberOfkPossible(vector<int>& stations, double g){
        int totalk = 0;
        for (int i=0; i<(stations.size()-1); i++){
            totalk += (ceil)((stations[i+1]-stations[i])/g-1);
        }
        return totalk;
    }
    double findSmallestMaxDist(vector<int> &stations, int k){
        double l = 0, h = stations.back()-stations[0];
        double m;
        while ((h-l) > 0.000001){
            m = (l+h)/2;
            if (numberOfkPossible(stations, m) <= k){
                h = m;
            }
            else{
                l = m;
            }
        }
        return h;
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
        auto ans = obj.findSmallestMaxDist(a, n);

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