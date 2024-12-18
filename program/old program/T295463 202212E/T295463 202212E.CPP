// T295463 202212E 旋转排列
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int p[20000];
int main()
{
    int n, back;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]);
        }
    do
    {
        back = p[n];
        for (int i = n; i > 0; i--)
        {
            p[i] = p[i - 1];
        }
        p[1] = back;
        for (int i = 1; i <= n; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }while(p[n]!=n);
}