#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, m;
int a[N], b[N];
int stk[N], top = 0, f[25][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) {
        while(top && (a[stk[top]] == a[i] || b[stk[top]] <= b[i])) {
            f[0][stk[top]] = i;
            top--;
        }
        stk[++top] = i;
    }
    for(int i = 1; i <= 20; i++) 
        for(int j = 1; j <= n; j++) 
            f[i][j] = f[i - 1][f[i - 1][j]];
    
    for(int _ = 1, l, r; _ <= m; _++) {
        cin >> l >> r;
        int cnt = 0;
        for (int i = 20; i >= 0; i--) {
            if (f[i][l] && f[i][l] <= r) {
                cnt += 1 << i;
                l = f[i][l];
            }
        }
        cout << cnt + 1 << '\n';
    }
    
    return 0;
}
/*
倍增是处理淘汰类问题的常见套路
像这种数据范围比较大的题首先就要考虑线性或者砍掉一大堆无效的操作/步骤
*/