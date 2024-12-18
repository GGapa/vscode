// The Smallest String Concatenation CodeForces - 632C
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
    vector<string> a(n);
    for(auto & i : a) cin >> i;
    sort(a.begin(), a.end(), [](const string & x, const string &y) {
        return x + y < y + x;
    });
    for(auto i : a) cout << i;

    return 0;
}