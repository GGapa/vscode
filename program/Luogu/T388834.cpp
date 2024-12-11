#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

int n, v;
vector<pair<int, int> > a[maxn];
vector<pair<int, int> > now;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> v;
    for(int i = 1, s; i <= n; i++) {
        cin >> s;
        a[i].resize(s);
        for(auto j : a[i]) cin >> j.first >> j.second;
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        now.resize(0);
        for(int i = l; i <= r; i++) {
            
        }
    }
    return 0;
}