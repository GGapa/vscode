// P1092 [NOIP2004 提高组] 虫食算
#include <bits/stdc++.h>
#define up(l, r, i) for (int i = l, END##i = r; i <= END##i; ++i)
#define dn(r, l, i) for (int i = r, END##i = l; i >= END##i; --i)
using namespace std;
typedef long long i64;
const int INF = 2147483647;
const int MAXN = 26 + 3;
string A, B, C;
int n, X[MAXN];
bool F[MAXN];
bool check()
{
    for (int i = n - 1; i >= 0; --i)
    {
        int u = X[A[i] - 'A'];
        int v = X[B[i] - 'A'];
        int w = X[C[i] - 'A'];
        if (u != -1 && v != -1 && w != -1)
        {
            if ((u + v) % n != w && (u + v + 1) % n != w)
                return false;
        }
    }
    return true;
}
void dfs(int d, int f)
{
    if (d == -1)
    {
        if (f == 0)
        {
            up(0, n - 1, i)
                    cout
                << X[i] << " ";
            cout << endl;
            exit(0);
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            bool fi = false;
            if (X[A[d] - 'A'] != -1)
            {
                fi = true;
                i = X[A[d] - 'A'];
            }
            else
            {
                int u = A[d] - 'A';
                if (F[i] == false)
                {
                    X[u] = i;
                    F[i] = true;
                }
                else
                {
                    continue;
                }
            }
            for (int j = 0; j < n; ++j)
            {
                bool fj = false;
                if (X[B[d] - 'A'] != -1)
                {
                    fj = true;
                    j = X[B[d] - 'A'];
                }
                else
                {
                    int u = B[d] - 'A';
                    if (F[j] == false)
                    {
                        X[u] = j;
                        F[j] = true;
                    }
                    else
                    {
                        continue;
                    }
                }
                for (int k = 0; k < n; ++k)
                {
                    bool fk = false;
                    if (X[C[d] - 'A'] != -1)
                    {
                        fk = true;
                        k = X[C[d] - 'A'];
                    }
                    else
                    {
                        int u = C[d] - 'A';
                        if (F[k] == false)
                        {
                            X[u] = k;
                            F[k] = true;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    if ((i + j + f) % n == k && check())
                    {
                        dfs(d - 1, (i + j + f) / n);
                    }

                    if (fk == true)
                    {
                        break;
                    }
                    else
                    {
                        int u = C[d] - 'A';
                        X[u] = -1;
                        F[k] = false;
                    }
                }
                if (fj == true)
                {
                    break;
                }
                else
                {
                    int u = B[d] - 'A';
                    X[u] = -1;
                    F[j] = false;
                }
            }
            if (fi == true)
            {
                break;
            }
            else
            {
                int u = A[d] - 'A';
                X[u] = -1;
                F[i] = false;
            }
        }
    }
}
int main()
{
    cin >> n;
    cin >> A >> B >> C;
    up(0, n - 1, i)
        X[i] = -1;
    dfs(n - 1, 0);
    return 0;
}