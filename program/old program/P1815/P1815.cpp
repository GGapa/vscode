//P1815 蠕虫游戏
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int map[55][55];
int n,x,y;
bool br=false;
void cheak(int z)
{
    if(x<1||y<1||x>50||y>50)
    {
        printf("The worm ran off the board on move %d.\n",z-20);
        br=true;
    }
    else if(z-20<map[x][y])
    {
        printf("The worm ran into itself on move %d.\n",z-20);
        br=true;
    }
}
int main()
{
    string in;
    while(scanf("%d",&n))
    {
        if(n==0)break;
        x=25;
        y=30;
        memset(map,0,sizeof(map));
        for(int i = 11;i<=30;i++)
        {
            map[25][i]=i-10;
        }
        in="";
        cin>>in;
        br=false;
        for(int i = 0;i<in.length();i++)
        {
            if(in[i]=='N')
            {
                x--;
                cheak(i+21);
                map[x][y]=i+21;
            }
            else if(in[i]=='S')
            {
                ++x;
                cheak(i+21);
                
                map[x][y]=i+21;
            }
            else if(in[i]=='E')
            {
                ++y;
                cheak(i+21);
                
                map[x][y]=i+21;
            }
            else if(in[i]=='W')
            {
                --y;
                cheak(i+21);
                
                map[x][y]=i+21;
            }
            if(br==true) 
                break;
        }
        if(br==true)
            continue;
        printf("The worm successfully made all %d moves.\n",in.length());
    }
    return 0;
}