/*
T365428 「Daily OI Round 1」Xor
https://www.luogu.com.cn/problem/T365428?contestId=123625
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

int n, q;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    while(q--) {
        int Xor;
        cin >> Xor;
        for(int i = 0; i < n; i++) a[i] = a[i] xor Xor;
        sort(a.begin(), a.end());
        int num = 1, ans = 1;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] + 1 == a[i + 1]) num++;
            else if(a[i] == a[i + 1]) continue;
            else num = 1;
            ans = max(ans, num);
        }
        cout << ans << "\n";
    }
    return 0;
}