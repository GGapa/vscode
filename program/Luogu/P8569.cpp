#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using ull = unsigned long long ;

namespace READ
{
	ull Read()
	{
		char ch=getchar();
		ull s=0;
		while(ch<'0'||ch>'9') ch=getchar();
		while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
		return s;
	}
	ull tp[10005];
	int l,r;
	ull g1,g2;
	void init(int &n)
	{
		int i,k;
		n=Read(),k=Read(),l=1;
		for(i=1;i<=k;i++)
			tp[i]=Read();
	}
	ull read()
	{
		if(l>r)
			l=Read(),r=Read(),g1=Read(),g2=Read();
		return tp[l++]*g1+g2;
	}
}

ull res;

inline ull C2(int x){return 1ull*x*(x-1)/2;}
ull w[30];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; READ::init(n);   
	ull sum=0;
	int lim=0;
	rep(i, 1, n) {
		ull x=READ::read();
		sum+=(~x);
		ull up=(~x),nup;
		for(int j=0;j<=lim;++j){
			sum-=(w[j]&x)<<j;
			w[j]&=(~x);
			nup=up&w[j];
			w[j]^=up;
			up=nup; 
		}
		if((i&-i)==i)++lim;
		res-=sum;
	}
	res-=C2(n+1);
	cout<<res;
    return 0;
}
