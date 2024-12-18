#include<bits/stdc++.h>
#define LL long long
#define sl(s) strlen(s)
#define endline puts("")
#define pii pair<int , int>
#define pr_q priority_queue
#define debug puts("DEBUG.")
using namespace std;
const int N = 1e5 + 10;
const int inf = ~0u >> 2;
const int p = 998244353;
int n,m,ct,f[N];
int qpow(int a , int k)
{
    int res = 1;
    while(k)
    {
        if(k & 1)
            res = 1ll * res * a % p;
        a = 1ll * a * a % p,k >>= 1;
    }
    return res;
}
int main()
{
    freopen("c.in" , "r" , stdin);
    freopen("c.out" , "w" , stdout);
    cin >> n >> m >> ct;
    f[0] = 0,f[1] = 1ll * (1 - n + p) * qpow(n , p - 2) % p;
    for(int i = 1;i <= m - 1;i++)
    {
        int p1 = 1ll * i * qpow(m , p - 2) % p;
        int p2 = 1ll * (m - i) * qpow(1ll * (n - 1) * m % p , p - 2) % p;
        f[i + 1] = (1ll * f[i - 1] * p1 % p * (p2 - 1) % p
         + 1ll * f[i] * (2 * p + 1 - 1ll * p1 * p2 % p - 1ll * (p + 1 - p1) * (p + 1 - p2) % p) % p
         + p - qpow(n , p - 2) ) % p;
        f[i + 1] = 1ll * f[i + 1] * qpow(1ll * (p + 1 - p1) * p2 % p , p - 2) % p;
    }
    while(ct--)
    {
        int ans = p - f[m];
        for(int i = 1,x;i <= n;i++)
            scanf("%d" , &x),ans = ( ans + f[x] ) % p;
        printf("%d\n" , ans);
    }
    return 0;
}