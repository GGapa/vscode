#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

string l, r;

int cnt[10], ans, tmp[10], tmp2[10];
int aaa = 0;

void work() {
    rep(i, 0, 9) cnt[i] = tmp[i];
    rep(i, 0, 18) {
        if(l[i] == r[i]) {
            if(--cnt[l[i] - '0'] < 0) return ;
        }
        else {
            rep(j, l[i] - '0' + 1, r[i] - '0' - 1) if(cnt[j]) return ans++, void();
            rep(i, 0, 9) tmp2[i] = cnt[i];
            if(tmp2[l[i] - '0']) {
                bool tag = 1;
                tmp2[l[i] - '0']--;
                for(int j = i + 1, k = 9; j <= 18; j++) {
                    while(k >= 0 && tmp2[k] == 0) k--;
                    if(k < 0) tag = 0;
                    if(k < l[j] - '0') tag = 0;
                    else if(k != l[j] - '0') break;
                    tmp2[k]--;
                }
                if(tag) return ans++, void();
            }

            rep(i, 0, 9) tmp2[i] = cnt[i];
            if(tmp2[r[i] - '0']) {
                bool tag = 1;
                tmp2[r[i] - '0']--;
                for(int j = i + 1, k = 0; j <= 18; j++) {
                    while(k <= 9 && tmp2[k] == 0) k++;
                    if(k >= 10) tag = 0;
                    if(k > r[j] - '0') tag = 0;
                    else if(k != r[j] - '0')break;
                    tmp2[k]--;
                }
                if(tag) return ans++, void();
            }
            return;
        }
    }
    ans++;
}

void dfs(int x, int rem) {
    if(x == 9) {
        tmp[x] = rem;
        work();
        return ;
    }
    rep(i, (x == 0), rem) {
        tmp[x] = i, dfs(x + 1, rem - i);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> l >> r;
    while(l.size() <= 18) l = "0" + l;
    while(r.size() <= 18) r = "0" + r;
    dfs(0, 19);
    cout << ans << '\n';
    return 0;
}
