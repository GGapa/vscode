//枚举：举例+验证
//计数：往上一级看，找合法的。
//合法：6个位置上面的数，相邻的两个数都是质数
#include<iostream>
using namespace std;
const int N=505;
bool vis[N];
bool check(int x){ //判断质数
  for(int i=2;i*i<=x;i++)
    if(x%i==0) return false;
  return true;
}

void init(){
  for(int i=2;i<=500;i++)
    if(check(i)) vis[i]=true;
}
int a[N][N]; //a[i][j]=k  以i开有j结束的序列，方案数为k
int tmp[N][N];
int main(){

  init();
  int n,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(vis[i+j]){
        a[i][j]++;//以i开头j结尾的方案数+1
      }
    }
  }
  for(int s=1;s<=4;s++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        tmp[i][j]=a[i][j];
        a[i][j]=0;
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){ //举例a数组
        for(int k=1;k<=n;k++){ //举例新进来的数字
          if(vis[j+k]){
            a[i][k]=(a[i][k]+tmp[i][j])%618;
          }
        }
      }
    }
  }

  for(int i=1;i<=n;i++){ //举例第一个数字
    for(int j=1;j<=n;j++){ //举例第6个数字
      if(vis[i+j])
        ans=(ans+a[i][j])%618;
    }
  }
  cout<<ans;
  return 0;
}
