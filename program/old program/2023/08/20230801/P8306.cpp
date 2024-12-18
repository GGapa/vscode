//P8306 【模板】字典
//https://www.luogu.com.cn/problem/P8306
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 3e6 + 5;
int tire[maxn][65], cnt[maxn];
int idx = 0;
int T, n, q;

int GetNumber(char x)
{
    if ('A' <= x && x <= 'Z')
        return x - 'A';
    if ('a' <= x && x <= 'z')
        return x - 'a' + 26;
    if ('0' <= x && x <= '9')
        return x - '0' + 52;
}

void insert(string x)
{
    int p = 0, len = x.length();
    for (int i = 0; i < len; i++)
    {
        int c = GetNumber(x[i]);
        if (!tire[p][c])
            tire[p][c] = ++idx;
        p = tire[p][c];
        cnt[p]++;
    }
}

int find(string x)
{
    int p = 0, len = x.length();
    for (int i = 0; i < len; i++)
    {
        int c = GetNumber(x[i]);
        if (!tire[p][c])
            return 0;
        p = tire[p][c];
    }
    return cnt[p];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        for(int i = 0; i < idx; i++)
            for(int j = 0; j < 65; j++)
                tire[i][j] = 0;
        for(int i = 0; i < idx; i++)cnt[i] = 0;
        idx = 0;
        while (n--)
        {
            string tmp;
            cin >> tmp;
            insert(tmp);
        }
        while (q--)
        {
            string tmp;
            cin >> tmp;
            cout << find(tmp) << endl;
        }
    }
    return 0;
}