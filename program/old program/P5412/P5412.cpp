//P5412 [YNOI2019] 排队
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
void so(double *a,int len)
{
    bool p=1;
    do
    {
        p=0;
        for(int i = 1;i<len;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                p=1;
            }
        }
    } while (p==1);
    
}
int main()
{
    bool xin[10005];
    double women[10005],men[10005];
    int t;
    cin>>t;
    while(t--)
    {
        memset(xin,false,sizeof(0));
        memset(women,0,sizeof(women));
        memset(men,0,sizeof(men));
        int n;
        cin>>n;
        for(int i = 1;i<=n;i++)
        {
            cin>>xin[i];
        }
        int menit,womenit;
        menit=womenit=1;
        for(int i = 1;i<=n;i++)
        {
            double tmp;
            cin>>tmp;
            if(xin[i])
            {
                men[menit++]=tmp;
            }
            else
            {
                women[womenit++]=tmp;
            }
        }
        sort(women+1,women+womenit);
        //so(women,womenit-1); 无论是冒泡还是STL都能过
        //so(men,menit-1);
        sort(men+1,men+menit);
        for(int i=1;i<womenit;i++)
		{
			cout<<women[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<menit;i++)
		{
			cout<<men[i]<<" ";
		}
		cout<<endl;
    }
    return 0;
}