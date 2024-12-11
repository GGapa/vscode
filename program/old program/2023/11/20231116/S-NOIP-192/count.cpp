#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define int long long
const int mod = 998244353;
const int maxn = 4000 + 5;
int n, m, s;
int len = 4, mul[maxn], a[maxn];
vector <int> ans;
int acnt = 0;

int qpow(int x, int y) {
    int as = 1;
    while(y != 0) {
        if(y & 1) as = as * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return as;
}

void init() {
    mul[0] = 1;
    for(int i = 1; i <= 4000; i++) {
        mul[i] = mul[i-1] * i % mod;
    }
}

bool check() {
    for(int i = 0; i < len - 3; i++)
        if((ans[i] ^ ans[i+1] ^ ans[i+2] ^ ans[i+3]) == s) 
            return false;
    return true;
}

void dfs(int x) {
    if(ans.size() == len) {
        if(check()) acnt++, acnt % mod;
        return ;
    }
    if(x > n) return;
    ans.push_back(a[x]);
    dfs(x + 1);
    ans.pop_back();
    dfs(x + 1);
}


int C(int mm, int nn) {
    return mul[nn] * qpow(mul[mm], mod - 2) % mod * qpow(mul[nn - mm], mod - 2) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    init();
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(; len <= n; len++) {
        ans.clear();
        dfs(1);
    }
    acnt += C(1, n) + C(2, n) + C(3, n);
    cout << acnt << '\n';
    return 0;
}