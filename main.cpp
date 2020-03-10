#include <iostream>
#include "pieces.h"
#include <array>

using namespace std;

struct P {
    size_t id = 0;
    size_t rot = 0;
};

using Tableau = array<P, 9>;

void solutionRec(size_t idPi, size_t pos, Tableau &tab);

bool tester(size_t p1, size_t p2, const Tableau &tab);

int main() {
    Tableau tab;
    solutionRec(8, 0, tab);
    return 0;
}

void solutionRec(size_t idPi, size_t pos, Tableau &tab) {
    // PIECES[idPi]
    tab[pos].id = idPi;
    for (int i = 0; i < 4; ++i) {
        tab[pos].rot = i;
        if(tester(pos, pos - 1, tab)&&tester(pos, pos - 3, tab)){
            solutionRec()
        }
    }
}

