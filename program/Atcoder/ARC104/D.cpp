#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mod;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k >> mod;
    return 0;
}
/*
暴力枚举 k 计算 -> TLE，加入一个数 i，对平均数的贡献是 i - ave，但是这样做和直接做没有任何本质区别？
转移可以使用前缀和优化，但是在 0 的时候会出问题，需要单独处理。
考虑不枚举所有的 ave 
*/