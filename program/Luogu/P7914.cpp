#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5, mod = 1e9 + 7;

int n, m;
int dp[N][N][4], d[N][N];
char a[N];

bool check(int l, int r) {
    if(d[l][r] != -1) return d[l][r];
    if(r - l + 1 > m) return d[l][r] = 0;
    if(l > r) return d[l][r] = 1;
    // cout << 1 << endl;
    if((a[l] == '*' || a[l] == '?') && (a[r] == '*' || a[r] == '?'))
        return d[l][r] = check(l + 1, r - 1);
    else 
        return d[l][r] = 0;
}

int dfs(int l, int r, int t) {
    if(l >= r) return 0;
    if(dp[l][r][t] != -1) return dp[l][r][t];
    int ans = 0;
    if(t == 0) {
        if((a[l] == '(' || a[l] == '?') && (a[r] == '?' || a[r] == ')')) {
            ans += (check(l + 1, r - 1));
            for(int i = 0; i <= 2; i++) 
                ans = (ans + dfs(l + 1, r - 1, i))  % mod;
            for(int i =l ; i < r; i++) 
                for(int j = 0; j <= 1; j++)
                    ans = (ans + (1ll * dfs(l, i, 3) * dfs(i + 1, r, j)) % mod) % mod;
        }   
        else 
            return dp[l][r][t] = 0;
    }
    if(t == 1) {
        for(int i = l; i < r; i++) {
            if(check(l, i))
                ans = (ans + dfs(i + 1, r, 0)) % mod;
            else 
                break;
        }
        
    }
    if(t == 2) {
        for(int i = r; i > l; i--)  {
            if(check(i, r)) 
                ans = (ans + dfs(l, i - 1, 0)) % mod;
            else 
                break;
        }
    }
    if(t == 3) {
        if((a[l] == '(' || a[l] == '?') && (a[r] == '?' || a[r] == ')')) {
            ans += (check(l + 1, r - 1));
            for(int i = 0; i <= 2; i++) 
                ans = (ans + dfs(l + 1, r - 1, i))  % mod;
        }   
        else 
            return dp[l][r][t] = 0;
    }
    // cout << l << " " << r << " " << t << ' ' << ans << endl;
    return dp[l][r][t] = ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    cin >> a + 1;
    cout << dfs(1, n, 0) % mod << '\n';

    return 0;
}