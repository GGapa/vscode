//P3197 [HNOI2008] 越狱
//https://www.luogu.com.cn/problem/P3197
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 100003;
ll m;//宗教数
ll n;//房间数（人数）

ll Pow(ll a, ll b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 1)
        return Pow(a, b - 1) * a % mod;
    else
    {
        ll temp = Pow(a, b / 2) % mod;
        return temp * temp % mod;
    }
}


int main() {
    cin >> m >> n;
    cout << (Pow(m, n) - m * Pow(m - 1, n - 1) % mod + mod) % mod;
    return 0;
}