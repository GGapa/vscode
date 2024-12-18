#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

unordered_map<char, char> mp;

string work(int l, int r, string s) {
    if(l == r) return string(1, s[l]);
    int ol = l;
    int rr = r;
    if(l < r) {
        while(s[r] != ')' && r > l) r--;
        while(s[l] != '(' && l < r) l++;
        string t;
        if(l == r) t += s[l];
        else t = work(r - 1, l + 1, s);
        return s.substr(ol, l - ol) + t + s.substr(r + 1, rr - r);
    }
    if(l > r) {
        swap(l, r); swap(ol, rr);
        while(s[r] != ')' && r > l) r--;
        while(s[l] != '(' && l < r) l++;
        string t;
        if(l == r) t += s[l];
        else t = work(r - 1, l + 1, s);
        return s.substr(r + 1, rr - r) + t + s.substr(ol, l - ol);
    }
    return "";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;  cin >> s;
    int n = s.size();
    for(char i = 'a', j = 'A'; i <= 'z'; i++, j++) mp[i] = j, mp[j] = i;
    for(int cnt = 0, i = 0 ; i< n; i++) {
        cnt += (s[i] == '(') - (s[i] == ')');
        if(cnt & 1 && s[i] != '(' && s[i] != ')') s[i] = mp[s[i]];
    }
    cout << work(0, n - 1, s) << endl;
    return 0;
}
