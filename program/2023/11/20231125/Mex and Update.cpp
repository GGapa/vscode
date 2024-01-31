#include <iostream>
#include <map>
using namespace std;
const int maxn = 2e5 + 5;

int n, q;
int a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    while(q--) {
        int it, x;
        cin >> it >> x;
        
        cout << ans << '\n';
    }
    return 0;
}

// 树状数组？线段树？