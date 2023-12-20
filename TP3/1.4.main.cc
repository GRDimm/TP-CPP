#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "1.4.cc"

vector<int> ParseInts(const string& str) {
  vector<int> numbers;
  char* end;
  const char* start = str.c_str();
  while (*start) {
    while (*start && *start == ' ') start++;
    if (!*start) break;
    int x = strtol(start, &end, 10);
    if (end == start) {
      cerr << "Invalid input at position #" << start - str.c_str()
           << " (expecting an integer).\n";
      exit(1);
    }
    numbers.push_back(x);
    start = end;
  }
  return numbers; 
}
  
int main() {
  // Partie "input". Pas la peine de perdre du temps a la lire ou la comprendre; vous pouvez
  // la rÃ©utiliser simplement.
  cout << "Entrez la liste de nombres a trier, sÃ©parÃ©s par des espaces: ";
  string s;
  std::getline(cin, s);
  const vector<int> numbers = ParseInts(s);
  const int num = numbers.size();
  const int* values = numbers.data();

  // AprÃ¨s la partie "input", le tableau d'entiers est dÃ©crit par (num, values).
  int* sorted = SortRev(num, values);
  
  // Affichage des entiers triÃ©s.
  cout << "Tableau triÃ©:";
  for (int i = 0; i < num; ++i) {
    cout << " " << sorted[i];
  }
  cout << endl;
}