/*
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<long long> de[1000005];
vector<long long> bde[1000005];
map <long long, long long> a;
map <long long, long long>b;
struct node_
{
    long long i, j, e;
};
node_ node[1000001];
map<long long, long long>in;
long long find(long long x)
{
    if (in[x] == x)return x;
    return in[x] = find(in[x]);
}
int cmd(node_ x, node_ y)
{
    return x.e > y.e;
}
int main()
{
    long long t, n;
    cin >> t;
    while (t--)
    {
        long long x, y, z;
        bool bj = true;
        cin >> n;
        for (long long i = 0; i <= n; i++)
        {
            a.insert({ i, i });
            b.insert({ i, i });
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> node[i].i >> node[i].j >> node[i].e;
        }
        sort(node, node + n, cmd);
        for (long long i = 0; i < n; i++)
        {
            x = node[i].i; y = node[i].j;
            in[x] = x;
            in[y] = y;
        }
        for (long long i = 0; i < n; i++)
        {
            x = node[i].i; y = node[i].j;
            if (node[i].e == 1)
            {
                int m = find(x), h = find(y);
                if (m < h)in[m] = h;
                if (m > h)in[h] = m;
            }
            else
            {
                //if (in[x] == in[y])
                if (find(x) == find(y))
                {
                    cout << "NO" << endl;
                    bj = false;
                    break;
                }
            }
        }
        if (bj)cout << "YES" << endl;

    }
    return 0;
}
*/