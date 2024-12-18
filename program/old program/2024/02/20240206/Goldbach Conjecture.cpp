//Goldbach's Conjecture
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1000000 + 5;

int n;
vector<int> pri;
bool vis[N];

void init() {
    rep(i, 2, N - 5) {
        if(!vis[i]) pri.push_back(i);
        int len = pri.size();
        for(int j = 0, t; j < len && (t = pri[j] * i) < N - 5; j++) {
            vis[t] = true;
            if(i % pri[j] == 0) continue;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    while(1)  {
        cin >> n; if(n == 0) break;
        for(auto p : pri) 
            if(!vis[n - p]) {
                printf("%d = %d + %d\n", n, p, n - p);
                break;
            }
    }
    return 0;
}   