#include <iostream>
using namespace std;
#define int long long

int n, cnt = 0;
int a[4];

void dfs(int x, int num) {
    if(cnt == n) {
        cout << a[1] + a[2] + a[3] ;
        exit(0);
    }
    if(x > 3) return;
    for(int i = 1; i <= num; i = i * 10 + 1) {
        if(x == 3) cnt++;
        a[x] = i;
        dfs(x + 1, i);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dfs(1, 112222222233);
    return 0;
}