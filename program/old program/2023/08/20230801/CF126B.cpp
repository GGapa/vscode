// Password
// https://www.luogu.com.cn/problem/CF126B
// https://codeforces.com/problemset/problem/126/B
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000000 + 5;

string failed = "Just a legend\n";
string a;
int Next[maxn], n, maxLen;

void GetNext()
{
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && a[i] != a[j + 1])
            j = Next[j];
        if (a[i] == a[j + 1])
            j++;
        Next[i] = j;
        if (i != n)
            maxLen = max(maxLen, Next[i]);
    }
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    n = a.length();
    a.insert(0, " ");
    GetNext();
    int x = Next[n];
    for(int i = 1;i <= n; i++)
    {
        cout << Next[i] << endl;
    }
    if (x == 0)
    {
        cout << failed;
        return 0;
    }
    while (x > maxLen)
    {
        x = Next[x];
        cout << x << endl;
    }
    cout << endl;
    for (int i = 2; i <= n; i++)
    {
        if (x == 0)
        {
            cout << failed;
            return 0;
        }
        if (x == Next[i])
        {
            //cout << x << endl;
            for (int j = i - Next[i] + 1; j <= i; j++)
                cout << a[j];
            return 0;
        }
    }
    return 0;
}