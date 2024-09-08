#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k){
    map<int, int> numsfreq;
    for (int i=0; i<nums.size(); i++){
        ++numsfreq[nums[i]];
    }
    vector<int> elnum;
    vector<int> freqnum;
    for (auto i=numsfreq.begin(); i!=numsfreq.end(); i++){
        //printf("i->first = %d, i->second = %d \n", i->first, i->second);
        printf("%d %d \n", i->first, i->second);
        elnum.push_back(i->first);
        freqnum.push_back(i->second);
    }
    int j;
    int maxf = freqnum[0];
    int ogk = k;
    for (int i=1; i<elnum.size(); i++){
        j = i-1;
        k = ogk;
        int curfreq = freqnum[i];
        while ((k>0) && (j>=0)){
            //printf("i = %d, j = %d, elnum[i] = %d, elnum[j] = %d, k = %d, maxf = %d, freqnum[i] = %d, freqnum[j] = %d, curfreq = %d \n", i, j, elnum[i], elnum[j], k, maxf, freqnum[i], freqnum[j], curfreq);
            if (k >= (((long)(elnum[i]-elnum[j]))*((long)(freqnum[j])))){
                k = k - ((elnum[i]-elnum[j])*freqnum[j]);
                curfreq += freqnum[j];
                maxf = max(maxf, curfreq);
                --j;
                continue;
            }
            else if ((elnum[i]-elnum[j]) > k){
                maxf = max(maxf, curfreq);
                break;
            }
            else{
                //printf("in else block, i = %d, j = %d, elnum[i] = %d, elnum[j] = %d, k = %d, maxf = %d, freqnum[i] = %d, freqnum[j] = %d, curfreq = %d \n", i, j, elnum[i], elnum[j], k, maxf, freqnum[i], freqnum[j], curfreq);
                curfreq += ((int)(k/(elnum[i]-elnum[j])));
                k = k - (((int)(k/(elnum[i]-elnum[j])))*((elnum[i]-elnum[j])));
                maxf = max(maxf, curfreq);
                --j;
                continue;
            }
        }
    }
    return maxf;
}

int main(){
    int k;
    int x;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin >> x;
        nums[i] = x;
    }
    cin >> k;
    printf("%d \n", maxFrequency(nums, k));
    return 0;
}