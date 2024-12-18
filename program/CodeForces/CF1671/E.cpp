#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;
const int N = 1 << 20, mod = 998244353;

int F[N];
string A[N];
int m;
string s; 


#define ls (x << 1)
#define rs ((x << 1) | 1)

void dfs(int x) {
    A[x] = s[x];
    if(ls > m) return F[x] = 1, void();
    dfs(ls); dfs(rs) ;
    if(A[ls] == A[rs]) F[x] = F[ls] * F[rs] % mod;
    else F[x] = F[ls] * F[rs] * 2 % mod;
    if(A[ls] < A[rs]) A[x] += A[ls] + A[rs];
    else A[x] += A[rs] + A[ls];
}

#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    m = (1 << n) - 1;
    cin >> s; s = " " + s;
    dfs(1) ;
    cout << F[1] << '\n';
    return 0;
}