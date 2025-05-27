#include <bits/stdc++.h>
using namespace std;

vector<int> shell_sort(vector<int>& c){
    int gap = ceil(c.size()/2.0);
    while (1){
        for (int i=0; (i+gap)<c.size(); i++){
            if (c[i] > c[i+gap]){
                swap(c[i], c[i+gap]);
            }
        }
        if (gap == 1){
            break;
        }
        gap = ceil(gap/2.0);
    }
    return c;
}

int main(){
    vector<int> c = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> sorted_c = shell_sort(c);
    for (int i=0; i<sorted_c.size(); i++){
        cout << sorted_c[i] << " ";
    }
    return 0;
}