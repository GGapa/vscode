#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 100000 + 5;

int n; 
string s; 

namespace A {
    constexpr int LG = __lg(N) + 1;
    int st[N][LG];

    // int query(int l, int r) {
    //     assert(l <= r);
    //     int d = __lg(r - l + 1);
    //     return min(st[l][d], st[r - (1 << d) + 1][d]); 
    // }
    void main() {
        rep(i, 1, n) {
            if(s[i - 1] == 'R' && s[i] == 'L') 
                st[i][0] = i - 2;
            else st[i][0] = i;
        }
        rep(j, 1, __lg(n)) rep(i, 1, n) st[i][j] = st[st[i][j - 1]][j - 1];
        LL ans = 0;
        rep(i, 1, n) ans += (i - st[i][__lg(n)]) / 2;
        // cerr << st[2][0] << '\n';
        cout << ans << '\n';
    }

    void check() {
        if(count(s.begin(), s.end(), 'U') + count(s.begin(), s.end(), 'D') == 0) {
            main();
            exit(0);
        }
    }
}

namespace baoli {
    vector<int> vec[N];
    int in[N], out[N];

    void main() {
        LL ans = 0;
        for(int j = 1; j <= n; j++) for(int i = j; i <= n; i += j) vec[i].emplace_back(j);

        rep(l, 1, n) if(s[l] != 'L' && s[l] != 'U') {
            rep(r, l + 1, n) if(s[r] != 'R' && s[r] != 'D') {
                int len = r - l + 1;
                for(auto h : vec[len]) {
                    int w = len / h;
                    rep(i, l, r) in[i] = 0;
                    rep(i, l, r) {
                        if(s[i] == 'L') {
                            if((i - l) / w == (i - l - 1) / w) in[i - 1]++;
                            else break;
                        }
                        else if(s[i] == 'R') {
                            if((i - l) / w == (i - l + 1) / w) in[i + 1]++;
                            else break;
                        }
                        else if(s[i] == 'U') {
                            if(i - w >= l) in[i - w]++;
                            else break;
                        }
                        else {
                            if(i + w <= r) in[i + w]++;
                            else break;
                        }
                    }
                    int mn = 2;
                    rep(i, l, r) mn = min(mn, in[i]);
                    // if(mn != 0) cerr << l << " " << r << '\n';
                    if(mn != 0) {
                        ans++;
                        goto nxt;
                    }
                }
                nxt: ;
            }
        }
        cout << ans << '\n';
    }
}


signed main() {
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> s; 
    n = s.size(); s = " " + s;
    
    A::check();
    baoli::main();

    return 0;
}