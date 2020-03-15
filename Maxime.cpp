#include <iostream>
#include "pieces.h"
#include <array>

using namespace std;

struct P {
   P(size_t id = 0, size_t rot = 0) : id(id), rot(rot) {}

   size_t id = 0;
   size_t rot = 0;

   Piece getPiece() const {
      return PIECES[id];
   }

   string getCode() {
      char v = 'a' + rot;
      return to_string(id + 1) + v;
   }
};

using Tableau = array<P, 9>;

bool checkAttachement(AttachementType aA, AttachementType aB) {
   switch (aA) {
      case DAME_HAUT:
         return aB == DAME_BAS;
      case DAME_BAS:
         return aB == DAME_HAUT;
      case FILLE_HAUT:
         return aB == FILLE_BAS;
      case FILLE_BAS:
         return aB == FILLE_HAUT;
      case ARROSOIR_GAUCHE:
         return aB == ARROSOIR_DROIT;
      case ARROSOIR_DROIT:
         return aB == ARROSOIR_GAUCHE;
      case GATEAU_GAUCHE:
         return aB == GATEAU_DROIT;
      case GATEAU_DROIT:
         return aB == GATEAU_GAUCHE;
      default:
         return false;
   }
}

bool tester(size_t p, const Tableau &tab) {
   if (p - 3 > 0) {
      if (!checkAttachement(tab[p].getPiece()[0], tab[p - 3].getPiece()[2]))
         return false;
   }
   if (p - 1 > 0) {
      if (!checkAttachement(tab[p].getPiece()[3], tab[p - 1].getPiece()[1]))
         return false;
   }
   return true;
}

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

