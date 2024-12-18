#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
const int mod = 1000;
#define int long long

int n, t, m;
struct Mat {
    int a[N][N];
    int* operator[](int x){
		return a[x];
	}
    int x, y;
    Mat operator*(const Mat& b) const {
        Mat c;
        c.x = x; c.y = b.y;
        for(int i = 1; i <= m; i++) 
            for(int j = 1; j <= m; j++) {
                c.a[i][j] = 0;
                for(int k = 1; k <= m; k++) 
                    c.a[i][j] = (c.a[i][j] + (a[i][k] * b.a[k][j]) % mod) % mod;
            }
        return c;
    }
}ans, base;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    m = 8;
    cin >> t;
    ans[1][2] = ans[2][3] = ans[3][4] = ans[4][5] = ans[1][6] = ans[6][7] = ans[7][8] = ans[8][5] =
    ans[2][1] = ans[3][2] = ans[4][3]  = ans[6][1] = ans[7][6] = ans[8][7] = 1;
    base = ans;
    t -= 1;
    while(t) {
        if(t & 1) ans = ans * base;
        base = base * base;
        t >>= 1;
    }
    cout << ans.a[1][5] << '\n';
    return 0;
}