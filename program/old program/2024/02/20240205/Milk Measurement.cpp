// Milk Measurement
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;
struct cow{
    int ch, id;
    string name;
}a[103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        int d; cin >> d;
        cin >> a[d].name >> a[d].ch;
        if(a[d].name == "Mildred") a[d].id = 1;
        if(a[d].name == "Elsie") a[d].id = 2;
        if(a[d].name == "Bessie") a[d].id = 3;
    }
    vector<int> tp{1, 2, 3};
    int ans = 0, m[4];
    m[1] = m[2] = m[3] = 7;
    rep(i, 1, 100) {
        vector<int> nw;
        int itt = 0, cntt = 0; 
        if(a[i].id == 0) continue;
        m[a[i].id] += a[i].ch;
        int mx = 0, mn = INT_MAX;
        rep(i, 1, 3) mx = max(mx, m[i]);
        rep(i, 1, 3) if(m[i] == mx) nw.push_back(i);
        if(tp != nw) tp = nw, ans++;
    }
    cout << ans << '\n';

    return 0;
}