#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,n1,n2,q;
int fa1[801],fa2[801];
vector<int> T1[801],T2[801];
vector<int> CT1[801],CT2[801];
int tag1[801],tag2[801];
int bel1[801],bel2[801];
int W1[801],W2[801];
pair<int,int> Q[801];
int qcnt,l1cnt,l2cnt;
unordered_set<int> S;
int f[801][801];
bool iff[801][801];
void clear(){
	for(int i=0;i<=800;i++){
		for(int j=0;j<=800;j++){
			f[i][j]=iff[i][j]=0;
		}
	}
	for(int i=0;i<=800;i++)iff[0][i]=1,T1[i].clear(),T2[i].clear(),CT1[i].clear(),CT2[i].clear();
	f[0][0]=1;
	return;
}
int getf(int ncnt,int num){
	if(num<0)return 0;
	// cerr<<ncnt<<" "<<num<<" "<<f[ncnt][num]<<"\n";
	if(iff[ncnt][num])return f[ncnt][num];
	iff[ncnt][num]=1;
	for(auto p:S)f[ncnt][num]+=getf(ncnt-1,num-p);
	// cout<<f[ncnt][num]<<" "<<ncnt<<" "<<num<<" getting\n";
	return f[ncnt][num]%=mod;
}
void getL1(int st,int ed,int siz){
	bel1[st]=l1cnt;
	if(st==ed){
		W1[l1cnt]=siz+1;
		return;
	}
	for(auto v:T1[st])getL1(v,ed,siz+1);
	return;
}
void getL2(int st,int ed,int siz){
	bel2[st]=l2cnt;
	if(st==ed){
		W2[l2cnt]=siz+1;
		return;
	}
	for(auto v:T2[st])getL2(v,ed,siz+1);
	return;
}
int lst;
void dfsT1(int now){
	if(T1[now].size()==1){
		tag1[now]=1;
		if(!lst)lst=now;
	}
	else{
		if(lst)++l1cnt,getL1(lst,now,0),lst=0;
		else ++l1cnt,getL1(now,now,0);
	}
	for(auto v:T1[now])dfsT1(v);
	return;
}
void dfsT2(int now){
	if(T2[now].size()==1){
		tag2[now]=1;
		if(!lst)lst=now;
	}
	else{
		if(lst)++l2cnt,getL2(lst,now,0),lst=0;
		else ++l2cnt,getL2(now,now,0);
	}
	for(auto v:T2[now])dfsT2(v);
	return;
}
bool chk(int now){
	if(CT1[now].size()!=CT2[now].size())return 0;
	bool res=1;
	for(auto v:CT1[now])res&=chk(v);
	return res;
}
int op,x;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n1>>n2;
	n=max(n1,n2);
	for(int i=2;i<=n1;i++)cin>>fa1[i],T1[fa1[i]].push_back(i);
	for(int i=2;i<=n2;i++)cin>>fa2[i],T2[fa2[i]].push_back(i);
	dfsT1(1),dfsT2(1);
	for(int i=2;i<=n1;i++)if(bel1[fa1[i]]!=bel1[i])CT1[bel1[fa1[i]]].push_back(bel1[i]);
	for(int i=2;i<=n2;i++)if(bel2[fa2[i]]!=bel2[i])CT2[bel2[fa2[i]]].push_back(bel2[i]);
	if(l1cnt!=l2cnt||!chk(1)){
		cin>>q;
		while(q--)cout<<0<<"\n";
		return 0;
	}
	// for(int i=1;i<=l1cnt;i++)cout<<W1[i]<<" "<<W2[i]<<"\n";
	// cout<<l1cnt<<" "<<l2cnt<<"\n";
	cin>>q;
	while(q--){
		cin>>op>>x;
		clear();
		if(op==1)S.insert(x);
		else S.erase(x);
		int ans=1;
		for(int i=1;i<=l1cnt;i++)ans=(ans*(getf(W1[i],W2[i])))%mod;
		cout<<ans<<"\n";
	}
	return 0;
}