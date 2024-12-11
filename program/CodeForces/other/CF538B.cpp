#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

int a[20], ans[20];
string n;
int len;


bool check() {
    rep(i, 1, len) if(a[i] != 0) return false;
    return true;
}

int getnum() {
    int sum = 0;
    rep(i, 1, len)  {
        sum *= 10;
        if(a[i] > 0) sum++, a[i]--;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    len = n.size();
    rep(i, 0, n.size()) a[i + 1] = n[i] - '0';
    int it = 0;
    while(!check()) 
        ans[++it] = getnum();
    cout << it << '\n';
    rep(i, 1, it) cout << ans[i] << " \n"[i == it];

    return 0;
}