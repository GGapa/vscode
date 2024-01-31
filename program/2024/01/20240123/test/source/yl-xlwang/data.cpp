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
signed main(){
	// freopen("input.in","r",stdin);
	freopen("b.in","w",stdout);
    cout<<400<<' '<<800<<endl;
    fr(i,2,400) cout<<i-1<<' ';cout<<endl;
    fr(i,2,800) cout<<i-1<<' ';cout<<endl;
    cout<<100<<endl;
    fr(i,1,100) cout<<1<<' '<<i<<endl;
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
