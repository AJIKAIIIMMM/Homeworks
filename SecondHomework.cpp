#include <iostream>

using namespace std;

int main() {
// Задание №1
  int a = 10;
  char b = 'B';
  long c = 15;
  long long d = 20;
  float e = 5.4;
  double f = 5.235235;
  bool g = true;

  std::cout << a << " " <<  b << " " << c << " " << d <<
   " " << e << " " << f << " " << g << std::endl;
//Задание №2,3
  enum GameCN {X = 88, O = 79, BLANK = 22};
  int SignX = X;
  int SignO = O;
  int SignBLANK = BLANK;
  char MassForGame[3] = {SignX, SignO, SignBLANK};
  for (int i = 0; i < 3; ++i) {
            cout << MassForGame[i] << " ";
        }cout << endl;
//Задание №4
  struct areaforplaying {
  char Cross;
  char Zero;
  char space;
  } area [3]{88, 79, 22};
// Задание №5
  struct areaforplaying1 {
        union Crosses{
          char Cross1:1;
          int Cross2:1;
      }Xs;
        union Zeros{
            char Zero1:1;
            int Zero2:1;
         }Os;
        union Spaces{
            char space1:1;
            int space2:1;
      }Sps;
    }AreaP;
    AreaP.Xs.Cross1 = 1;
    AreaP.Xs.Cross2 = 0;
    AreaP.Os.Zero1 = 1;
    AreaP.Os.Zero2 = 0;
    AreaP.Sps.space1 = 1;
    AreaP.Sps.space2 = 0;

  return 0;
}
