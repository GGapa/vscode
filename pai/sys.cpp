#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int cnt = 0; ; ) {
        system("./data");
        system("./baoli");
        system("./user");
        if(system("cmp data.out user.out")) exit(0);
        cerr << ++cnt << '\n';
    }
    return 0;
}