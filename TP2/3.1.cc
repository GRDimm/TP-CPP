#include <iostream>
using namespace std;
  
// Ne touchez pas à cette fonction! Utilisez-là telle qu'elle est.
void GetDate(int* year, int* month, int* day) {
  *year = 7654;
  *month = 11;
  *day = 22;
}
  
int main() {
  // TODO: Utilisez GetDate() pour récuperer la date dans des
  // variables y, m et d de type int.

  int y;
  int m;
  int d;

  GetDate(&y, &m, &d);

  // Affichage de la date.
  cout << y << "-" << m << "-" << d << endl;
}