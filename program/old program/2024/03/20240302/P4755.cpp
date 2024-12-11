#include <bits/stdc++.h>
#include<bits/extc++.h>
// #define int long long
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn], n;
ll ans;
int l[maxn], r[maxn];


char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

inline int build()
{
    int st[maxn], tp = 0, k = 0;
    for (int i = 1; i <= n; i++)
    {
        k = tp;
        while (k > 0 && a[st[k]] < a[i])
            k--;
        if (k)
            r[st[k]] = i;
        if (k < tp)
            l[i] = st[k + 1];
        st[++k] = i;
        tp = k;
    }
    return st[1];
}

unordered_map<int, vector<int>> v;
vector<int> ret;

inline vector<int> st(vector<int> &a, vector<int> &b)
{
    int x = a.size();
    int y = b.size();
    ret.resize(x + y);
    // fill(ret.begin(), ret.end(), 0);
    int i = 0, j = 0, k = 0;
    while (i < x && j < y)
    {
        if (a[i] > b[j])
            ret[k++] = b[j++];
        else
            ret[k++] = a[i++];
    }
    while (i < x)
        ret[k++] = a[i++];
    while (j < y)
        ret[k++] = b[j++];
    return ret;
}


inline void dfs(int u)
{
    if (u == 0)
        return;
    dfs(l[u]);
    dfs(r[u]);
    auto v1 = &v[l[u]];
    auto v2 = &v[r[u]];
    // v[r[u]].shr
    // vector<int>().swap(v[l[u]]);
    // v.erase(r[u]); 
    // v.erase(l[u]);
    // v[l[u]].clear();
    // v[r[u]].clear();
    // if (v1.size() > v2.size())
    //     swap(v1, v2);
    v1->push_back(a[u]);
    v[u] = st(*v1, *v2);
    v2->push_back(a[u]);
    for (int ai : *v1)
    {
        int k = a[u] / ai;
        int c = upper_bound(v2->begin(), v2->end(), k) - v2->begin();
        ans += c;
    }
    vector<int>().swap(v[r[u]]);
    vector<int>().swap(v[l[u]]);
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    dfs(build());
    cout << ans;
    return 0;
}