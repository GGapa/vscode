#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL s, p;  cin >> s >> p;
    for(LL i = 1; i * i <= p; i++) {
        if(p % i == 0) {
            LL n = i;
            if(n + p / n == s) return cout << "Yes\n", 0;
            n = p / i;
            if(n + p / n == s) return cout << "Yes\n", 0;
        }
    }
    cout << "No\n";
    return 0;
}