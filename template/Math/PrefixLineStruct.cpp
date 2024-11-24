struct Line {
    vector<int> a, pos;
    int n;
    Line(int _n) : n(_n), a(_n + 1), pos(_n + 1) {}
    void insert(int x, int it) {
        per(i, n, 0)
         if(x >> i & 1) {
            if(!a[i] ) return a[i] = x, pos[i] = it, void();
            else if(pos[i] < it) swap(pos[i], it), swap(a[i], x) ;
            x ^= a[i];
        }
    }
    int query(int it) {
        int ret = 0;
        per(i, n, 0) if(!(ret >> i & 1) && pos[i] >= it) 
            ret ^= a[i];
        return ret;
    }
};