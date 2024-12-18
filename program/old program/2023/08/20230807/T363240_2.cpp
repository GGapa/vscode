//T363240 洗牌
//T363240 洗牌https://www.luogu.com.cn/problem/T363240?contestId=123906
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    vector<int> vec;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        int posx, posy;
        for(int i = 0; i < n; i++) {
            if(vec[i] == x) posx = i;
            if(vec[i] == y) {
                posy = i;
                break;
            }
        }
        queue <int> Tmp;
        for(auto i = vec.begin() + posx; i != vec.begin() + posy + 1; i++) {
            Tmp.push(*i);
        }
        vec.erase(vec.begin() + posx, vec.begin() + posy + 1);
        while(!Tmp.empty()) {
            vec.push_back(Tmp.front());
            Tmp.pop();
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        cout << vec[i] << " ";
    }
}