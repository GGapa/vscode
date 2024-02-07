#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n)
    {vector<pair<int, int>> ans;
    for(int x, y = n + 1; y <= n * 2; y++) {
        if((n * y) % (y - n) == 0)  ans.push_back({(n * y) / (y - n), y});
    }
    printf("%d\n", ans.size());
    for(auto i : ans) printf("1/%d = 1/%d + 1/%d\n", n, i.first, i.second);}
    return 0;
}