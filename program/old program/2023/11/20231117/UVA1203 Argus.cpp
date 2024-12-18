/**
 * @Problem      : UVA1203 Argus
 * @URL          : https://www.luogu.com.cn/remoteJudgeRedirect/uva/1203
 * @Author       : GGapa
 * @Date         : 2023-11-17 11:55:18
 * @LastEditTime : 2023-11-17 12:56:16
**/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int num, per, sum;
    bool operator<( const Node &c) const {
        return sum > c.sum || (sum == c.sum && num > c.num); 
    }
};

priority_queue<Node> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    while(1) {
        string op;
        int num, per;
        cin >> op;
        if(op == "#") break;
        cin >> num >> per;
        q.push((Node){num, per, per});
    }
    int k;
    cin >> k;
    while(k--) {
        Node x = q.top(); q.pop();
        cout << x.num << "\n";
        x.sum += x.per;
        q.push(x);
    }
    return 0;
}
// AC 100pts