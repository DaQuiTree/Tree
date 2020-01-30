#ifndef _family_tree_
#define _family_tree_

#include <string> 

using namespace std;

#define MaxChildren 32 

typedef struct familyNodeT{
    string name;
    int childNum;
    struct familyNodeT **children;
}familyNodeT, *familyTreeT;

familyTreeT ReadFamilyTree(string filename);
void WalkingFamily(familyTreeT tree);

#endif
