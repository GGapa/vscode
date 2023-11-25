#include <iostream>
#include <cstdio>

#define maxn 100005
using namespace std;
#define int long long
#define ll long long
int a[maxn];
int n, m, mod;

struct stru_tree
{
    int left, right;
    long long sum, lazy, mu;
};
stru_tree tree[maxn * 4];

inline void make_tree(int it, int left, int right)
{
    tree[it].left = left;
    tree[it].right = right;
    tree[it].mu = 1;
    if (left == right)
    {
        tree[it].sum = a[left];
        return;
    }
    int middle = (left + right) >> 1;
    make_tree(it * 2, left, middle);
    make_tree(it * 2 + 1, middle + 1, right);
    tree[it].sum = (tree[it * 2].sum + tree[it * 2 + 1].sum) % mod;
}

inline void update(int it)
{

    tree[it * 2].sum = (tree[it * 2].sum * tree[it].mu + ((tree[it * 2].right - tree[it * 2].left + 1) * tree[it].lazy) % mod) % mod;
    tree[it * 2 + 1].sum = (tree[it * 2 + 1].sum * tree[it].mu + ((tree[it * 2 + 1].right - tree[it * 2 + 1].left + 1) * tree[it].lazy) % mod) % mod;
    tree[it * 2].mu = (tree[it * 2].mu * tree[it].mu) % mod;
    tree[it * 2 + 1].mu = (tree[it * 2 + 1].mu * tree[it].mu) % mod;
    tree[it * 2].lazy = (tree[it * 2].lazy * tree[it].mu + tree[it].lazy) % mod;
    tree[it * 2 + 1].lazy = (tree[it * 2 + 1].lazy * tree[it].mu + tree[it].lazy) % mod;

    tree[it].mu = 1;
    tree[it].lazy = 0;
}

inline void Add(int it, int left, int right, long long add)
{
    if (left <= tree[it].left && right >= tree[it].right)
    {
        tree[it].lazy = (tree[it].lazy + add) % mod;
        tree[it].sum = (tree[it].sum + ((tree[it].right - tree[it].left + 1) * add) % mod) % mod;
        return;
    }
    update(it);
    int middle = (tree[it].left + tree[it].right) >> 1;
    if (left <= middle)
        Add(it * 2, left, right, add);
    if (right > middle)
        Add(it * 2 + 1, left, right, add);
    tree[it].sum = (tree[it * 2].sum + tree[it * 2 + 1].sum) % mod;
}

inline void mu(int it, int left, int right, long long add)
{
    if (left <= tree[it].left && right >= tree[it].right)
    {
        tree[it].mu = (tree[it].mu * add) % mod;
        tree[it].lazy = (tree[it].lazy * add) % mod;
        tree[it].sum = (tree[it].sum * add) % mod;
        return;
    }
    update(it);
    int middle = (tree[it].left + tree[it].right) >> 1;
    if (left <= middle)
        mu(it * 2, left, right, add);
    if (right > middle)
        mu(it * 2 + 1, left, right, add);
    tree[it].sum = (tree[it * 2].sum + tree[it * 2 + 1].sum) % mod;
}

inline long long reply(int it, int left, int right)
{
    if (left <= tree[it].left && right >= tree[it].right)
    {
        return tree[it].sum;
    }
    update(it);
    int middle = (tree[it].left + tree[it].right) >> 1;
    long long ans = 0;
    if (left <= middle)
        ans = (ans + reply(it * 2, left, right)) % mod;
    if (right > middle)
        ans = (ans + reply(it * 2 + 1, left, right)) % mod;
    return ans;
}

signed main()
{
    scanf("%lld%lld%lld", &n, &m, &mod);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    make_tree(1, 1, n);
    while (m--)
    {
        int op;
        scanf("%lld", &op);
        if (op == 1)
        {
            int x, y, k;
            scanf("%lld%lld%lld", &x, &y, &k);
            mu(1, x, y, k);
        }
        else if (op == 2)
        {
            int x, y, k;
            scanf("%lld%lld%lld", &x, &y, &k);
            Add(1, x, y, k);
        }
        else
        {
            int x, y;
            scanf("%lld%lld", &x, &y);
            printf("%u\n", reply(1, x, y));
        }
    }
    return 0;
}