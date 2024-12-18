//P1056 [NOIP2008 普及组] 排座椅
//https://www.luogu.com.cn/problem/P1056
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000 + 5;
int m, n, k, l, d;
struct AA {
    int it, val = 0;
};
AA H[maxn], Z[maxn]; //横向，纵向
bool cmp(AA x, AA y) {
    return x.val > y.val;
}
int main() {
    cin >> m >> n >> k >> l >> d;
    for(int i = 1; i <= n; i++) {
        H[i].it = i;
    }
    for(int i = 1; i <= m; i++) {
        Z[i].it = i;
    }
    for(int i = 1, x1, y1, x2, y2; i <= d; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            Z[min(y1, y2)].val++;
        }
        if(y1 == y2) {
            H[min(x1, x2)].val++;
        }
    }
    sort(H + 1, H + 1 + n, cmp);
    sort(Z + 1, Z + 1 + n, cmp);
    vector<int> Hl,Zl;
    for(int i = 1; i <= k; i++) {
        Hl.push_back(H[i].it);
    }
    for(int i = 1; i <= l; i++) {
        Zl.push_back(Z[i].it);
    }
    sort(Hl.begin(), Hl.end());
    sort(Zl.begin(), Zl.end());
    for(int i = 0; i < Hl.size(); i++) {
        cout << Hl[i] << " \n"[i == Hl.size() - 1];
    }
    for(int i = 0; i < Zl.size(); i++) {
        cout << Zl[i] << " \n"[i == Zl.size() - 1];
    }
    return 0;
}