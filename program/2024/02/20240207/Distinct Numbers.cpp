//Distinct Numbers CSES - 1621 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    set<int> s;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
    
    return 0;
}