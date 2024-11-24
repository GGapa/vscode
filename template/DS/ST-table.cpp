struct ST {
    int n;
    vector<VI> mn;
    void init(const vector<int>& A) {
        mn[0] = A;
        rep(i, 1, __lg(n)) for(int j = 1; j + (1 << i) - 1 <= n; j++)
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i)]);
    }
 
    ST(int nn) {
        n = nn;
        mn.assign(__lg(n) + 1, VI(n + 1, INT_MAX));
    }
 
    ST(int nn, const vector<int> &A) {
        n = nn;
        mn.assign(__lg(n) + 1, VI(n + 1, INT_MAX));
        init(A);
    }
 
    int query(int l, int r) {
        int d = __lg(r - l + 1);
        return min(mn[d][l], mn[d][r - (1 << d) + 1]);
    }
};