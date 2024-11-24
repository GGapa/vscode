#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1500 + 5;

int F[N][N];
int sum = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1), sss(4);
    vector<VI> vec(4);
    rep(i ,1, n) cin >> A[i] >> B[i], sss[A[i]] += B[i], vec[A[i]].emplace_back(B[i]);
    sum = sss[1] + sss[2] + sss[3];
    if(sum % 3 != 0) return cout << -1 << '\n', 0;
    fill_n(F[0], N * N, n + 1);
    F[sss[1]][sss[2]] = 0;
    
    for(auto t : vec[1]) rep(i, 0, sum) per(j, sum, 0) if(i + j <= sum)  if(i - t >= 0) {
        if(j + t <= sum) F[i - t][j + t] = min(F[i - t][j + t], F[i][j] + 1);
        F[i - t][j] = min(F[i - t][j], F[i][j] + 1);
    }
    for(auto t : vec[2]) per(i, sum, 0) rep(j, 0, sum) if(i + j <= sum)  if(j - t >= 0){
        if(i + t <= sum) F[i + t][j - t] = min(F[i + t][j - t], F[i][j] + 1);
        F[i][j - t] = min(F[i][j - t], F[i][j] + 1);
    }
    for(auto t : vec[3]) per(i, sum, 0) per(j, sum, 0) if(i + j <= sum)  {
        if(i + t <= sum) F[i + t][j] = min(F[i + t][j], F[i][j] + 1);
        if(j + t <= sum) F[i][j + t] = min(F[i][j + t], F[i][j] + 1);
    }
    cout << (F[sum / 3][sum / 3] <= n ? F[sum / 3][sum / 3] : -1) << '\n';
    return 0;
}
/*
11
1 1
1 1
1 2
1 1
1 1
1 1
1 1
2 1
2 1
3 1
3 1
*/