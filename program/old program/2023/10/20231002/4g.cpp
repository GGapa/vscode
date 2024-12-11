//枚举：举例正方形的最大边长
#include<iostream>
#include<stack>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2000005;
int n;
long long a[N],b[N],p[N];
long long l[N],r[N];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    //p表示坐标
    p[i+1]=p[i]+b[i];
  }
  int stk[N],top=0;
  for(int i=1;i<=n;i++){
    while(top&& a[i]< a[stk[top]] ){
      r[stk[top]]=i; //记录自身右边第一个小于自身的位置
      top--; //出栈
    }
    stk[++top]=i;
  }
  while(top){
    r[stk[top]]=n+1;
    top--;
  }
  for(int i=n;i>=1;i--){
    while(top&& a[i]< a[stk[top]] ){
      l[stk[top]]=i; //记录自身右边第一个小于自身的位置
      top--; //出栈
    }
    stk[++top]=i;
  }
  while(top){
    l[stk[top]]=n+1;
    top--;
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    ll lp=p[l[i]+1]; //最左侧的坐标
    ll rp=p[r[i]-1]+b[r[i]-1]; //最右侧的坐标
    if(rp-lp>=a[i]) ans=max(ans,1ll*a[i]*a[i]);
    else ans=max(ans,1ll*(rp-lp)*(rp-lp));
  }
  cout<<ans;
  return 0;
}