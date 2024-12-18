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
  freopen("b.in", "w", stdout);
  int n1 = 800, n2 = 800;
  printf("%d %d\n", n1, n2);
  for(int i = 1; i < n1; i++)cout << i << endl;
  for(int i = 1; i < n1; i++)cout << i << endl;
  int Q = 100;
  printf("%d\n", Q);
  for(int i = 1; i <= Q; i++)cout << 1 << ' ' << i << endl;
  return 0;
}