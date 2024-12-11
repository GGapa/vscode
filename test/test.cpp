#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull p2[70], dp[70];
int oe[70];
int n;
ull k;
ull sol(int x) {
    for (int i = 1; i <= n; i++) {
        if (i <= x) {
            dp[i] = 1;

            for (int j = 1; j < i; j++) {
                bool fl = 1;

                for (int z = 1; z <= j; z++)
                    fl &= (oe[z] == oe[i - j + z]);

                if (fl)
                    dp[i] = 0;
            }

            continue;
        }

        dp[i] = p2[i - x];

        for (int j = 1; j <= i / 2; j++)
            if (dp[j]) {
                if (x <= i - j) {
                    dp[i] -= dp[j] * p2[i - j - max(x, j)];
                    continue;
                }

                bool fl = 1;

                for (int z = 1; z <= j && z + i - j <= x; z++)
                    fl &= (oe[z] == oe[i - j + z]);

                if (fl)
                    dp[i]--;
            }
    }

    return dp[n];
}
void sol() {
    cin >> n >> k;
    printf("%llu\n", sol(0));

    for (int i = 1; i <= n; i++) {
        oe[i] = 0;
        ull tp = sol(i);

        if (k > tp)
            k -= tp, oe[i] = 1;

        cout << (oe[i] ? "b" : "a");
    }

    cout << endl;
}
int main() {
    p2[0] = 1;

    for (int i = 1; i < 64; i++)
        p2[i] = p2[i - 1] * 2;

    int T;
    cin >> T;

    while (T--)
        sol();

    return 0;
}