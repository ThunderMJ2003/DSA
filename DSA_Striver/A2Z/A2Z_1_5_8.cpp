#include <bits/stdc++.h>
using namespace std;

// bool recurseisPalindrome(string s){
//     int n = s.length();
//     int i = 0;
//     int j = n-1;
//     while (i<j){
//         if (s[i]!=s[j]){
//             return false;
//         }
//         ++i;
//         --j;
//     }
//     return true;
// }

// bool isPalindrome(string s){
//     string cleans = "";
//     for (int i=0; i<s.length(); i++){
//         if (((s[i]>='a')&&(s[i]<='z')) || ((s[i]>='0')&&(s[i]<='9'))){
//             cleans.push_back(s[i]);
//         }
//         if ((s[i]>='A')&&(s[i]<='Z')){
//             cleans.push_back(s[i]-'A'+'a');
//         }
//     }
//     return recurseisPalindrome(cleans);
bool isPalindrome(string s) {
    int i=0, j=s.size()-1;
    while (i<j){
        while ((i<j) && (!isalnum(s[i]))){
            ++i;
        }
        while ((i<j) && (!isalnum(s[j]))){
            --j;
        }
        //cout << s[i] << " " << s[j] << endl;
        if (tolower(s[i]) != tolower(s[j])){
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    printf("%d \n", isPalindrome(s));
    return 0;
}