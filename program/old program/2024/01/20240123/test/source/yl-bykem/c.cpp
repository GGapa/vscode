#include <algorithm>
#include <iostream>
#include <vector>
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

int main() {
  RF("c");
  ios_base::sync_with_stdio(0), cin.tie(0);

  return 0;
}
/*
f({1,2})=
  1+
  1/3*(
    2/3*f({1,2})
    1/3*f({0,3})
  )+
  2/3*(
    2/3*f({1,2})
    1/3*f({1,2})
  )

f({1,m-1})=
  1+
  1/m*(
    (m-1)/m*f({1,m-1})
    1/m*f({0,m})
  )+
  (m-1)/m*(
    (m-1)/m*f({2,m-2})
    1/m*f({1,m-1})
  )

f({a,m-a})=
  1+
  a/m*(
    (m-a)/m*f({a,b})
    a/m*f({a-1,m-a+1})
  )+
  (m-a)/m*(
    (m-a)/m*f({a+1,m-a-1})
    a/m*f({a,b})
  )

((m-a)^2+a^2)*f({a,m-a})=m^2+a^2*f({a-1,m-a+1})+(m-a)^2*f({a+1,m-a-1})

f({1,m-1})=1+(2m-2)/(m^2)*f({1,m-1})+(m-1)^2/m^2*f({2,m-2})
((m-1)^2+1)*f({1,m-1})=m^2+(m-1)^2*f({2,m-2})
((m-2)^2+4)*f({2,m-2})=m^2+4*f({1,m-1})+(m-2)^2*f({3,m-3})
*/