#include<bits/stdc++.h>
using namespace std;

const int N=10+5;

int n,m,q,cnt,cnt1,ans,a[N],ct[N],ct1[N],siz[N],siz1[N],head[N],head1[N];
bool b[N];

struct edge{
    int to,nxt;
}e[N<<1],e1[N<<1];

void add(int u,int v){
    e[++cnt]=(edge){v,head[u]};
    head[u]=cnt;
}

void add1(int u,int v){
    e1[++cnt1]=(edge){v,head1[u]};
    head1[u]=cnt1;
}

bool check(int x,int y){
    //cout<<x<<' '<<y<<endl;
    if(siz[x]!=siz1[y]) return false;
    //cout<<x<<' '<<y<<endl;
    for(int i=1;i<a[x];i++){
        if(ct1[y]!=1) return false;
        y=e1[head1[y]].to;
    }
    if(ct[x]!=ct1[y]) return false;
    for(int i=head[x],j=head1[y];i&&j;i=e[i].nxt,j=e1[j].nxt){
        int v1=e[i].to,v2=e1[j].to;
        if(!check(v1,v2)) return false;
    }
    return true;
}

void init(int u){
    siz[u]=a[u];ct[u]=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        ct[u]++;
        init(v);
        siz[u]+=siz[v];
    }
    //cout<<u<<' '<<siz[u]<<endl;
}

void dfs(int x){
    if(x==n+1){
        //for(int i=1;i<=n;i++)
        //    cout<<a[i]<<' ';
        //cout<<endl;
        init(1);
        ans+=check(1,1);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]) continue;
        a[x]=i;
        dfs(x+1);
        a[x]=0;
    }
}

void init1(int u){
    siz1[u]=1;
    for(int i=head1[u];i;i=e1[i].nxt){
        int v=e1[i].to;
        ct1[u]++;
        init1(v);
        siz1[u]+=siz1[v];
    }
    //cout<<u<<' '<<siz1[u]<<endl;
}

int main(){
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=2,x;i<=n;i++){
        scanf("%d",&x);
        add(x,i);
    }
    for(int i=2,x;i<=m;i++){
        scanf("%d",&x);
        add1(x,i);
    }
    init1(1);
    scanf("%d",&q);
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        if(x==1) b[y]=true;
        else b[y]=false;
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
