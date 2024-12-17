#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
using tpi = tuple<int, int, int, int>;
using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n, p = 0;
    cin >> n;
    vector<tpi> a(n), b;
    for (int i = 0; i < n; i++)
    {
        auto &[l, r, k, x] = a[i];
        cin >> l >> r >> k, x = i;
    }
    sort(a.begin(), a.end(), [](tpi x, tpi y)
         { return get<2>(x) > get<2>(y); });
    b = a, sort(b.begin(), b.end(), [](tpi x, tpi y)
                { return get<1>(x) - get<0>(x) > get<1>(y) - get<0>(y); }); 
    tree<pii, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update> L;
    tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> R;
    vector<int> s(n);
    for (auto [l, r, k, x] : a)
    {
        while (p < n && get<1>(b[p]) - get<0>(b[p]) >= k)
            L.insert(make_pair(get<0>(b[p]), p)), R.insert(make_pair(get<1>(b[p]), p)), p++;
        s[x] = L.size() - R.order_of_key(make_pair(l + k, 0)) - L.order_of_key(make_pair(r - k, n));
    }
    for (int i : s)
        cout << i - 1 << '\n';
    return 0;
}