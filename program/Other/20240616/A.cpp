#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
using VI = vector<int>;

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string a, b; cin >> b >> a;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    int ans = 0;
    for(int i = 1; i + m - 1 <= n; i++) {
        bool tag = true;
        rep(j, 0, m - 1) if(a[i + j] != b[j + 1])  {
            tag = false;
            break;
        }
        ans += (tag == true);
    }
    cout << ans << '\n';
    return 0;
}
/*
ab
abbaabcaabc

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
using VI = vector<int>;

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
        
    return 0;
}

*/
