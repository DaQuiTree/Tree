#include "fmTree.h"

using namespace std;

int main(void)
{
    familyTreeT tree = ReadFamilyTree("normandy.dat");
    WalkingFamily(tree);

    return 0;
}
