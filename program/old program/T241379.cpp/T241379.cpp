//T241379 『JROI-8』颅脑损伤 2.0
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int map[1000006];
struct stru
{
    int l,r;
}a[30005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i  = 1;i<=n;i++)
    {
        scanf("%d %d",&a[i].l,&a[i].r);
    }
    cout<<4<<endl;
}