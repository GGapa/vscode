//T351675 「RiOI-2」weight
//https://www.luogu.com.cn/problem/T351675?contestId=122184

// TLE 50 pts
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, long long> M;
int n, q, Max = -1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1, x; j <= n; j++) {
            cin >> x;
            M[x]++;
            Max = max(Max, x);
        }
    int last = 0;
    for(auto i = M.end(); i != M.begin(); i--)
    {
        if(i == M.end()) continue;
        i->second += last;
        last = i->second;
    }
    M.begin()->second += last;
    while(q--) {
        int x;
        cin >> x;
        auto tmp = M.lower_bound(x);
        cout << (x > (long long)Max ? 0 : min(tmp->second, (long long)n)) << endl;
    }
    return 0;
}