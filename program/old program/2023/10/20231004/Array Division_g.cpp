//Array Division
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> A;
int n, k;
ll sum;

bool check(ll m) {
    ll s = 0, g = 0;
    for(auto a : A) {
        if(a > m) return false;
        if(s + a > m) ++g, s = 0;
        s += a;
    }
    return g + (s > 0) <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    A.resize(n);
    for(auto &a : A)  cin >> a, sum += a;
    ll l = 0, r = sum;
    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        (check(mid) ? r : l) = mid;               
    }
    cout << r << "\n";
    return 0;
}