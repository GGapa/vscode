#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans=0;
    cin >> n >> k;
    for(int i = 1, t; i <= n; i++) {
        cin >> t;
        ans += (t >= k);
    }
    cout << ans << '\n';
    return 0;
}