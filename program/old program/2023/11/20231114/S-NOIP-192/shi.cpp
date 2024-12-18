/**
 * @Problem      : 失落的帝国
 * @URL          : http://47.94.97.204/contest/350/problem/4
 * @Author       : GGapa
 * @Date         : 2023-11-14 15:13:08
 * @LastEditTime : 2023-11-14 18:07:09
**/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 5;

int T;
int n, m, mi = 2e9;
struct Node {
    int u, v, l, r, id;
}a[maxn];
int fa[maxn];
int ans[maxn];
bool used[maxn];

bool islr = true, mn_1 = true;

int read() {
    char c;
    int x = 0, f = 1;
    c = getchar();
    while(!isdigit(c)) {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

namespace lr {
    int main() {
        sort(a + 1, a + 1 + m, [](const Node& x, const Node& y){return x.l < y.l;}) ;
        for(int i = 1; i <= m; i++) {
            int A = find(a[i].u), B = find(a[i].v);
            if(A == B || a[i].id >= n || used[a[i].l]) {
                cout << "NO\n";
                return 0;
            }
            used[a[i].l] = true;
            ans[a[i].id] = a[i].l;
            fa[B] = A;
        }
        cout << "YES\n";
        for(int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
        return 0;
    }
}

namespace MN_1 {
    int check(int x, int y) {
        for(int i = x; i <= y; i++) {
            if(!used[i]) return i;
        }
        return 0;
    }
    int main() {
        sort(a + 1, a + 1 + m, [](const Node& x, const Node& y){
            if(x.r == y.r)
                return x.l < y.l;
            return x.r < y.r;
        });
        int cnt = n, last = a[1].l;
        for(int i = 1; i <= m; i++) {
            int A = find(a[i].u), B = find(a[i].v);
            int vv = check(a[i].l, a[i].r);
            if(A == B || vv == 0) {
                cout << "NO\n";
                return 0;
            }
            cnt--;
            used[vv] = true;
            ans[a[i].id] = vv;
            fa[B] = A;
        }
        if(cnt != 1) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        for(int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
        return 0;
    }
}

namespace MN {
    int check(int x, int y) {
        for(int i = x; i <= y; i++) {
            if(!used[i]) return i;
        }
        return 0;
    }
    int main() {
        int special = 0;
        sort(a + 1, a + 1 + m, [](const Node& x, const Node& y){
            if(x.r == y.r)
                return x.l < y.l;
            return x.r < y.r;
        });
        int cnt = n, last = a[1].l;
        for(int i = 1; i <= m; i++) {
            int A = find(a[i].u), B = find(a[i].v);
            if(a[i].id == m) {
                for(int kkk = a[i].r; kkk >= a[i].l; kkk--) {
                    if(!used[kkk]) {special = kkk;
                    break;
                    }
                }
                if(special == 0) {
                    cout << "NO\n";
                    return 0;
                }
                continue;
            }
            int vv = check(a[i].l, a[i].r);
            if(vv >= special && special != 0) {
                cout << "NO\n";
                return 0;
            }
            if(A == B || vv == 0) {
                cout << "NO\n";
                return 0;
            }
            cnt--;
            used[vv] = true;
            ans[a[i].id] = vv;
            fa[B] = A;
        }
        ans[m] = special;
        if(cnt != 1) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        for(int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("shi.in", "r", stdin);
    freopen("shi.out", "w", stdout);
    T = read();
    while(T--) {
        n = read(); m = read();
        memset(used, 0, sizeof(used));
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n - 1; i++) {
            ans[i] = 0;
            a[i].u = read(), a[i].v = read(), a[i].l = read(), a[i].r = read(), a[i].id = i;
            mi = min(mi, a[i].l);
            islr = a[i].l != a[i].r ? 0 : islr;
        }
        mi++;
        for(int i = n; i <= m; i++) {
            ans[i] = 0;
            a[i].u = read(), a[i].v = read(), a[i].l = read(), a[i].r = read(), a[i].id = i;
            a[i].l = max(a[i].l, mi);
            islr = a[i].l != a[i].r ? 0 : islr;
        }
        if(m < n - 1) {
            cout << "NO\n";
            continue;
        }
        if(islr) {
            lr::main();
            continue;
        }
        if(m == n - 1) {
            MN_1::main();
            continue;
        }
        MN::main(); continue;
    }
    
}

// 排序