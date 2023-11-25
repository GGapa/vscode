#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, y, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> y >> n >> m;
    vector<int> a(m);
    for(auto& i : a) cin >> i;
    sort(a.begin(), a.end(), greater<>());
    int ans = 0;
    while(y > 0) {
        if(y <= n) ans++, y -= n;
        else if(y % a[a.size() - 1] <= n) ans += 1 + (int)(y % a[a.size() - 1] > 0), y /= a[a.size() - 1];
        else ans++, y -= n;
    }
    cout << ans << "\n";
    return 0;
}