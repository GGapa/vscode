#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 2e5 + 5;

int ans[maxn], t[maxn][3], cans;
int n;
stack<int> q[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i][1] >> t[i][2];
        if(t[i][1] == 1) {
            q[t[i][2]].push(i);
        }
        else {
            if(q[t[i][2]].empty()) {
                cout << -1 << endl;
                exit(0);
            }
            ans[q[t[i][2]].top()] = 1;
            q[t[i][2]].pop();
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(t[i][1] == 2) cnt--;
        if(ans[i]) cnt++;
        cans = max(cans, cnt);

    }
    cout << cans << '\n';
    for(int i = 1; i <= n; i++) {
        if(t[i][1] == 2) continue;
        cout << (int) ans[i] << ' ';
    }
    cout << endl;
    return 0;
}