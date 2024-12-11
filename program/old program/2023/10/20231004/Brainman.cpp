/*
Brainman
https://vjudge.csgrandeur.cn/contest/584212#problem
2023-10-04
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1005;

int T;
int a[maxn], b[maxn];
int ans = 0;

void so(int l, int r) { //归并排序求解逆序对
    if(l == r) return;
    int mid = (l + r) / 2, x = l, y = mid + 1, z = l;
    so(l, mid);
    so(mid + 1, r);
    while(x <= mid && y <= r) {
        if(a[x] <= a[y]) 
            b[z++] = a[x++];
        else {
            b[z++] = a[y++];
            ans += mid - x + 1;
        }
    }
    while(x <= mid) //如果上面的那一部分还没有执行完
        b[z++] = a[x++];
    while(y <= r) 
        b[z++] = a[y++];
    for(int i = l; i <= r; i++) 
        a[i] = b[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    cin >> T;
    int it = 1;
    while(T--) {
        int n;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        ans = 0;
        cin >> n;
        //vector<int> a(n);
        for(int i = 1; i <= n; i++) cin >> a[i];
        so(1, n);
        printf("Scenario #%d:\n", it++);
        printf("%d\n\n", ans);
    }
    return 0;


}