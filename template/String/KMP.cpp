#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e6 + 5;

int nxt[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    int len1 = a.size(), len2 = b.size();
    a = " " + a, b = " " + b;
    for(int i = 2, j = 0; i <= len2; i++) {
        for(; j && b[i] != b[j + 1]; j = nxt[j]);
        j += (b[i] == b[j + 1]);
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= len1; i++) {
        for(; j && a[i] != b[j + 1]; j = nxt[j]);
        j += (a[i] == b[j + 1]);
        if(j == len2) {
            cout << i - len2 + 1 << '\n';
            j = nxt[j];
        }
    }
    for(int i = 1; i <= len2; i++) 
        cout << nxt[i] << " \n"[i == len2];
    return 0;
}