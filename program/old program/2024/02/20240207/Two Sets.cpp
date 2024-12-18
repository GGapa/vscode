//Two Sets 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int s = (n + 1) * n / 2;
    if(s % 2) {
        cout << "NO\n";
        return 0;
    }
    vector<int> ans[2];
    ans[0].push_back(n);
    int it = 1;
    if(n % 2) {
    for(int i = n - 1; i >= 1; i -= 2,it ^= 1) 
        for(int j = i; j >= i - 1 && j >= 3; j--) ans[it].push_back(j);
        it ^= 1; ans[it].push_back(1); ans[it].push_back(2);
    }
    else 
    for(int i = n - 1; i >= 1; i -= 2,it ^= 1) 
        for(int j = i; j >= i - 1 && j >= 1; j--) ans[it].push_back(j);

    cout << "YES\n";
    cout << ans[0].size() << '\n';
    for(auto i : ans[0]) cout << i << " ";
    cout << '\n' << ans[1].size() << '\n';
    for(auto i : ans[1]) cout << i << ' ';
    return 0;
}