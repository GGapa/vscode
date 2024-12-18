#include <bits/stdc++.h>
int st;
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e6;

int idx = 0, ctl = 0, ctr = 0;

int hl[N], hr[N];
int nxtl[N], nxtr[N];
char bl[N], br[N];
int F[N];
int rel[N], rer[N];

void insert(string &s, int id) {
    int n = s.size();
    int il = 0, ir = 0;
    rep(i, 0, n - 1) {
        int j = n - 1 - i;
        bool tag = true;
        for(int t = hl[il]; t; t = nxtl[t]) {
            if(bl[t] == s[i]) {
                il = t; 
                tag = false;
                break;
            }
        }
        if(tag) nxtl[++ctl] = hl[il], hl[il] = ctl, bl[ctl] = s[i], il = ctl;
        tag =  true;
        for(int t = hr[ir]; t; t = nxtr[t]) {
            if(br[t] == s[j]) {
                ir = t; 
                tag = false;
                break;
            }
        }
        if(tag) nxtr[++ctr] = hr[ir], hr[ir] = ctr, br[ctr] = s[j], ir = ctr;
        if(rel[il] == rer[ir]) F[id] = max(F[id], F[rel[il]] + 1);
    }
    rel[il] = id, rer[ir] = id;
}
int ed;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << 1.0 * (&ed - &st) / 1024 / 1024 << endl;
    int n; cin >> n;
    rep(i, 1, n) {
        string s; cin >> s;
        insert(s, i);
    }
    cout << *max_element(F, F + 1 + n) << '\n';
    return 0;
}
/*

*/