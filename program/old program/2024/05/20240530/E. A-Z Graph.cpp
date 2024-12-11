#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 2e5 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    unordered_map<ll, char> mp; 
    int ou = 0, ji = 0;
    for(int o = 1; o <= m; o++) {
        char c; cin >> c;
        int x, y; 
        if(c == '+') {
            cin >> x >> y >> c;
            int f = (x < y ? 1 : -1);
            int id = min(x, y) * N + max(x, y); id *= f;
            mp[id] = c;
            if(mp[id] == mp[-id] && mp[-id] != '\0') ou++; 
            if(mp[-id] != '\0') ji++;
        }
        else if(c == '-') {
            cin >> x >> y;
            int f = (x < y ? 1 : -1);
            int id = min(x, y) * N + max(x, y); id *= f;
            if(mp[id] == mp[-id] && mp[-id] != '\0') ou--;
            if(mp[-id] != '\0') ji--;
            mp[id] = '\0';
        }
        else {
            cin >> x;
            if((x % 2 == 1 && ji) || (x % 2 == 0 && ou)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}