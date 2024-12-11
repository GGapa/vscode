#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BCJ
{
    vector<int> son;

    BCJ(int n)
    {
        son.resize(n);
        for (int i = 0; i < n; ++i)
            son[i] = i;
    }

    int find(int x)
    {
        if (son[x] != x)
            son[x] = find(son[x]);
        return son[x];
    }

    void unite(int x, int y)
    {
        int lx = find(x);
        int ly = find(y);
        if (lx != ly)
            son[lx] = ly;
    }
};

struct Edge
{
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool cmp(Edge &e1, Edge &e2)
{
    return e1.weight > e2.weight;
}


int main()
{
    int n;
    cin >> n;
    vector<Edge> edges;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int gcd_value = __gcd(i, j);
            edges.push_back(Edge(i, j, gcd_value));
        }
    }

    sort(edges.begin(), edges.end(), cmp);
    int ans = 0;
    BCJ uf(n + 1);
    for (const auto &i : edges)
    {
        if (uf.find(i.u) != uf.find(i.v))
        {
            uf.unite(i.u, i.v);
            ans += i.weight;
        }
    }
    cout<<ans<<endl;
    return 0;
}