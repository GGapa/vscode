struct Dijkstra {
    int n; vector<LL> dis;
    LL& operator[] (const int x) {return dis[x]; }
    Dijkstra() {}
    Dijkstra(int _n) : n(_n), dis(_n + 1, INF) { }
    void init(int nn) {n = nn, dis.assign(n + 1, INF); }
    void work(int st) {
        priority_queue<AI, vector<AI>, greater<AI>> q;
        fill(dis.begin(), dis.end(), INF);
        dis[st] = 0; q.push({0, st});
        while(!q.empty()) {
            int x = q.top()[1], w = q.top()[0]; q.pop();
            if(dis[x] < w) continue;
            for(auto i : G[x]) {
                int to = i[0], w = i[1];
                if(dis[to] > dis[x] + w) {
                    dis[to] = dis[x] + w;
                    q.push({dis[to], to});
                }
            }   
        }
    }
}dj1, dj2;