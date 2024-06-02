// 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    // 1 2 3 4 5
    
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}




/*


问题描述
在AtCoder国家，有N个车站：车站1，车站2，…，车站N。

你得到了有关该国列车的M条信息。第i条信息（1≤i≤M）由六个正整数元组（li,di,ki,ci,Ai,Bi）表示，对应以下信息：

对于每个t=li,li+di,li+2di,…,li+(ki−1)di，都有一列列车，如下：
列车从站点Ai在时间t出发，并在时间t+ci到达站点Bi。
除了这些信息描述的列车外，没有其他列车存在，并且除了乘坐列车外，不可能通过其他方式从一个车站移动到另一个车站。
此外，假设换乘所需时间可以忽略不计。

设f(S)为从站点S到达站点N的最晚时间。
更准确地说，f(S)定义为满足以下所有条件的四个整数元组序列((ti,ci,Ai,Bi)) i=1,2,…,k的最大值：

t≤t1
A1=S,Bk=N
Bi=Ai+1对所有1≤i<k成立
对于所有1≤i≤k，有一列列车从站点Ai在时间ti出发，并在时间ti+ci到达站点Bi。
对于所有1≤i<k，ti+ci≤ti+1成立
如果不存在这样的t，则设置f(S)=−∞。

找到f(1),f(2),…,f(N−1)。

约束
2≤N≤2×10
5
1≤M≤2×10
5
1≤li,di,ki,ci,Ai,Bi≤10
9 （1≤i≤M）
1≤Ai,Bi≤N （1≤i≤M）
Ai≠Bi （1≤i≤M）
所有输入值都是整数。
输入
输入以以下格式从标准输入给出：

N
M
l1 d1 k1 c1 A1 B1
l2 d2 k2 c2 A2 B2
...
lM dM kM cM AM BM

输出
打印N−1行。第k行应包含f(k)如果f(k)≠−∞，否则为Unreachable。
*/