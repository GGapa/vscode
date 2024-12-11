#include<iostream>
#include<cstring>
using namespace std;
const int N=2005;
int n,x;
int a[N],b[N],c[N];
int ans=0;
int f[N][N];


int main(){
  
  cin>>n>>x;
  for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i]>>c[i];
  }
  
  memset(f,-0x3f,sizeof(f)); 
  f[0][0]=0;
  
  for(int i=1;i<=n;i++){
    for(int j=0;j<N;j++){
      f[i][min(N-1,j+a[i])]=max(f[i][min(N-1,j+a[i])],f[i-1][j]+a[i]);
      f[i][j]=max(f[i][j],f[i-1][j]+b[i]+min(c[i],2*b[i]));
      f[i][j]=max(f[i][j],f[i-1][j]+c[i]);
    }
  }
  int ans=-1;
  for(int i=x;i<N;i++)
    ans=max(ans,f[n][i]);
  cout<<ans<<endl;
  return 0;
}