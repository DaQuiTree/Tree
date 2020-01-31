#include <string>
#include "famtree.h"
#include "familyTree.h"

using namespace std;

struct personCDT{
    familyTreeT tree;
};

personADT NewPerson(string name, personADT parent)
{
    personADT family = new personCDT;
    if(parent == NULL){
        family->tree = NewFamilyTree(name);
        return (family);
    }

    family->tree = InsertNode(parent->tree, name, parent->tree->name);

    return family;
}

string GetName(personADT person)
{
    return(person->tree->name);
}

personADT GetParent(personADT person)
{
}

int Nchildren(personADT person)
{
    int cnt = 0;
    /*no child*/
    familyTreeT ptree = person->tree;
    if(ptree->children == NULL)
        return 0;

    /*any child*/
    do{
        cnt++;
        ptree = ptree->children;
    }while(ptree->brothers != NULL);

    return cnt;
}

personADT IthChild(personADT person, int i)
{
    familyTreeT ptree = person->tree->children;
    do{
        i--;
        ptree = ptree->brothers;
    }while(ptree != NULL && i);

    personADT family = new personCDT;
    family->tree = ptree;

    return family;
}

