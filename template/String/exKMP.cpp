signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<int> z(n + 1);
    for(int i = 2, l = 0, r = 0; i <= n; i++) {
        int &j = z[i] = i > r ? 0 : min(r - i + 1, z[i - l + 1]);
        while(s[1 + j] == s[i + j]) j++;
        if(i + j - 1 > r) r = i + j - 1, l = i;
    }
    rep(i, 1, n) cout << z[i] << " \n"[i == n];

    return 0;
}