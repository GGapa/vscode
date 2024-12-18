#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1005;
bool a[maxn];
int  n, m;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int input;
        scanf("%d", &input);
        if (input == n)
        {
            a[input] = 1 - a[input];
            a[input - 1] = 1 - a[input - 1];
            a[1] = 1 - a[1];
        }
        else if (input == 1)
        {
            a[input] = 1 - a[input];
            a[input+1] = 1 - a[input+1];
            a[n] = 1 - a[n];
        }
        else
        {
            a[input] = 1 - a[input];
            a[input + 1] = 1 - a[input + 1];
            a[input - 1] = 1 - a[input - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}