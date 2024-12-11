// P2085 最小函数值
// https://www.luogu.com.cn/problem/P2085
#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a, b, c, sz[11000];
priority_queue<long long> dui;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        for (int j = 1; j <= 1000; j++) {
            dui.push(a * j * j + b * j + c);
            if (dui.size() > m)
                dui.pop();
        }
    }
    for (int i = m; i >= 1; i--)
        sz[i] = dui.top(), dui.pop();
    for (int i = 1; i <= m; i++)
        cout << sz[i] << " ";
    return 0;
}