//P3868 [TJOI2009] 猜数字
//https://www.luogu.com.cn/problem/P3868
#include <iostream>
using namespace std;
const int maxn = 10 + 5;
typedef long long ll;
inline int read() {
    int f = 1,x = 0;
    char c;
    c = getchar();
    while(!isdigit(c)) {
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return f * x;
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(a % b == 0) {
        x = 0;
        y = 1;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;

}

ll inv(ll x, ll y) {
    ll a, b;
    exgcd(x, y, a, b);
    return (a % y + y) % y;
}

inline void write(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}

int k;
int a[maxn], b[maxn];
ll t[maxn];
ll sum = 1;
int main() {
    k = read();
    for(int i = 1;i <= k; i++) 
        a[i] = read();
    for(int i = 1;i <= k; i++) {
        b[i] = read();
        a[i] = (a[i] % b[i] + b[i]) % b[i];
        sum *= b[i];
    }
    __int128 ans = 0;
    for(int i = 1; i <= k ; i++) {
        t[i] = sum / b[i];
        ans = (__int128)(ans + (__int128)((__int128)((__int128)(inv(t[i], b[i]) % sum) * a[i]) % sum) * t[i] % sum) % sum;
    }
    write(ans);
    return 0;
}