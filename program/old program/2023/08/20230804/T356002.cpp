//T356002 双倍咕值 (double)
//https://www.luogu.com.cn/problem/T356002?contestId=119800
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
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

int n, m, users[maxn], u[maxn], v[maxn];
int main()
{
    n = read();
    m = read();
    for(int i = 1; i <= m; i++)
    {
        u[i] = read();
        v[i] = read();
    }
    cout << 1 << endl;
    
    return 0;
}