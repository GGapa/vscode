#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, s;
pair<int, int> a[N];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].first >> a[i].second;
    int ans = 0, k = 1, dir = 1;
    for(int i = s, num = 0; 1 <= i && i <= n && num <= 1e8; i += k * dir, num++) {
        if(a[i].first && a[i].second <= k) {
            ans++;
            a[i].second = INT_MAX;
        }
        if(!a[i].first) {
            dir *= -1;
            k += a[i].second;
        }
    }
    cout << ans << '\n';
    return 0;
}