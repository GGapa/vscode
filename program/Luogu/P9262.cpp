#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++) 
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--) 
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

const int N = 250005;
int nxt[N], sta[N];
bool vis[N];
char ans[505][505];
vector<AI<4>> pie; 
int n, m;
void move(int dx, int dy) {
    sort(pie.begin(), pie.end(), [&](const AI<4> &a, const AI<4> &b) { 
        if (dx) return a[1] == b[1] ? (a[0] * dx > b[0] * dx) : a[1] < b[1];
        return a[0] == b[0] ? (a[1] * dy > b[1] * dy) : a[0] < b[0];
    });
    
    rep(i, 0, (int)pie.size() - 1) {
        if (!i || (dx && pie[i][1] != pie[i - 1][1]) || (dy && pie[i][0] != pie[i - 1][0])) {
            if (dx) pie[i][0] = dx < 0 ? 1 : n;
            else pie[i][1] = dy < 0 ? 1 : m;
        } else {
            if (dx) pie[i][0] = pie[i - 1][0] - dx;
            else pie[i][1] = pie[i - 1][1] - dy;
        }
    }
}
void apply(char i) {
    if (i == 'G') move(-1, 0);
    else if (i == 'D') move(1, 0);
    else if (i == 'L') move(0, -1);
    else move(0, 1);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) {
        char c = cin.get();
        while (c != '.' && c != 'B' && c != 'C') c = cin.get();
        if (c != '.') pie.emplace_back(AI<4>{i, j, c == 'C', 0});
    }


    int k;
    cin >> k;
    string op;
    rep(i, 1, k) {
        char c = cin.get();
        while (c != 'G' && c != 'D' && c != 'L' && c != 'P') c = cin.get();
        if (op.size() > 1 && c == op[op.size() - 2]) continue;
        auto same_tp = [](char a, char b) {
            if (a > b) swap(a, b);
            return a == b || (a == 'L' && b == 'P') || (a == 'D' && b == 'G');
        };
        if (!op.empty() && same_tp(c, op.back())) {
            op.pop_back();
            if (op.size() > 1 && c == op[op.size() - 2]) continue;
        }
        op += c;
    }

    k = op.size();
    if (k < 10) {
        for (char i : op) apply(i);
    } else {
        apply(op[0]), apply(op[1]), apply(op[2]);
        int cnt = 0;
        for (auto &i : pie) i[3] = cnt++;
        vector<AI<4>> tmp(pie);
        apply(op[3]), apply(op[4]), apply(op[5]), apply(op[6]);
        cnt = 0;
        for (auto &i : pie) nxt[i[3]] = cnt++;
        int step = (k - 3) / 4;
        rep(i, 0, cnt - 1) {
            if (vis[i]) continue;
            int t = i, top = 0;
            while (!vis[t]) {
                sta[top++] = t;
                vis[t] = true;
                t = nxt[t];
            }
            rep(j, 0, top - 1) nxt[sta[j]] = sta[(j + step) % top];
        }
        pie = tmp;
        rep(i, 0,  cnt - 1) pie[i][0] = tmp[nxt[i]][0], pie[i][1] = tmp[nxt[i]][1];
        rep(i, step * 4 + 3, k - 1) apply(op[i]);
    }
    for (auto &i : pie) ans[i[0]][i[1]] = i[2] ? 'C' : 'B';
    rep(i, 1, n) {
        rep(j, 1, m) cout << (ans[i][j] ? ans[i][j] : '.');
        cout << '\n';
    }

    return 0;
}
