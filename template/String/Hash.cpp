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

namespace Hash {
    static constexpr int mod1 = 98244853, mod2 = 998442853;

    void init() {
        pw1[0] = pw2[0] = 1;
        rep(i, 1, N - 1) pw1[i] = pw1[i - 1] * B % mod1, pw2[i] = pw2[i - 1] * B % mod2;
    }
    struct Hash {
        LL x, y;
        Hash(LL a = 0) {x = a % mod1, y = a % mod2; }
        Hash(LL a, LL b) : x(a), y(b) {}
        Hash operator+(const Hash &t) { return Hash((x + t.x) % mod1, (y + t.y) % mod2); }
        Hash operator-(const Hash &t) { return Hash((x + mod1 - t.x) % mod1, (y + mod2 - t.y) % mod2); }
        Hash operator*(const int &t) { return Hash(x * pw1[t] % mod1, y * pw2[t] % mod2); }
        bool operator<(const Hash &t) const { return x == t.x ? y < t.y : x < t.x; }
        bool operator==(const Hash &t) {return x == t.x && y == t.y; }
    } H[N];

    map<Hash, AI<2>> mp;
    Hash get(int l, int r) {return H[r] - H[l - 1] * (r - l + 1); }
}using namespace Hash;