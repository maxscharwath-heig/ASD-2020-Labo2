#include <iostream>
#include "pieces.h"
#include <array>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

struct P {
    size_t id  = 0;
    size_t rot = 0;
};

using Tableau = array<size_t , 3>;

void solutionRec(Tableau& tab, size_t taille);

//void solutionRec(size_t idPi, size_t pos, Tableau &tab);

//bool tester(size_t p1, size_t p2, const Tableau &tab);

int main() {
    Tableau tab = {1,3,5};
    solutionRec(tab, tab.size() );
    //solutionRec(8, 0, tab);
    return 0;
}



void solutionRec(Tableau& tab, size_t taille ){
    if( taille == 1 ){
        for(size_t i = 0; i < 3; ++i)
            cout << tab[i];
        cout << endl;
    }else{
        for(size_t i = 0; i < taille - 1; ++i ){

            swap(tab[i], tab[taille - 1]);
            solutionRec( tab, taille-1);
            swap(tab[i], tab[taille - 1]);
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

