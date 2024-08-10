// Initial Template for C++

#include <iostream>
using namespace std;

class Geeks {
public:
    void printTable(int n) {
        int multiplier = 10;
        while (multiplier > 0) {
            // Your code here
            printf("%d ", multiplier*n);
            multiplier--;
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        
        Geeks obj;
        obj.printTable(n);
    }
    return 0;
}
