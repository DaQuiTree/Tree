#ifndef _family_tree_
#define _family_tree_

#include <string> 

using namespace std;

#define MaxChildren 32 

typedef struct familyNodeT{
    string name;
    struct familyNodeT *children[MaxChildren];
}familyNodeT, *familyTreeT;

familyTreeT ReadFamilyTree(string filename);
void WalkingFamily(familyTreeT tree);

#endif
