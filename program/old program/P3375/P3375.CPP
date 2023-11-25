#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1005;
string s1, s2;
int Next[maxn];
int main()
{
    cin >> s1 >> s2;
    s1.insert(0, " ");
    s2.insert(0, " ");
    int j = 0;
    int i;
    for (i = 2; i <= s2.length(); i++) // 求前缀函数
    {
        while (j && s2[i] != s2[j + 1])
            j = Next[j];
        if (s2[i] == s2[j + 1])
            j++;
        Next[i] = j;
    }
    i = 1;
    j = 0;
    int q = 1;
    for (int i = 1; i <= s1.length(); i++) // 开始配对（下标从1开始）
    {
        while (j && s2[j + 1] != s1[i])
            j = Next[j];
        if (s2[j + 1] == s1[i])
            j++;
            cout<<i<<" "<<j<<endl;
        if (j == s2.length() - 1)
        {
            cout << i - s2.length() + 2 << endl;
            j = Next[j];
        }
    }
    for (int i = 1; i <= s2.length()-1; i++)
        cout << Next[i] << " ";
    return 0;
}