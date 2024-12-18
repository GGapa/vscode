#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

int n; 
int A[N];
double sqt[N], F[N];
double w(int j, int i) {
    return double(A[j]) + sqt[i - j];
}   

void work(int l, int r, int L, int R) {
    if(l > r) return ;
    int mid = l + r >> 1, p;
    double mx = 0;
    rep(i, L, min(mid, R)) if(w(i, mid) > mx) mx = w(i, mid), p = i;
    F[mid] = max(F[mid], mx);
    work(l, mid - 1, L, p);
    work(mid + 1, r, p, R);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> A[i], sqt[i] = sqrt(i);
    work(1, n, 1, n);
    rep(i, 1, n / 2) swap(A[i], A[n - i + 1]), swap(F[i], F[n - i + 1]);
    work(1, n, 1, n);
    per(i, n, 1) cout << (int)ceil(F[i]) - A[i] << '\n';
    return 0;
}