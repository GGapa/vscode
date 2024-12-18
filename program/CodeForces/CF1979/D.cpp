//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = " " + s;
    int cnt = 1;
    per(i, n - 1, 1) {
        if(s[i] == s[i + 1]) cnt++;
        else break;
    }
    if(cnt > k) return cout << -1 << '\n', void();
    int wrg = 0;
    s += " ";
    for(int i = 2, t = 1; i <= n + 1; i++) {
        if(s[i] != s[i - 1]) {
            if(t != k) wrg++;
            t = 1;
        }
        else t++;
    }
    if(wrg > 2) return cout << -1 << '\n', void();
    if(wrg == 0) {
        if(s[1] != s[k] || k == n)
            return cout << k << '\n', void(); 
        else return cout << k * 2 << '\n', void();
        
    }
    if(wrg == 1) {
        for(int i = 2, t = 1; i <= n + 1; i++) {
            if(s[i] != s[i - 1]) {
                int p = i - 1;
                if(t != k && t == k * 2) return cout << p - k << '\n', void();
                t = 1;
            }
            else t++;
        }    
        return cout << "-1\n", void();
    }
    if(wrg == 2) {
        for(int i = 2, t = 1; i <= n + 1; i++) {
            if(s[i] != s[i - 1]) {
                int p = i - 1;
                if(t != k) {
                if(s[p] == s[n]) {
                    if(cnt + k == t) return cout << p - k << '\n', void();
                    if(k - cnt == t) return cout << p << '\n', void();
                }
                else{
                    if(t == k * 2) return cout << p - k << '\n', void();
                    return cout << -1 << '\n', void();            
                }}
                t = 1;
            }
            else t++;
        }
        return cout << -1, void();
    }
    // for(int i = 2, t = 1; i <= n + 1; i++) {
    //     if(s[i] != s[i - 1]) {
    //         int p = i - 1;
    //         if(t != k) {
    //             if(s[p] != s[n]) {
    //                 if(k == t) return cout << p << '\n', void();
    //                 else if(wrg == 1 && k * 2 == t) return cout << p - k << '\n', void();
    //                 return cout << -1 << '\n', void();
    //             }
    //             else if(cnt + t == k) return cout << p << '\n', void();
    //             else if(2 * k - cnt == t) return cout << p - k << '\n', void();
    //             else return cout << -1 << '\n', void();
    //         }
    //         else {
    //             int p = i - 1;
    //             if(wrg == 0) return cout << p << '\n', void();
    //         }
    //         t = 1;
    //     }
    //     else t++;
    // }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}