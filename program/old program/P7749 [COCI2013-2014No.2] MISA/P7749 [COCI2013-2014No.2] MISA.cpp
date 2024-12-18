//P7749 [COCI2013-2014#2] MISA
#include <iostream>
using namespace std;
char map[51][51];
int num[51][51],ans=0,setdownx,setdowny,fx[8]={0,-1,-1,-1,0,1,1,1},fy[8]={-1,-1,0,1,1,1,0,-1},maxsetdownnum=-1;
bool ifsetdown=false,ifsayhello[51][51][51][51]={false};
int main()
{
    int r,s;
    cin>>r>>s;
    for(int i = 1;i<=r;i++)
    {
        for(int j = 1;j<=s;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i = 1;i<=r;i++)
    {
        for(int j = 1;j<=s;j++)
        {
            if(map[i][j]=='.')
            {
                ifsetdown=true;
                int temp=0;
                for(int q = 0;q<8;q++)
                {
                    int X=fx[q]+i,Y=fy[q]+j;
                    if(X<=0||Y<=0||X>r||Y>s)continue;
                    if(map[X][Y]=='o')temp++;
                }
                if(temp>maxsetdownnum)
                {
                    maxsetdownnum=temp;
                    setdownx=i;
                    setdowny=j;
                }
            }
        }
    }
    if(ifsetdown==true)
    {
        map[setdownx][setdowny]='o';
    }
    for(int i = 1;i<=r;i++)
    {
        for(int j = 1;j<=s;j++)
        {
            if(map[i][j]=='o')
            {
                for(int q = 0;q<8;q++)
                {
                    int X=fx[q]+i,Y=fy[q]+j;
                    if(X<=0||Y<=0||X>r||Y>s||ifsayhello[i][j][X][Y])continue;
                    if(map[X][Y]=='o')ans++,ifsayhello[i][j][X][Y]=true,ifsayhello[X][Y][i][j]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
