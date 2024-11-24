struct Hash {
    int n; vector<ULL> XP, H;
    void init(string & s, ULL x) {
        n = s.size(); XP.resize(n + 1); H.resize(n + 1);
        XP[0] = 1;
        rep(i, 1, n) XP[i] = x * XP[i - 1] ;
        H[n] = 0;
        for(int i = n - 1; i >= 0; i--) H[i] = s[i] + x * H[i + 1];
    } 
    ULL c_hash(int i, int j) {
        return H[i] - H[j] * XP[j - i];
    }
};
KMP