#include<bits/stdc++.h>

#define rand rnd
#define ll long long
#define INF 2147483647

int inp(){
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    int sum = 0;
    while(c >= '0' && c <= '9'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    return sum;
}

ll f[20][100], dis[100][100];
int c[100];
std::mt19937 rand(time(0));

int main(){
    // srand((unsigned)time(NULL));
    int n = inp();
    int k = inp();
    int T = 5000;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = inp();
    ll ans = 1e18;
    while(T--){
        for(int i = 1; i <= n; i++){
            c[i] = rand() & 1;
            f[0][i] = 1e18;
        }
        f[0][1] = 0;
        for(int i = 0; i < k; i++){
            for(int j = 1; j <= n; j++)
                f[i + 1][j] = 1e18;
            for(int j = 1; j <= n; j++)
                for(int u = 1; u <= n; u++)
                    if(c[j] != c[u])
                        f[i + 1][u] = std::min(f[i + 1][u], f[i][j] + dis[j][u]);
        }
        ans = std::min(ans, f[k][1]);
    }
    printf("%lld\n", ans);
}