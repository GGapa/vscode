// Stronger Takahashi
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

array<int, 2> f1[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
array<int, 2> f2[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-2, -1}, {-2, 0}, {-2, 1}, {2, -1}, {2, 0}, {2, 1}, {-1, -2}, {0, -2}, {1, -2}, {-1, 2}, {0, 2}, {1, 2}};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int H, W; cin >> H >> W;
    vector<string> S(H + 1);
    rep(i, 0, H - 1) cin >> S[i];
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    vector<int> D(H * W + 1, -1);
    q.push({0, 0});
    while(!q.empty()) {
        int d = q.top()[0], x = q.top()[1];
        q.pop();
        if(D[x] != -1) continue;
        D[x] = d;
        for(auto i : f1) {
            int nx = x / W + i[0], ny = x % W + i[1];
            if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.') 
                q.push({d, nx * W + ny}); 
        }
        for(auto i : f2) {
            int nx = x / W + i[0], ny = x % W + i[1];
            if(0 <= nx && nx < H && 0 <= ny && ny < W) 
                q.push({d + 1, nx * W + ny}); 
        }
    }
    cout << D[H * W - 1] << '\n';
    return 0; 
}