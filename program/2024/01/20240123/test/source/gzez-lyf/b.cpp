#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <queue>
typedef long long LL;
using namespace std;
inline int read() {
    int num = 0 ,f = 1; char c = getchar();
    while (!isdigit(c)) f = c == '-' ? -1 : f ,c = getchar();
    while (isdigit(c)) num = (num << 1) + (num << 3) + (c ^ 48) ,c = getchar();
    return num * f;
}
inline void open_file() {
	freopen("b.in" ,"r" ,stdin);
	freopen("b.out" ,"w" ,stdout);
}
const int N = 1005 ,mod = 1e9 + 7 ,SS = 9;
inline int add(int a ,int b) {return a + b >= mod ? a + b - mod : a + b;}
inline int dec(int a ,int b) {return a - b < 0 ? a - b + mod : a - b;}
inline int mul(int a ,int b) {return 1ll * a * b % mod;}
inline void mul(int a[N] ,int b[N] ,int c[N] ,int n) {
    for (int i = 0; i <= n; i++) c[i] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n - i; j++)
            c[i + j] = add(c[i + j] ,mul(a[i] ,b[j]));
}
vector <int> G1[N] ,G2[N];
int dl1[N] ,dl2[N] ,to1[N] ,to2[N];
int S[N] ,top;
int h[11][N];
int tmp[2][N];
inline int query(int i ,int j) {
    for (int k = 0; k <= j; k++) tmp[0][k] = tmp[1][k] = 0;
    tmp[0][0] = 1;
    int u = 0;
    for (int k = 0; k <= SS; k++)
        if (i >> k & 1)
            mul(tmp[u] ,h[k] ,tmp[u ^ 1] ,j) ,u ^= 1;
    return tmp[u][j];
}
inline int fuling_dp(int x ,int y ,bool type) {
    if (!x && !y) return 1;
    if (!x || !y) return 0;
    if (type) {
        if (G1[x].size() != G2[y].size()) return 0;
        if (!G1[x].size() && !G2[y].size()) return 1;
        int res = 1;
        for (int i = 0; i < (int)G1[x].size(); i++) {
            int v1 = G1[x][i] ,v2 = G2[y][i];
            res = mul(res ,fuling_dp(v1 ,v2 ,0));
            if (!res) break;
        }
        return res;
    }
    return mul(query(dl1[x] ,dl2[y]) ,fuling_dp(to1[x] ,to2[y] ,1));
}
signed main() {
	open_file();
    int n1 = read() ,n2 = read();
    for (int i = 2; i <= n1; i++) {
        int fa = read();
        G1[fa].emplace_back(i);
    }
    for (int i = 2; i <= n2; i++) {
        int fa = read();
        G2[fa].emplace_back(i);
    }
    for (int i = n1; i >= 1; i--) {
        if (G1[i].size() == 1u) {
            int v = G1[i][0];
            dl1[i] = dl1[v] + 1;
            to1[i] = to1[v];
        }
        else to1[i] = i ,dl1[i] = 1;
    }
    for (int i = n2; i >= 1; i--) {
        if (G2[i].size() == 1u) {
            int v = G2[i][0];
            dl2[i] = dl2[v] + 1;
            to2[i] = to2[v];
        }
        else to2[i] = i ,dl2[i] = 1;
    }
    int n = max(n1 ,n2);
    int q = read();
    while (q--) {
        int opt = read() ,x = read();
        if (opt == 1) S[++top] = x;
        else {
            for (int i = 1; i <= top; i++) if (S[i] == x) {swap(S[i] ,S[top]); top--; break;}
        }
        for (int i = 0; i <= n; i++) h[0][i] = 0;
        for (int i = 1; i <= top; i++) h[0][S[i]] = 1;
        for (int i = 1; i <= SS; i++)
            mul(h[i - 1] ,h[i - 1] ,h[i] ,n);
        printf("%d\n" ,fuling_dp(1 ,1 ,0));
    }
    return 0;
}
