struct Trie {
    static constexpr int N = 1e5 + 5;
    int tr[N][4], in[N], out[N], dfn[N], ctt[N];
    int idx = 0, cnt = 0;
    void insert(const string &s) {
        int it = 0;
        for(auto cc : s) {
            int c = exc.find(cc);
            if(!tr[it][c]) tr[it][c] = ++idx;
            it = tr[it][c];
        }
        ctt[it]++;
    }
    pair<int, int> query(const string &s) {
        int it = 0;
        for(auto cc : s) {
            int c = exc.find(cc);
            if(!tr[it][c]) return {-1, -1};
            it = tr[it][c];
        }
        return {in[it] + 1, out[it]};
    }
    void dfs(int x) {
        in[x] = cnt;
        cnt += ctt[x];
        rep(i, 0, 3) if(tr[x][i]) dfs(tr[x][i]);
        out[x] = cnt;
    }
};
