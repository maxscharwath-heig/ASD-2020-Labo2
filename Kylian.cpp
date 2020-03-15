#include <iostream>
#include "pieces.h"
#include <array>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

struct P {
    P(size_t id = 0, size_t rot = 0) : id(id), rot(rot) {}

    size_t id;
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

void solutionRec(Tableau& tab, size_t taille);

//void solutionRec(size_t idPi, size_t pos, Tableau &tab);

bool tester(size_t p1, size_t p2, const Tableau &tab);

int main() {
    Tableau tab = {P(0), P(1), P(2), P(3), P(4), P(5), P(6), P(7), P(8)};
    solutionRec(tab, tab.size() );
    //solutionRec(8, 0, tab);
    return 0;
}

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

void solutionRec(Tableau& tab, size_t taille ){
    if( taille == 1 ){
        for(size_t i = 0; i < 3; ++i)
            cout << tab[i].id;
        cout << endl;
    }else{
        for(size_t i = 0; i < taille - 1; ++i ){
            for(size_t j = 0; j < 4; ++j)
                if( tester(taille,tab) ){
                    swap(tab[i], tab[taille - 1]);
                    solutionRec( tab, taille-1);
                    swap(tab[i], tab[taille - 1]);
                }
        }
        solutionRec(tab, taille-1);
    }
}

/*
void solutionRec(size_t idPi, size_t pos, Tableau &tab) {
    // PIECES[idPi]
    tab[pos].id = idPi;
    for (int i = 0; i < 4; ++i) {
        tab[pos].rot = i;
        if(tester(pos, pos - 1, tab)&&tester(pos, pos - 3, tab)){
            solutionRec()
        }
    }
}*/

