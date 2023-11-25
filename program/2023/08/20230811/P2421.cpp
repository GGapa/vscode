//https://www.luogu.com.cn/problem/P2421
//P2421 [NOI2002] 荒岛野人
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 20;
int C[maxn], p[maxn], l[maxn];
int n, Max = -1;
int exgcd(int a, int b, int &x, int &y) {
	if(!b) {
        x = 1;
        y = 0;
        return a;
    }
	int tmp = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return tmp;
}
bool check(int m)
{
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int a = p[i] - p[j];
            int b = m;
            int c = C[j] - C[i];
            int x, y;
            int gcd = exgcd(a, b, x, y);
            if (c % gcd != 0)
                continue;
            a /= gcd;
            b /= gcd;
            c /= gcd;
            b = abs(b);
            x = (x * c % b + b) % b;
            if (x <= l[i] && x <= l[j])
                return 0;
        }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> C[i] >> p[i] >> l[i];
        Max = max(C[i], Max);
    }
    for(int i = Max; i <= 1e6; i++) {
        if(check(i)) {
            cout << i;
            return 0;
        }
    }
    return 0;
}