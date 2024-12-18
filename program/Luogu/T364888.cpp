//T364888 电脑中了满屏粉兔病毒
//https://www.luogu.com.cn/problem/T364888?contestId=121028
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 500 * 500 + 5;
int n, m, N, M;
/*
vector <int> mapH[maxn];//雄性  横向
vector <int> mapS[maxn];//ts    纵向
*/
int xF[maxn], yF[maxn];//雌性
int xM[maxn], yM[maxn];//xiong

char map[505][505];

int main(){
    cin >> n >> m >> N >> M;
    int cnt = 1;
    int cnt2 = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'F') {
                xF[cnt] = i;
                yF[cnt++] = j;
            }
            if(map[i][j] == 'M') {
                xM[cnt2] = i;
                yM[cnt2++] = j;
            }
        }
    int sum = 0;
    for(int i = 1; i <= cnt; i++) {
        int Run = 0;
        int x, y;
        x = xF[i];
        y = yF[i];
        while(map[x - 1][y] != 'M' && x - 1 >= 1) 
            x--;
        if(x == 1) Run++;
        x = xF[i];
        y = yF[i];
        while(map[x + 1][y] != 'M' && x + 1 <= n ) 
            x++;
        if(x == n) Run++;
        x = xF[i];
        y = yF[i];
        while(map[x][y - 1] != 'M' && y - 1 >= 1) 
            y--;
        if(y == 1) Run++;
        x = xF[i];
        y = yF[i];
        while(map[x][y + 1] != 'M' && y + 1 <= m) 
            y++;
        if(y == m) Run++;
        x = xF[i];
        y = yF[i];
        if(Run >= 3) 
            sum++;
    }
    for(int i = 1; i <= cnt2; i++) {
        int Run = 0;
        int x, y;
        x = xM[i];
        y = yM[i];
        while(map[x - 1][y] != 'F' && x - 1 >= 1) 
            x--;
        if(x == 1) Run++;
        x = xM[i];
        y = yM[i];
        while(map[x + 1][y] != 'F' && x + 1 <= n) 
            x++;
        if(x == n) Run++;
        x = xM[i];
        y = yM[i];
        while(map[x][y - 1] != 'F' && y - 1 >= 1) 
            y--;
        if(y == 1) Run++;
        x = xM[i];
        y = yM[i];
        while(map[x][y + 1] != 'F' && y + 1 <= m) 
            y++;
        if(y == m) Run++;
        x = xM[i];
        y = yM[i];
        if(Run >= 3) 
            sum++;
    }
    cout << sum << endl;
    return 0;
}