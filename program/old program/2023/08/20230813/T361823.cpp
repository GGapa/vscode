//T361823 连通图计数
//https://www.luogu.com.cn/problem/T361823?contestId=122758
#include <iostream>
using namespace std;
const int mod = 998244353;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    long long ans = 3;
    for(int i = 5; i <= n; i++) {
        ans += (i - 2);
    }
    cout << ans << endl;
}