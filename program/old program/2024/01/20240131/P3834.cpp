#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 4e5 + 10, N = 2e5;
int n, m, tot, a[maxn << 5], b[maxn << 5], rt[maxn << 5];
int siz;
struct node{
    int ls, rs, sum;
}t[maxn << 5];
void init(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    siz = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + siz + 1, a[i]) - b;
}
inline void modify(int& id, int pre, int l, int r, int x){
    id = ++tot;
    t[id] = t[pre];
    t[id].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid) modify(t[id].ls, t[pre].ls, l, mid, x);
    else modify(t[id].rs, t[pre].rs, mid + 1, r, x);
}
inline int query(int id1, int id2, int l, int r, int k){
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int sum1 = t[t[id1].ls].sum - t[t[id2].ls].sum;
    if (sum1 >= k) return query(t[id1].ls, t[id2].ls, l, mid, k);
    else return query(t[id1].rs, t[id2].rs, mid + 1, r, k - sum1);
}
void build_tree(){
    for (int i = 1; i <= n; i++){
        modify(rt[i], rt[i - 1], 1, siz, a[i]);     // 警钟
    }
}
void work(){
    for (int i = 1; i <= m; i++){
        int l, r, k;
        cin >> l >> r >> k;
        cout << b[query(rt[r], rt[l - 1], 1, siz, k)] << '\n';      
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    build_tree();
    work();
    return 0;
}