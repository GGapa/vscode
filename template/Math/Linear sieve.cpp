vector<int> p;
int vis[N], mn[N];

for(int i = 2; i < N; i++) {
    if(!vis[i]) p.emplace_back(i), mn[i] = i;
    for(auto pr : p) {
        if(i * pr >= N) break;
        vis[i * pr] = 1;
        mn[i * pr] = pr;
        if(i % pr == 0) break;
    }
}