//P7190 [COCI2007-2008#6] SEMAFORI
#include <iostream>
using namespace std;

int main()
{
    int n,l,d,r,g,time=0,where=0,moret,wait;
    cin>>n>>l;
    for(int i = 1;i<=n;i++)
    {
        cin>>d>>r>>g;
        time+=d-where;
        where=d;
        moret=time%(r+g);
        if(moret<r)wait=r-moret;
        else wait=0;
        time +=wait;
        if(where>=l||i==n)cout<<time+(l-where)<<endl;
    }
    return 0;
}