//Milk Pails

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int x, y, z;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> x >> y >> z;
    
    for(int i = 0; i * x <= z; i++) 
        for(int j = 0; i * x + j * y <= z; j++) 
            ans = max(ans, i * x + j * y);
    cout << ans << '\n';

    return 0;
}