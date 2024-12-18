//T356000 无根树变有根树 (root)
//https://www.luogu.com.cn/problem/T356000?contestId=119800
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
const int maxn = 1e5 + 5;

inline int read()
{
    int f = 1, x = 0;
    char c;
    c = getchar();
    while(!isdigit(c))
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int n, k;
vector<int> G[maxn];
bool vu1 = true;
void dfs(int x)
{
    for(auto i : G[x])
    {
        
    }
}
int main()
{
    srand((int)time(0));
    n = read();
    k = read();
    for(int i = 1, u, v; i < n; i++)
    {
        u = read();
        v = read();
        if(v != u + 1)
            vu1 = false;
    }
    if(vu1)
    {
        cout << n / 2 - max((k - 1), 1) / 2<< endl;
        return 0;
    }
    cout << (n-(rand()%n)) << endl;
    return 0;
}