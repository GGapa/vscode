#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    VI ran(n + 1), st;
    s = " " + s;
    unordered_map<char, char> mp;
    for(char i = 'a', j = 'A'; i <= 'z'; i++, j++) 
        mp[i] = j, mp[j] = i;
    for(int i = 1, cnt = 0; i <= n; i++) {
        auto &c = s[i];
        if(c == '(') {
            st.push_back(i);
            cnt++;
        }
        else if(c == ')') {
            int t = st.back();
            st.pop_back();
            ran[t] = i; ran[i] = t;
            cnt--;
        }
        else if(cnt & 1) c = mp[c];
    }
    function<string(int, int, int)> dfs = [&](int l, int r, int ty) {
        string res;
        if(!ty) {
            while(l <= r) {
                if(s[l] == '(') {
                    res += dfs(l + 1, ran[l] - 1, 1);
                    l = ran[l];
                }
                else res += s[l];
                l++;
            }
        }
        else {
            while(l <= r) {
                if(s[r] == ')') {
                    res += dfs(ran[r] + 1, r - 1, 0);
                    r = ran[r];
                }
                else res += s[r];
                r--;
            }
        }
        return res;
    };
    cout << dfs(1, n, 0)  << '\n';
    return 0;
}