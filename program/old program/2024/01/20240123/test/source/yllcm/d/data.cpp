#include<bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int
#define FR first
#define SE second
using namespace std;
inline int read() {
  int x = 0; bool op = false;
  char c = getchar();
  while(!isdigit(c))op |= (c == '-'), c = getchar();
  while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
random_device rd;
mt19937_64 rnd(rd());
ll rand(ll l, ll r) {return rnd() % (r - l + 1) + l;}
int main() {
  freopen("d.in", "w", stdout);
  int n = rand(1, 6), m = n - 1, p = rand(0, n + m), k = rand(1, 30), t = rand(1, 998244352);
  printf("%d %d %d %d %d\n", n, m, k, p, t); 
  for(int i = 1; i <= n; i++)printf("%d ", rand(1, 998244352)); putchar('\n');
  for(int i = 2; i <= n; i++)printf("%d %d %d\n", rand(1, i - 1), i, rand(1, 998244352));
  return 0;
}