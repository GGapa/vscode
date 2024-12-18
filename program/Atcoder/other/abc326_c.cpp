#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3e6 + 5;
#define int long long

int a[maxn];
int n, m;
int ans = 0;
vector<int> vec;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        vec.push_back(a[i]);
        while(!vec.empty() && vec.back() - vec.front() >= m) {
            vec.pop_back();
        }
        ans = max(ans, (int)vec.size());
    }
    cout << ans << "\n";
    return 0;
}
 