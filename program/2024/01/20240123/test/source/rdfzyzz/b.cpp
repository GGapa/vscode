#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
// #define int long long
#define fi first
#define se second

const int inf = 1e9;
const int N = 805;
const int mod = 1e9+7;

int n[2],q;

vector<int> v[2][N];

int dw[2][N], sz[2][N];

void dfs(int x, int id, int up, int tsz){
    dw[id][up] = x; sz[id][up] = tsz;
    for (int i = 0; i < v[id][x].size(); i++){
        int y = v[id][x][i];
        if (v[id][x].size() == 1) dfs(y,id,up,tsz+1);
        else dfs(y, id, y, 1);
    }
}
void NO(){
    for (int i = 1; i <= q; i++) cout << 0 << "\n";
    exit(0);
}

vector<pii> Q;
void dfs2(int x, int y){
    if (v[0][x].size() != v[1][y].size()) NO();
    for (int i = 0; i < v[0][x].size(); i++){
        Q.push_back({sz[0][v[0][x][i]],sz[1][v[1][y][i]]});
        dfs2(dw[0][v[0][x][i]], dw[1][v[1][y][i]]);
    }
}

int f[N][N];
signed main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> n[0] >> n[1];
    for (int id = 0; id <= 1; id++){
        for (int i = 2; i <= n[id]; i++){
            int x;
            cin >> x;
            v[id][x].push_back(i);
        }
        for (int i = 1; i <= n[id]; i++){
            sort(v[id][i].begin(), v[id][i].end());
        }
    }

    for (int id = 0; id <= 1; id++) dfs(1,id,1,1);
    cin >> q;
    Q.push_back({sz[0][1], sz[1][1]});
    dfs2(dw[0][1],dw[1][1]);

    int mx = 0, mx2 = 0;
    for (auto t:Q){
        mx = max(mx, t.fi);
        mx2 = max(mx2, t.se);
    } 

    vector<int> now;
    for (int i = 1; i <= q; i++){
        int op,x;
        cin >> op >> x;
        if (op == 1) now.push_back(x);
        else{
            for (int j = 0; j < now.size(); j++){
                if (now[j] == x){
                    now.erase(now.begin()+j);
                    break;
                } 
            }
        }

        memset(f,0,sizeof f);
        f[0][0] = 1;
        for (int j = 1; j <= mx; j++){
            for (int y:now){
                for (int k = mx2; k >= y+j-1; k--){
                    f[j][k] += f[j-1][k-y];
                    if (f[j][k] > mod) f[j][k] -= mod;
                }
            }
        }

        ll ans = 1;
        for (auto t:Q){
            ans *= f[t.fi][t.se];
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}