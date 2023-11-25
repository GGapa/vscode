//Painting the Array I
//https://www.luogu.com.cn/problem/CF1479B1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn], id[maxn], Next[maxn];
vector <pair<int, int> > b, c;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        id[i] = n + 1;
    }
    for(int i = n; i >= 1; i--) {
        Next[i] = id[a[i]];
        id[a[i]] = i;
    }
    int ans = 0;
    b.push_back(pair<int, int>(0, n + 1));
    c.push_back(pair<int, int>(0, n + 1));
    for(int i = 1; i <= n; i++) {
        if(a[i] == c.back().first) {
            if(a[i] != b.back().first) {
                ans++;
            }
            b.push_back(pair<int, int>(a[i], Next[i]));
        }
        else if(a[i] == b.back().first) {
            ans++;
            c.push_back(pair<int, int>(a[i], Next[i]));
        }
        else {
            if(b.back().second < c.back().second) {
                ans++;
                b.push_back(pair<int, int>(a[i], Next[i]));
            }
            else {
                ans++;
                c.push_back(pair<int, int>(a[i], Next[i]));
            }
        }
    }
    cout << ans << endl;
    return 0;
}