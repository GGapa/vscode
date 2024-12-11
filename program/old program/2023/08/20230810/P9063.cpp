    //P9063 [yLOI2023] 分解只因数
    //https://www.luogu.com.cn/problem/P9063
    #include <iostream>
    using namespace std;
    typedef long long ll;
    int T;
    ll n;
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> T;
        while(T--) {
            cin >> n;
            if(n % 2) cout << "Yes\n";
            else cout << "No\n";
        }
        return 0;
    }