//T305471 『GROI-R1』 一切都已过去
#include <iostream>
using namespace std;
int a[200001],n,q;
double b[200001],sum=1;


int main()
{
    cin>>n>>q;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        int x,y;
        double z;
        cin>>x>>y>>z;
        b[x]=z;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        sum*=a[l];
        for(int i = l;i<r;i++)
        {
            sum*=b[i];
        }
        if(sum-int(sum)==0)
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}