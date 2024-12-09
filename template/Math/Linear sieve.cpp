namespace LS {
    constexpr int N = 1e6 + 5;
    int pri[N], phi[N], mi[N], mu[N];
    bitset<N> vis;

    void init(){
        mu[1] = 1;
        rep(i, 2, N - 1) {
            if(!vis[i]) pri[++pri[0]] = i, mi[i] = i, phi[i] = i - 1, mu[i] = -1;
            for(int j = 1; j <= pri[0] && i * pri[j] < N; j++) {
                int tt = i * pri[j];
                vis[tt] = 1;
                mi[tt] = pri[j];
                if(i % pri[j] == 0) {
                    phi[tt]  = phi[i] * pri[j];
                    break;
                }
                else phi[tt] = phi[i] * phi[pri[j]];
                mu[tt] = -mu[i];
            }
        }
    }
}