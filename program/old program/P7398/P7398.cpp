// P7398 [COCI2020-2021#5] Šifra
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
string a, b;
map<string, bool> used;
int main()
{
    cin >> a;
    bool bj = false;
    int ans = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            bj = true;
            b += a[i];
        }
        else if (bj)
        {
            bj = false;
            if (used[b] == 0)
                ans++;
            used[b] = 1;
            b = "";
        }
    }
    if (bj && used[b] == 0)
        ans++;
    printf("%d", ans);
    return 0;
}