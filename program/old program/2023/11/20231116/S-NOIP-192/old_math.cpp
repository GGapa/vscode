#include <bits/stdc++.h>
using namespace std;
#define int __int128
typedef pair<int, int> pii;

int n, sum;
pii B, A, C;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

int gcd(int a,int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

void easy(pii& x) {
    bool flag = (x.first * x.second < 0);
    x.first = x.first < 0 ? -x.first : x.first;
    x.second = x.second < 0 ? -x.second : x.second;
    int gd = gcd(x.first, x.second);
    x.first /= gd; x.second /= gd;
    if(flag) x.first *= -1;
}

pii add(pii x, pii y) {
    x.first = x.first * y.second + y.first * x.second;
    x.second = x.second * y.second;
    easy(x);
    return x;
}
pii sub(pii x, pii y) {
    x.first = x.first * y.second - y.first * x.second, x.second *= y.second;
    easy(x);
    return x;
}


pii pow2(pii x) {
    x.first *= x.first; x.second *= x.second;
    easy(x);
    return x;
}

pii mul(pii x, int y) {
    if(y == 0) return make_pair(0, 1);
    if(x.second % y == 0) x.second /= y, y = 1;
    else {
        x.first *= y;
    }
    easy(x);
    return x;
}

pii dvi(pii x, int y) {
    x.second *= y;
    easy(x);
    return x;
}

void out() {
    easy(A); easy(B);
    write(sum); 
    putchar(' ');
    if((A.first) % (A.second) == 0) write(A.first / A.second);
    else write(A.first), putchar('/'), write(A.second);
    putchar(' ');
    if(B.first % B.second == 0) write(B.first / B.second);
    else write(B.first), putchar('/'), write(B.second);
    putchar('\n');
}   

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
// #ifdef ONLINE_JUDGE
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
// #endif
    n = read(); 
    A.second = B.second = 1;
    for(int i = 1, x; i <= n; i++) {
        x = read();
        sum += x;
        A.first = sum; A.second = i;
        B = add(B, pow2(make_pair(x, 1)));
        C = B;
        B = sub(dvi(B, i), pow2(A));
        out();
        B = C;
    }
    return 0;
}