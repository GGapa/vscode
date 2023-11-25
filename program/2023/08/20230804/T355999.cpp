//T355999 大粉兔病毒 (virus)
//https://www.luogu.com.cn/problem/T355999?contestId=119800
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
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

struct Sickque
{
    int date, number;
};

vector<int> Friends[maxn];
int n, m, s;
queue<Sickque> sick;
int LastSick[maxn];
int Sicksum[maxn];
int main()
{
    //freopen("virus.in", "r", stdin);
    n = read();
    m = read();
    for(int i = 1, x, y; i <= m; i++)
    {
        x = read();
        y = read();
        Friends[x].push_back(y);
        Friends[y].push_back(x);
    }
    s = read();
    sick.push((Sickque){1, s});
    LastSick[s] = 1;
    Sicksum[s] ++;
    int ans = 0;
    while(!sick.empty())
    {
        Sickque x = sick.front();
        sick.pop();
        ans = max(ans, x.date);
        if(Sicksum[x.number] >= 5)
        {
            cout << -1 << endl;
            exit(0);
        }
        for(auto to : Friends[x.number])
        {
            if(x.date-LastSick[to] > 1 || LastSick[to] == 0)
            {
                LastSick[to] = x.date + 1;
                Sicksum[to] ++;
                sick.push((Sickque){x.date + 1, to});
            }
        }
    }
    cout << ans << endl;
    return 0;
}