//P4231 三步必杀
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
#define maxn 10000005
ll n,m;
ll l,r,s,e;
ll map[maxn];
ll tmp=0,Maxans=-1,ans=0;
inline ll read()
{
    int f=1;
    char c;
    long long num=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        num=(num<<1)+(num<<3)+(c^48);
        c=getchar();
    }
    return num;
}
int main()
{
    n=read();
    m=read();
    for(int i = 1;i<=m;i++)  
    {
        l=read();r=read();s=read();e=read();//开始 结束 初值 终值
        int k=(e-s) / (r-l);
        map[l]+=s;
        map[l+1]+=(k-s);
        map[r+1]+=(-e-k);
        map[r+2]+=e;
    }
    //for(int i = 1;i<=n;i++)map[i]+=map[i-1];
    for(int i = 1;i<=n;i++)
    {
        map[i]+=map[i-1];
        tmp+=map[i];
        //debug(tmp);
        ans^=tmp;
        Maxans=Maxans<tmp?tmp:Maxans;
        //max(Maxans,tmp);
    }
    cout<<ans<<" "<<Maxans<<endl;
    return 0;
}