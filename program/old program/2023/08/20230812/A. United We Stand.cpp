// A.United We Stand
//https://codeforces.com/contest/1859/problem/0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        vector<int> a(n), b, c;
        for(auto &i : a) cin >> i;
        /*
        b.push_back(a[0]);
        for(int i = 1; i < n; i++) {
            if(a[i] == b[0]) {
                b.push_back(a[i]);
            }
            else {
                c.push_back(a[i]);
            }
        }
        
        */
       sort(a.begin(), a.end(), greater<int>());
       c.push_back(a[0]);
       for(int i = 1; i < n; i++) {
            if(a[i] == c[0]) {
                c.push_back(a[i]);
            }
            else {
                b.push_back(a[i]);
            }
        }
        if(b.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        cout << b.size() << " " << c.size() << endl;
        for(auto i : b) cout << i << " ";
        cout << endl;
        for(auto i : c) cout << i << " ";
        cout << endl;
    }
    return 0;
}