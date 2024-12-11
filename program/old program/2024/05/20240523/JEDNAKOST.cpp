#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1000 + 5, INF = 1e9, M = 5000 + 5;

string A;
int B, F[N][M], n, pre[N];

int dfs(int x, int v) {
    if(x == n + 1) return v == 0 ? 0 : INF;
    auto &f = F[x][v];
    if(f != -1) return f;
    f = INF;
    int num = 0;
    rep(j, pre[x], n) {
        num = num * 10 + A[j] - '0';
        if(num > v) break;
        f = min(f, dfs(j + 1, v - num) + 1);
    }
    return f;
}

void work(int x, int v) {
    if(x == n + 1) return cout << "=" << B << '\n', void();
    if(x > 1) cout << "+";
    int num = 0;
    rep(j, x, n) {
        cout << A[j];
        num = num * 10 + A[j] - '0';
        if(dfs(x, v) == dfs(j + 1, v - num) + 1) 
            return work(j + 1, v - num);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char c;
    while(isdigit(c = getchar())) A += c;
    while(isdigit(c = getchar()))  B = B * 10 + (c - '0'); 
    n = A.size(); A = " " + A;
    pre[n] = n;
    per(i, n - 1, 1) pre[i] = A[i] == '0' ? pre[i + 1] : i;
    memset(F, -1, sizeof(F));   
    work(1, B);
    return 0;
}
/*
1826553186455=572
18+265+53+186+45+5=572

1345276417972564571153=473
13+45+27+64+17+97+25+64+57+11+53=473

13452547535435745675341135745=3300
134+525+475+35+43+574+567+534+11+357+45=3300

135157452641045281425364472536212313012003=2050
135+157+45+264+104+528+142+53+64+47+253+62+12+31+30+120+03=2050
*/