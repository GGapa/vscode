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
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int Maxn=8e2+10,mod=1e9+7;
vector<int> son1[Maxn],son2[Maxn];
int father[Maxn];
int fa[Maxn][Maxn];
int n1,n2;
inline void init(){
    n1=read();n2=read();
    fr(i,2,n1){
        int x;
        x=read();
        son1[x].push_back(i);
    }
    fr(i,2,n2){
        int x;x=read();
        son2[x].push_back(i);
        father[i]=x;
        fa[i][1]=x;
    }
    fr(i,1,n2) fa[i][0]=i;
    fr(j,2,n2) fr(i,1,n2) fa[i][j]=fa[father[i]][j-1];
}
int f[Maxn][Maxn];
inline void add(int &x,int y){
    x+=y;if(x>=mod) x-=mod;
}
inline int getfa(int x,int y){
    int pop=x;
    fr(i,0,10) if(y&(1<<i)) pop=fa[pop][i];
    return pop;
}
int vis[Maxn];
vector<int> use;
int maxln[Maxn];
inline void dfs(int x){
    for(register int i=0;i<son2[x].size();++i){
        int y;
        y=son2[x][i];
        dfs(y);
    }
    int now=1;
    fr(i,1,n1){
        if(!(son1[i].size()==son2[x].size())) continue;
        now=1;
        for(register int j=0;j<son1[i].size();++j) now=1ll*now*f[son2[x][j]][son1[i][j]]%mod;
        if(now==0) continue;
		// cout<<"*"<<x<<' '<<i<<' '<<now<<endl;
        for(register int j=0;j<use.size();++j){
            int y=use[j];
            if(y>maxln[x]) break;
            // int pop=x;
            // fr(j,1,y-1) pop=father[pop];
            // int pop=getfa(x,y-1);
            int pop=fa[x][y-1];
            add(f[pop][i],now);
        }
    }
}
inline void getans(){
    fr(i,1,n2) fr(j,1,n1) f[i][j]=0;
    use.clear();
    fr(i,1,max(n1,n2)) if(vis[i]) use.push_back(i);
    dfs(1);
    // fr(i,1,n2) fr(j,1,n1) cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
    writeln(f[1][1]);
}
inline void work(){
    int q;q=read();
    fr(i,1,n2){
        int ln=0;
        int x=i;
        while(1){
            if(!x) break;
            if(x!=i && son2[x].size()>1) break;
            ++ln;x=father[x];
        }
        maxln[i]=ln;
    }
    // fr(i,1,n2) cout<<i<<' '<<maxln[i]<<endl;
    while(q--){
//        cerr<<q<<endl;
        int tp,x;
        tp=read();x=read();
        vis[x]^=1;
        getans();
    }
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    init();work();
//     cerr<<clock()<<endl;
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
