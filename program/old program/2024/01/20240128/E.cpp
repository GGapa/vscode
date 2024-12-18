#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

pair<int, int> a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second) swap(a[i].second, a[i].first);
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i < n; i++) {
        if((a[i + 1].first <= a[i].second && a[i].second <= a[i + 1].second) || (a[i + 2].first <= a[i].second && a[i].second <= a[i + 2].second)) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No";
    return 0;
}