//T338335 『MGOI』Simple Round I | B. 魔法照相馆
//https://www.luogu.com.cn/problem/T338335?contestId=101
#include <iostream>

using namespace std;
int n;
string a;
bool f[3];
int main() {
    cin >> n >> a;
    int ans = 0;
    for(int i = 0; i <= 2; i++) f[i] = true;
    for(int i = 0; i < n; i++) {
        if(a[i] == 'R') {
            ans += f[2];
            ans += f[1];
            ans += !f[0];
            f[2] = 0;
            f[1] = 0;
            f[0] = 1;
        }
        if(a[i] == 'B') {
            ans += f[2];
            ans += !f[1];
            f[2] = 0;
            f[1] = 1;
        }
        if(a[i] == 'W') {
            ans += !f[2];
            f[2] = 1;
        }
    }
    cout << ans << endl;
}