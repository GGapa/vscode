namespace LS {
    constexpr int N = 1e6 + 5;
    int pri[N], phi[N], mn[N], mu[N];
    bitset<N> vis;

    void init(){
        mu[1] = 1;
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i, mn[i] = i, phi[i] = i - 1, mu[i] = -1;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                mn[tt] = pri[j];
                if(i % pri[j] == 0) {
                    phi[tt]  = phi[i] * pri[j];
                    break;
                }
                else phi[tt] = phi[i] * phi[pri[j]];
                mu[tt] = -mu[i];
            }
        }
    }

    vector<pair<int, int>> getpri(int x) {
        vector<pair<int, int>> ret;
        while(x > 1) {
            int t = mn[x], cnt = 0;
            while(x % t == 0) x /= t, cnt++;
            ret.emplace_back(t, cnt);
        }
        return ret;
    } 
}using LS::getpri;