#include <iostream>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        int n, p;
        cin >> n >> p;
        if(n < p * 2 + 1) {cout << -1 << "\n"; continue;}
        int len = p * 2 + 1;
        int slen = n - len;
        for(int i = 1; i <= slen; i++) cout << "0";
        for(int i = 1; i <= len; i++) 
            cout << ((i % 2) ? ("1") : ("0"));
        //if(p != 0) cout << "1";
        cout << "\n";
    }
    return 0;
}