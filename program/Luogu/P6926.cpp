#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    auto check = [&](vector<int> A, int x, int sum) {
        if (x == 1 && sum != 2) return false;
        for (int i = x, l = 1, r = n; i; i--) {  // 从两端开始查找
            if ((A[l] -= i) < 0) return false;
            while (l < r && A[l] == 0) l++;
            if ((A[r] -= i) < 0) return false;
            while (l < r && A[r] == 0) r--;
        }
        return true;
    };
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int s;
    if((s = accumulate(A.begin(), A.end(), 0)) & 1) return cout << "no quotation" << '\n', 0;

    
    int k = min(A[1], A[n]);
    while(k && !check(A, k, s)) k--;
    if(k) cout << k << '\n';
    else cout << "no quotation" << '\n', 0;

    return 0;
}