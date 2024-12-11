#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using ULL = unsigned long long ;

struct Hash {
    int n; vector<ULL> XP, H;
    void init(string & s, ULL x) {
        n = s.size(); XP.resize(n + 1); H.resize(n + 1);
        XP[0] = 1;
        rep(i, 1, n) XP[i] = x * XP[i - 1] ;

        ULL res = 0;
        for (int i = 0; i < s.size(); ++i) res = res * x + s[i], H[i] = res;
    } 
    ULL c_hash(int i, int j) {
        return H[j] - H[i] * XP[j - i];
    }
}hh;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s; 
    int n = s.size(); s = "0" + s;
    // s = " " + s;
    hh.init(s, 233);
    // cerr << hh.c_hash(1, 2) << " " << hh.c_hash(7, 8) << '\n';
    
    vector<int> f(n + 1), g(n + 1);

    auto cmp = [&](int a, int b, int x, int y) {
        if(a == 1 && b == 3 && x == 4 && y == 9) {
            y++; y--;
        }
        while(a < b && s[a] == '0') a++;
        while(x < y && s[x] == '0') x++;

        if(b - a != y - x) return b - a < y - x;
        int l = 0, r = y - x, ans = y - x;
        while (l <= r) {
            int mid = l + r  >> 1;
            if(hh.c_hash(a - 1, a + mid) == hh.c_hash(x - 1, x + mid)) l = mid + 1;
            else r = mid - 1, ans = mid;
        }

        return s[a + ans] < s[x + ans];
    };

    f[1] = 1;
    rep(i, 2, n) per(j, i, 2) {
        if(cmp(f[j - 1], j - 1, j, i)) {
            f[i] = j;
            break;
        }
        if(f[i] == 0) f[i] = 1;
    }

    
    int t = f[n];
    g[t] = n;
    while(t - 1 >= 1&& s[t - 1] == '0')  g[t-- - 1] = n;
    per(i, t - 1, 1) per(j, f[n] - 1, i) {
        if(cmp(i, j, j + 1, g[j + 1])) {
            g[i] = j;
            break;
        }
    }

    string ans;
    for(int i = 1; i <= n; i = g[i] + 1) {
        rep(j, i, g[i]) ans += s[j];
        if(g[i] != n) ans += ',';
    }
    cout << ans << '\n';
    return 0;
}
/*
考虑使用两次 DP 第一次处理出最小的一个 F(j)
第二次处理出
*/