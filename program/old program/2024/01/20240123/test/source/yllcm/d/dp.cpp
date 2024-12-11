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
int main() {
  for(int T = 1; ; T++) {
    system("./data");
    system("./d");
    system("./std");
    if(system("diff -b std.out d.out"))break;
    printf("Accepted:%d\n", T);
  }
  return 0;
}