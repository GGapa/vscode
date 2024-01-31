#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0)*random_device{}());
int N=400,M=800;
int P[805];
bool vis[805];
int main(){
	freopen("b.in","w",stdout);
	printf("%d %d\n",N,M);
	for(int i=2;i<=N;i++) printf("%d%c",i-1,i==N?'\n':' ');
	for(int i=2;i<=M;i++) printf("%d%c",i-1,i==M?'\n':' ');
	int Q=100;
//	for(int i=1;i<=Q;i++) P[i]=i;
//	shuffle(P+1,P+1+Q,rd);
	printf("%d\n",Q);
//	for(int i=1;i<=Q;i++) printf("1 %d\n",P[i]) ;
	while(Q--){
		int x=rd()%400+1;
		while(vis[x]) x=rd()%400+1;
		vis[x]=1;
		printf("%d %d\n",1,x);
	}
	return 0;
}
