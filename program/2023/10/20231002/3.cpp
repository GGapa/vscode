#include <iostream>
#include <vector>
using namespace std;
const int mod = 618;

int n;
int ans = 0;

void dfs(int x, vector<int> a) {
    if(x > 6) return;
    int l = x - 1;
    int r = x + 1;
    if(l < 1) l = n;
    if(r > 6) r = 1;
    if(a[l] % 2 + a[r] % 2 == 1) {
        dfs(x + 1, a);
        return ;
    }

    vector<int> t;
    t = a;
    for(int i = 1; i <= n; i++) {
        if((a[l] + i) % 2 == 0 || (a[r] + i) % 2 == 0 || i == a[x]) continue;
        t[x] = i;
        ans++;
        ans %= mod;
        for(int i = 1; i <= 6; i++) cout << t[i] << "\0\n"[i == 6];
        dfs(x + 1, t);
        t[x] = a[x];
    }
    dfs(x + 1, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> a(6, 1);
    a.insert(a.begin(), 0);
    dfs(1, a);
    cout << ans + 1 << endl;
    return 0;
}