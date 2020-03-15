#include <iostream>
#include "pieces.h"
#include <array>

using namespace std;



using Tableau = array<P, 9>;



void solutionRec(size_t idPi, size_t pos, Tableau &tab) {
   // PIECES[idPi]
   tab[pos].id = idPi;
   for (int i = 0; i < 4; ++i) {
      tab[pos].rot = i;
      if (tester(pos, pos - 1, tab) && tester(pos, pos - 3, tab)) {
         solutionRec(idPi, pos + 1, tab);
      }
   }
}

int main() {
   P p;
   for (int i = 0; i < 9; ++i) {
      for (int r = 0; r < 4; ++r) {
         p.id = i;
         p.rot = r;
         cout << p.getCode() << ' ';
      }
   }
   return 0;
}

