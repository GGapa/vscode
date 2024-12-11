/*
problem:P7077 [CSP-S2020] 函数调用
link:https://www.luogu.com.cn/problem/P7077
start:2023/09/27 13:08
45pts:2023/09/27 13:38
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 998244353;
typedef long long ll;
#define int unsigned long long

int n, m, q;
int a[maxn];
int ind[maxn];
int F[maxn];
vector<int> G[maxn];
int dag[maxn];
int kkksc03;

struct Fn {
	int op, it;
	ll val, mul, sum;
}fn[maxn];

void toposort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) if(ind[i] ==  0) 
        q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        dag[++kkksc03] = x;
        for(auto to : G[x]) {
            ind[to]--;
            if(ind[to] == 0) q.push(to);
        }
    }
}

void getmul() {
    for(int i = m; i >= 1; i--) {
        int x = dag[i];
        for(auto to : G[x]) {
            fn[x].mul = fn[x].mul * fn[to].mul % mod;
        }
    }
}

void getsum() {
    for(int i = 1; i <= m; i++) {
        ll now = 1;
        int x = dag[i];
        for(auto to : G[x]) {
            fn[to].sum = (fn[to].sum + fn[x].sum * now % mod) % mod;
            now = now * fn[to].mul % mod;
        }
    }
}

signed main() {
    //freopen("test.in", "r", stdin);
	ios::sync_with_stdio(0) ;
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++)	 {
		cin >> fn[i].op;
		if(fn[i].op == 1) {
			cin >> fn[i].it >> fn[i].val;
            fn[i].mul = 1;
		}
		if(fn[i].op == 2) {
			cin >> fn[i].val;
			fn[i].mul = fn[i].val;
		}
		if(fn[i].op == 3) {
			cin >> fn[i].it;
            fn[i].mul = 1;
			for(int j = 1; j <= fn[i].it; j++)  {
				int to;
				cin >> to;
				G[i].insert(G[i].begin(), to);
                //G[i].push_back(to);
                ind[to]++;
			}
		}
	}
    toposort();
    getmul();
    cin >> q;
    ll now = 1;
    for(int i = 1; i <= q; i++) cin >> F[i];
    for(int i = q; i > 0; i--) {
        int x = F[i];
        fn[x].sum = (fn[x].sum + now) % mod;
        now = now * fn[x].mul % mod;
    }
    getsum();
    for(int i = 1; i <= n; i++) a[i] = a[i] * now % mod;
    for(int i = 1; i <= m; i++) if(fn[i].op == 1 ) 
        a[fn[i].it] = (a[fn[i].it] + fn[i].val * fn[i].sum % mod) % mod;
    for(int i = 1; i <= n; i++) 
        cout << a[i] << " \n"[i == n];
	return 0;
}