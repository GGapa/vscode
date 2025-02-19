#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 4e6 + 5, B = 233;

int n, k;
LL L, R, pw1[N], pw2[N];
string s; 

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
void update(const Hash &t, int x) {mp[t][0]++, mp[t][1] = x; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> L >> R;
    cin >> s; s = " " + s;
    init();
    
    rep(i, 1, n) {
        H[i] = H[i - 1] * 1 + Hash(s[i] - 'a');
        if(i > k) update(get(i - k, i), i);
    }

    int len ; len = -1;
    rep(i, n + 1, R) {
        int cnt, mx; cnt = mx = 0;
        rep(c, 0, 25) if(mp.count(get(i - k, i - 1) * 1 + Hash(c))) {
            int w = mp[get(i - k, i - 1) * 1 + Hash(c)][0];
            if(w > cnt) cnt = w, mx = c;
        }
        H[i] = H[i - 1] * 1 + Hash(mx), s += mx + 'a';
        int j = mp[get(i - k, i)][1];
        if(j > n) {
            len = i - j;
            break;
        }
    }
    int t = (int)s.size() - 1;
    rep(i, L, R) cout << (i <= t ? s[i] : s[(i - t - 1) % len + t - len + 1]);

    return 0;
}
/*
显然找一个串的位置显然不仅仅是 KMP，也可以使用 Hash。
*/