#include <iostream>
#include "pieces.h"
#include <array>

using namespace std;

struct P{
    size_t id;
    size_t rot;
};

using Tableau = array<P,9>;

void solutionRec(P pi, size_t pos, Tableau tab);

bool tester(P pi, const Tableau& tab);

int main() {

    return 0;
}

void solutionRec(P pi, size_t pos, Tableau tab){


}
