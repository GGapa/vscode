#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;

int n, t;
int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    t = INT_MAX;
    for(int i = 1; i <= n; i++) cin >> a[i], t = min(t, a[i] / 4);    
    int ans = 0;
    ans += 6;
    set<int> s;
    for(int i = 4; i <= t; i++) {
        s.clear();
        for(int j = 1; j <= n; j++) 
            s.insert(a[j] % i);
        if(s.size() <= 3) 
            ans += i;
    }
    cout << ans << '\n';
    return 0;
}
//Cowlendar