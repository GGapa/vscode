// 报数游戏（第十三届国赛 T2）
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int X, Y, K; cin >> X >> Y >> K;
    int n = X + Y;
    vector<int> A(n + 1, 1);
    for(int i = 1, cnt = 0, num = 0; cnt < Y; i++) {
        if(i > n) i = 1;
        if(A[i]) num++;
        if(num == K) num = 0, A[i] = 0, cnt++;
    }
    rep(i, 1, n) if(A[i]) cout << i << ' ';
    return 0;
}