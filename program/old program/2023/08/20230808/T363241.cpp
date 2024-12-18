//T363241 Collatz 猜想
//https://www.luogu.com.cn/problem/T363241?contestId=123906

#include <iostream>
#include <set>
using namespace std;
int n, k, ans;
set<int> used;

void dfs(int x, int step) {
    if(x <=  n)
        used.insert(x);
    if(step < k ) {
        dfs(x * 2, step + 1);
        if ((x - 1) % 3 == 0 && (x - 1) / 3 % 2 == 1)
			dfs((x - 1) / 3, step + 1);
    }
}
int main() {
    cin >> n >> k;
    ans = n;
    dfs(1, 0);
    cout << ans - used.size() << '\n';
    return 0;
}