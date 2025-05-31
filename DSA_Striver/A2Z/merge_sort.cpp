#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& c, int l, int h){
    if ((h-l+1) < 2){
        return;
    }
    int m = (h+l)/2;
    merge_sort(c, l, m);
    merge_sort(c, m+1, h);
    int i=l, j=m+1;
    vector<int> temparr;
    while ((i<=m) && (j<=h)){
        if (c[i] < c[j]){
            temparr.push_back(c[i]);
            ++i;
        }
        else{
            temparr.push_back(c[j]);
            ++j;
        }
    }
    if (i<=m){
        while (i<=m){
            temparr.push_back(c[i]);
            ++i;
        }
    }
    if (j<=h){
        while (j<=h){
            temparr.push_back(c[j]);
            ++j;
        }
    }
    for (int i=0; i<temparr.size(); i++){
        c[i+l] = temparr[i];
    }
    return;
}

int main(){
    vector<int> c = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(c, 0, c.size()-1);
    for (int i=0; i<c.size(); i++){
        cout << c[i] << " ";
    }
    return 0;
}