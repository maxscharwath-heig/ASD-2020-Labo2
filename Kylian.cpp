#include <iostream>
#include "pieces.h"
#include <array>
#include <utility>
#include <string>

using namespace std;

/*--------------------------------------------------------------------------------*/

struct PieceEntity {
    PieceEntity(size_t id, size_t rot = 0) : id(id), rot(rot) {}

    size_t id;
    size_t rot;

    Piece getPiece() const;
    AttachementType getAttachement(size_t r = 0) const;
    string getCode();
};

using Tableau = array<PieceEntity, 9>;

void solutionRec(Tableau& tab, size_t taille, size_t largeur, size_t hauteur);
bool tester(size_t p, const Tableau &tab, size_t largeur, size_t hauteur);

/*--------------------------------------------------------------------------------*/

int main() {
    const unsigned HAUTEUR = 3,
                   LARGEUR = 3;

    Tableau tab = {PieceEntity(0), PieceEntity(1), PieceEntity(2),
                   PieceEntity(3), PieceEntity(4), PieceEntity(5),
                   PieceEntity(6), PieceEntity(7), PieceEntity(8)};

    solutionRec(tab, tab.size(), LARGEUR, HAUTEUR);

    return EXIT_SUCCESS;
}

/*--------------------------------------------------------------------------------*/

Piece PieceEntity::getPiece() const {
    return PIECES[id];
}

AttachementType PieceEntity::getAttachement(size_t r) const {
    return getPiece()[(rot + r) % 4];
}

string PieceEntity::getCode() {
    char v = 'a' + rot;
    return to_string(id + 1) + v;
}

/*--------------------------------------------------------------------------------*/

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

bool tester(size_t p, const Tableau &tab, size_t largeur, size_t hauteur) {
    if (p / hauteur != hauteur - 1) {
        if (!checkAttachement(tab[p].getAttachement(2), tab[p + largeur].getAttachement(0)))
            return false;
    }
    if (p % largeur != largeur - 1) {
        if (!checkAttachement(tab[p].getAttachement(1), tab[p + 1].getAttachement(3)))
            return false;
    }
    return true;
}

void solutionRec(Tableau& tab, size_t taille, size_t largeur, size_t hauteur){
    if( taille == 0 ){
        for(size_t i = 0; i < largeur*hauteur; ++i)
            cout << tab[i].getCode() << " ";
        cout << endl;
    }else{
        for(size_t i = 0; i < taille ; ++i ){
            for( ; tab[i].rot < 4; ++tab[i].rot) {
                swap(tab[i], tab[taille - 1]);
                if (tester(taille - 1, tab, largeur, hauteur)) {
                    solutionRec(tab, taille - 1, largeur, hauteur);
                }
                swap(tab[i], tab[taille - 1]);
            }
            tab[i].rot = 0;
        }
    }
}