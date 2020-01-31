#ifndef _family_tree_
#define _family_tree_

#include <string> 

using namespace std;

#define MaxChildren 32 

typedef struct familyNodeT{
    string name;
    struct familyNodeT *children;
    struct familyNodeT *brothers;
}familyNodeT, *familyTreeT;

familyTreeT ReadFamilyTree(string filename);
void WalkingFamily(familyTreeT tree);
familyNodeT *FindNode(familyTreeT tptr, string name);
familyNodeT *FindParentNode(familyTreeT tptr, string name);
familyTreeT NewFamilyTree(string anster);
familyTreeT InsertNode(familyTreeT tptr, string name, string parent);

#endif
