//P8832 [传智杯 #3 初赛] 志愿者
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct people
{
    int number,product,worktime;
}a[500005];
bool cmp(people x,people y)
{
    if (x.product==y.product)
    {

        if(x.worktime==y.worktime)
        {
            return x.number<y.number;
        }
        else
        {
            return x.worktime>y.worktime;
        }
    }
    else 
    {
        return x.product>y.product;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        int tmp2;
        scanf("%d%d",&a[i].worktime,&tmp2);
        a[i].product=a[i].worktime*tmp2;
        a[i].number=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=n ;i++)
    {
        printf("%d ",a[i].number);
    }
    return 0;
}