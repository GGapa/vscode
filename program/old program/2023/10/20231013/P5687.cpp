/*
prolbem:P5687 [CSP-S2019 江西] 网格图
URL:https://www.luogu.com.cn/problem/P5687
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 5;
#define int long long

int n, m;
int h, s;  //横竖被使用几次了 
int a[maxn], b[maxn];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	h = m - 1; s = n - 1;  //注意n m 是否混淆
	for(int i = 1; i <= n; i++) cin >> a[i]; //横着的
    for(int i = 1; i <= m; i++) cin >> b[i]; //竖着的
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
	long long ans = 0, need = n * m - 1, sum = n + m - 2;
    ans = 1ll * a[1] * (m - 1) + 1ll * b[1] * (n - 1);
    int ita, itb; 
    ita = itb = 2;
	for(;ita <= n || itb <= m ; ) {
        if(a[ita] < b[itb] && ita <= n) {
            ans += 1ll * h * a[ita++];
            //sum += h;
            s--;
        }
        else if(a[ita] >= b[itb] && itb <= m){
            ans += 1ll * s * b[itb++];
            //sum += s;
            h--;
        }
        else break;
    }
	cout << ans << endl;
	return 0;
}
/*
2023-10-13 23:37:44
编程语言
C++14 (GCC 9)
代码长度
1.00KB
用时
1.14s
内存
5.01MB*/