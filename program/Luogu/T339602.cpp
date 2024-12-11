/*
T339602 Colorful Days♪
https://www.luogu.com.cn/problem/T339602?contestId=124047

*/

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;

int n, m, c1, c2, k = 1;
int ans = 0;
int a[maxn];
bool used[maxn];
vector<int> b(1);
vector<int> index[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> c1 >> c2;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        used[a[i]] = true;
        index[a[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 1, tmp; i <= m; i++) {
        cin >> tmp;
        if(used[tmp]) b.push_back(tmp);
        ans += used[tmp];
    }
    int it = 0;
    for(int i = 1; i < b.size(); i++) {
        bool suc = true;
        while(suc){
            suc = true;
            for(int j = 0; j < index[b[i]].size(); j++) {
                if(index[b[i]][j] > it) {
                    it = index[b[i]][j];
                    suc = false;
                    break;
                }
            }
            if(suc) {
                k++;
                it = 0;
            }
        }
    }
    cout << c1 * ans << " " <<c2 * k;
}


/*
15 12 26 21 26 21 23 12 23
26 21 15 15 12 23 12
*/