#include <fstream>

using namespace std;

ifstream cin("CON");
ofstream cout("b.in");

const int kN = 400, kM = 800;

int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(0);
  cout << kN << ' ' << kM << '\n';
  for (int i = 1; i < kN; i++) {
    cout << i << " \n"[i == kN - 1];
  }
  for (int i = 1; i < kM; i++) {
    cout << i << " \n"[i == kM - 1];
  }
  cout << 800 << '\n';
  for (int i = 1; i <= 800; i++) {
    cout << 1 << ' ' << i << '\n';
  }
  return 0;
}
