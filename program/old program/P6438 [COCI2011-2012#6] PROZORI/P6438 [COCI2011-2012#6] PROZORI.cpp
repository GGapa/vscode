#include <iostream>
using namespace std;
char map[600][600];
int ans[5]={0};
int main()
{
    int n,m;
    cin>>n>>m;
    n=n*5+1;
    m=m*5+1;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }for(int i = 1;i<n;i+=5)
    {
        for(int j = 1;j<m;j+=5)
        {
            int num=0;
            for(int q = i;q<=n;q++)
            {
                if(map[q][j]=='*')num++;
                else break;
            }
            ans[num]++;
        }
    }
    for(int i = 0;i<5;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
