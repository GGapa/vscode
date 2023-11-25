// 2023-10-30 11:35
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5 + 5;
#define int long long

int T;
int n, q;
int a[maxn], x[maxn], poww[40], pos[maxn];
bool used[40];
queue<int> que[40];

void init() {
    poww[0] = 1;
    for(int i = 1; i <= 31; i++) poww[i] = poww[i-1] * 2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> T;
    while(T--) {
        memset(used, 0, sizeof(used));
        memset(pos, 0, sizeof(pos));
        memset(a, 0, sizeof(a));
        for(int i = 0; i <= 31; i++) while(!que[i].empty()) que[i].pop();

        cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1, x; i <= q; i++) {
            cin >> x;
            if(!used[x]) {
                for(int j = 1; j <= n; j++) {
                    if(pos[j] != x && a[j] % poww[x] == 0) {
                        que[x].push(j);
                    }
                }
                used[x] = true;
            }
            while(!que[x].empty()) {
                int top = que[x].front();
                a[top] += poww[x-1];
                pos[top] = x-1;
                que[x-1].push(top);
                que[x].pop();
            }
        }

        for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    }
    return 0;
}