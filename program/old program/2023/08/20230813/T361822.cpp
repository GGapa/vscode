// https://www.luogu.com.cn/problem/T361822?contestId=122758
// T361822 广度优先遍历
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int maxn = 100005;
#define int long long
namespace STD
{
    vector<int> G[maxn];
    queue<int> q;
    int pa[maxn];
    int shunxu[maxn];
    int Main()
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(pa, -1, sizeof pa);
        q.push(1);
        pa[1] = 0;
        // shunxu[1] = 1;
        int it = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            shunxu[u] = it++;
            for (auto v : G[u])
            {
                if (pa[v] != -1)
                    continue;
                pa[v] = u;
                q.push(v);
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            cout << pa[i];
            if (i != n)
                cout << " ";
        }
        cout << endl;
        return 0;
    }

}

int n, m;
vector<int> Gstd[maxn];
int so[maxn];
int fa[maxn];
map<int, map<int, bool> > isout;

namespace P20
{
    void Main()
    {
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;
            cout << u << " " << v << endl;
        }
    }
}

struct Node 
{
    int index, val;
};
bool cmp (Node x, Node y)
{
    return x.val < y.val;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //STD::Main();
    cin >> n >> m;

    if (m == n - 1 || m <= 10)
    {
        P20::Main();
        return 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        Gstd[u].push_back(v);
        Gstd[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> fa[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto to : Gstd[i])
        {
            if (fa[to] != i)
            {
                so[i]++;
                so[fa[to]]--;
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++) {
        cout << so[i] << " ";
    }
    */
    for (int i = 1; i <= n; i++)
    {
        vector<Node> tmp;
        for (auto to : Gstd[i]) 
        {
            if(!isout[min(i, to)][max(i, to)])
            {
                tmp.push_back((Node){to, so[to]});
                isout[min(i, to)][max(i, to)] = 1;
            }
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for (auto to : tmp)  
        {
            cout << i << " " << to.index << endl;
        }
    }
    return 0;
}