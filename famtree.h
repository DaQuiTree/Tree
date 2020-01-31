#ifndef _famtree_h
#define _famtree_h

#include <string>

using namespace std;

typedef struct personCDT *personADT;

personADT NewPerson(string name, personADT parent);
string GetName(personADT person);
personADT GetParent(personADT person);

int Nchildren(personADT person);
personADT IthChild(personADT person, int i);

#endif
