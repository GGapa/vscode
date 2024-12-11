#include<bits/stdc++.h>
using namespace std;
struct IO{
    int rd()
    {
        int x=0,w=1;
        char c=getchar();
        while(c<'0'||c>'9')
        {
            if(c=='-') w=-1;
            c=getchar();
        }
        while(c>='0'&&c<='9')
        {
            x=(x<<3)+(x<<1)+c-'0';
            c=getchar();
        }
        return x*w;
    }
    void write(int x)
    {
        if(x<0) putchar('-'),x=-x;
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
    void wt(int x,char c){write(x);putchar(c);}
}io;
int n,m,q;
struct edge{
    vector<int>e[64010];
    int son[64010];
    int dep[64010];
}t1,t2;
const long long mod=1e9+7;
int f[2001][2001];
map<pair<int,int>,int>mp;
int dfncnt;
int sum[100100],len;
int jc[100100],jc_inv[200100];
int dp(int x,int y,int xlen,int ylen,int op,int val)
{
    if(!mp[make_pair(x,y)])
    {
//         cout<<x<<" "<<y<<" "<<xlen<<" "<<ylen<<endl;
        mp[make_pair(x,y)]=++dfncnt;
        sum[dfncnt]=sum[dfncnt-1]+xlen+1;
        f[sum[dfncnt-1]+1][0]=1;
    }
    int cl=mp[make_pair(x,y)];
    if(op==1)
    {
       for(int i=xlen;i>=1;i--)
		{
			for(int p=1;p<=i;p++)
			{
				for(int k=ylen;k>=val*p;k--)
				{
					f[sum[cl-1]+i+1][k]=(f[sum[cl-1]+i+1][k]+1ll*f[sum[cl-1]+i+1-p][k-val*p]*jc_inv[p]%mod)%mod;
				}
			}
		}
    }
    else 
    {
        for(int i=1;i<=xlen;i++)
		{
			for(int p=1;p<=i;p++)
			{
				for(int k=val*p;k<=ylen;k++)
				{
					f[sum[cl-1]+i+1][k]=((f[sum[cl-1]+i+1][k]-1ll*f[sum[cl-1]+i+1-p][k-val*p]*jc_inv[p]%mod)%mod+mod)%mod;
				}
			}
		}
    }
    // cout<<f[cl][xlen][ylen]<<" "<<xlen<<" "<<ylen<<" "<<op<<" "<<val<<endl;
    return 1ll*f[sum[cl-1]+xlen+1][ylen]*jc[xlen]%mod;
}
int match(int x,int y,int op,int val)
{
    int tox=x,depx=1;
    while(t1.son[tox]==1)
    {
        depx++;
        tox=t1.e[tox][0];
    }
    int toy=y,depy=1;
    while(t2.son[toy]==1)
    {
        depy++;
        toy=t2.e[toy][0];
    }
    // cout<<tox<<" "<<toy<<endl;
    if(t1.son[tox]!=t2.son[toy])
    {
        return 0;
    }
    else 
    {
        // cout<<"!"<<t1.son[x]<<" "<<t1.son[y]<<endl;
        int ans=dp(x,y,depx,depy,op,val);
        for(int i=0;i<t1.son[tox];i++)
        {
            ans=(1ll*ans*match(t1.e[tox][i],t2.e[toy][i],op,val)%mod);
        }
        return ans;
    }
}
map<int,int>clr;
struct tree{
    int l,r;
    vector<int>vc;
}t[64010];
void build(int p,int L,int R)
{
    t[p].l=L;t[p].r=R;
    if(L==R) return ;
    int mid=(L+R)>>1;
    build(p*2,L,mid);build(p*2+1,mid+1,R);
}
void change(int p,int L,int R,int x)
{
    if(L<=t[p].l&&t[p].r<=R)
    {
        t[p].vc.push_back(x);
        return ;
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(L<=mid) change(p*2,L,R,x);
    if(mid+1<=R) change(p*2+1,L,R,x);
}
int ans;
int Ans[200100];
int sta[640010],top;
void get_ans(int p)
{
//	cout<<p<<" "<<t[p].l<<" "<<t[p].r<<endl;
    int stk=top+1,lak;
    for(auto x:t[p].vc)
    {
//    	S[x]=1; 
        ans=match(1,1,1,x); 
        sta[++top]=x;
//        cout<<"+"<<x<<endl;
    }
    lak=top;
    if(t[p].l==t[p].r)
    {
        Ans[t[p].l]=ans;
    }
    if(t[p].l!=t[p].r)
    {
        get_ans(p*2);
        get_ans(p*2+1);
    }
    for(int i=lak;i>=stk;i--)
    {
//    	S[sta[top]]=0;
//    	 cout<<"-"<<sta[top]<<endl;
        ans=match(1,1,2,sta[top]);
        top--;
    }
}
//void dp(int cl,)
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    n=io.rd();m=io.rd();
    jc[0]=1;
    for(int i=1;i<=2000;i++) jc[i]=1ll*jc[i-1]*i%mod;
    jc_inv[0]=jc_inv[1]=1;
    for(int i=2;i<=2000;i++)
    {
    	jc_inv[i]=1ll*(mod-mod/i)*jc_inv[mod%i]%mod;
	}
	for(int i=1;i<=2000;i++)
	{
		jc_inv[i]=1ll*jc_inv[i-1]*jc_inv[i]%mod;
	}
    for(int i=2;i<=n;i++)
    {
        int fa=io.rd();
        t1.e[fa].push_back(i);
        t1.son[fa]++;
    }
    for(int i=2;i<=m;i++)
    {
        int fa=io.rd();
        t2.e[fa].push_back(i);
        t2.son[fa]++;
    }
    q=io.rd();
    build(1,1,q);
    for(int i=1;i<=q;i++)
    {
        int op=io.rd(),x=io.rd();
        // ans=match(1,1,op,x);
        // io.wt(ans,'\n');
       if(op==1)
       {
           clr[x]=i;
       }
       else if(op==2)
       {
           change(1,clr[x],i-1,x);
           clr[x]=0;
       }
    }
   for(auto x:clr)
   {
       if(x.second!=0)
       {
           change(1,x.second,q,x.first);
       }
   }
   get_ans(1);
   for(int i=1;i<=q;i++)
   {
       io.wt(Ans[i],'\n');
   }
    // fclose(stdin);fclose(stdout);
    return 0;
}
