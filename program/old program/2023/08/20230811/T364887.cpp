//.T364887 小粉兔还会忘记考试吗
//https://www.luogu.com.cn/problem/T364887?contestId=121028
#include <iostream>
#include <map>
using namespace std;

int n, m;
map <int, int> score;

int main() {
    cin >> n >> m;
    int vacant = 0;
    for(int i = 1, kkksc03; i <= n; i++){
        cin >> kkksc03;
        score[kkksc03] = -1;
    }
    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        score[x] = y;
    }
    int ans = 0;
    for(auto i = score.begin(); i != score.end(); i++) {
        if(i->second < 60) ans++;
        if(i->second == -1) vacant ++;
    }
    cout << vacant << "\n" << ans << "\n";
    return 0;
}