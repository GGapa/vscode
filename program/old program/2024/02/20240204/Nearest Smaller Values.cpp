//CSES - 1645
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n;
int st[N], a[N], top;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        while(top && a[st[top]] >= a[i]) top--; 
        cout << (top <= 0 ? 0 : st[top]) << ' ';
        st[++top] = i;
    }
    return 0;
}

// 最近最小值，单调栈