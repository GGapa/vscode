#include<bits/stdc++.h>
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
#define randfind(l,r) (rnd()%((r)-(l)+1)+(l))
#define pb push_back
#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){write(x); puts("");}
inline void writepl(int x){write(x); putchar(' ');}
//inline void init(){
//	int t=read();
//	while(t--) work();
//}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int Maxn=1e3+10,mod=998244353;
int num;
map<vector<int> ,int> mp;
vector<int> vc,vc1[Maxn];
inline void dfs(int x,int lst){
    if(x==0){
        mp[vc]=++num;
        vc1[num]=vc;
        return;
    }
    fr(i,lst,x){
        vc.push_back(i);
        dfs(x-i,i);
        vc.pop_back();
    }
}
int x[Maxn];
int a[Maxn][Maxn];
int n,m,t;
inline void init(){
    n=read();m=read();t=read();
    dfs(m,1);
}
int b[Maxn];
int c[Maxn];
inline void add(int &x,int y){
    x+=y;if(x>=mod) x-=mod;
}
int d[Maxn];
inline void addval(int id,int val1){
    vector<int> now;now.clear();
    fr(i,1,n){
        if(!d[i]) continue;
        now.push_back(d[i]);
    }
    sort(now.begin(),now.end());
    add(a[id][mp[now]],val1);
}
inline int ksm(int x,int y){
    int sum=1;
    while(y){
        if(y&1) sum=1ll*sum*x%mod;
        y=y/2;x=1ll*x*x%mod;
    }
    return sum;
}
int id[Maxn];
inline void guess(){
    // cout<<"&"<<num<<endl;
    // fr(i,1,num){
    //     fr(j,1,num+1) writepl(a[i][j]);
    //     puts("");
    // }
    fr(i,1,num){
        fr(j,i+1,num){
            if(abs(a[i][i])<abs(a[j][i])) swap(a[i],a[j]);
        }
        if(abs(a[i][i])==0) continue;
        fr(j,i+1,num){
            int k=1ll*ksm(a[i][i],mod-2)*a[j][i]%mod;
            fr(k,i,num+1) add(a[j][k],mod-1ll*a[i][k]*k%mod);
        }
    }
    rf(i,num,1){
        fr(j,i+1,num) add(a[i][num+1],mod-1ll*id[j]*a[i][j]%mod);
        if(id[i]==0) continue;
        id[i]=1ll*a[i][num+1]*ksm(a[i][i],mod-2)%mod;
    }
    fr(i,1,num) writepl(i),writeln(id[i]);
}
inline void work(){
    // cout<<1ll*8*ksm(9,mod-2)%mod<<endl;
    fr(i,1,num){
        vector<int> now=vc1[i];
        int s=0;
        int number=0;
        if(now.size()>n) continue;
        for(register int j=0;j<now.size();++j) b[j+1]=now[j],c[j+1]=m-now[j],++number;
        fr(j,(now.size()+1),n) b[j]=0,c[j]=m;
        fr(j,1,n) d[j]=b[j];
        int flag=1;
        fr(j,1,n) if(c[j]<0 || b[j]<0){
            flag=0;break;
        }
        if(!flag) continue;
        // writeln(i);
        // fr(j,1,n) writepl(b[j]);puts("");
        // writeln(i);
        // fr(j,1,n) writepl(c[j]);puts("");
        fr(j1,1,n) fr(j2,1,n){
            if(b[j1]<=0) continue;
            if(c[j2]<=0) continue;
            d[j1]--;d[j2]++;
            // fr(j,1,n) writepl(d[j]);puts("");
            // cout<<j1<<' '<<j2<<' '<<1ll*ksm(m,mod-2)*b[j1]%mod*ksm(1ll*(n-1)*m%mod,mod-2)%mod*c[j2]%mod<<endl;
            addval(i,mod-1ll*ksm(m,mod-2)*b[j1]%mod*ksm(1ll*(n-1)*m%mod,mod-2)%mod*c[j2]%mod);
            d[j1]++;d[j2]--;
        }
        // cout<<"*"<<i<<' '<<num+1<<endl;
        add(a[i][i],1);add(a[i][num+1],mod-1);
    }
    guess();
    while(t--){
        fr(i,1,n) d[i]=read();
        vector<int> now;now.clear();
        fr(i,1,n) if(d[i]) now.push_back(d[i]);
        sort(now.begin(),now.end());
        writeln(id[mp[now]]);
    }
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
    init();work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}