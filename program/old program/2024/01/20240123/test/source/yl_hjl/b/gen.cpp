#include<bits/stdc++.h>
#define db double
#define int ll
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#define MP make_pair
#define pii pair<int, int>
#define vec vector<int>
#define fi first
#define se second
#define ls k<<1
#define rs k<<1|1
#define CLK (double)clock()/(double)CLOCKS_PER_SEC
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void write(register int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

void MAIN(){
    int n=800;cout<<n<<' '<<n<<"\n";
    for(int i=2;i<=n;i++)cout<<i-1<<' ';cout<<"\n";
    for(int i=2;i<=n;i++)cout<<i-1<<' ';cout<<"\n";
    cout<<100<<"\n";
    for(int i=1;i<=100;i++){
        cout<<"1 "<<i<<"\n";
    }
}
signed main(){
    freopen("b.in","w",stdout);
    int T=1;while(T--)MAIN();
//  printf("\nTIME:%lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
