#include <iostream>
#include <fstream>
#include <string>
#include "familyTree.h"

static familyTreeT NewFamilyTree(string anster)
{
    familyTreeT tree = new familyNodeT;

    tree->name = anster;
    tree->children = NULL;
    tree->childNum = 0;

    return tree;
}

static familyNodeT *FindNode(familyTreeT tptr, string name)
{
    if(tptr->name == name)return tptr;
    for(int i = 0; i < tptr->childNum; i++)
    {
        familyNodeT *tTree;
        tTree = FindNode(tptr->children[i], name);
        if(tTree == NULL)
            continue;
        else
            return tTree;
    }

    return NULL;
}

static void InsertNode(familyTreeT tptr, string name, string parent)
{
    familyTreeT paTree;
    familyNodeT *member;
    familyNodeT **newHouse;

    if((paTree = FindNode(tptr, parent)) != NULL){
        /*new one*/
        member = new familyNodeT;
        member->name = name;
        member->children = NULL;

        /*enlarge*/
        newHouse = new familyTreeT[paTree->childNum+1];
        int i;
        for(i = 0; i < paTree->childNum; i++)
            newHouse[i] = paTree->children[i];
        newHouse[i] = member;
        delete []paTree->children;
        paTree->children = newHouse;
        paTree->childNum++;
    }
}


familyTreeT ReadFamilyTree(string filename)
{
    ifstream ifs(filename);
    string line;
    if(!ifs){
        cout << "open error" << endl;
        exit(-1);
    }

    getline(ifs, line);
    familyTreeT tree = NewFamilyTree(line);

    while(getline(ifs, line)){
        string child = line.substr(0, line.find(':'));
        string parent = line.substr(line.find(':')+1);
        cout << "child: " << child << "   parent: " << parent << endl;
        InsertNode(tree, child, parent);
    }

    return tree;
}

void WalkingFamily(familyTreeT tree)
{
    static int depth = 0;

    if(tree != NULL){
        for(int i = 0; i < 2*depth; i++)
            cout << " ";
        cout << tree->name << endl;
        for(int i = 0; i < tree->childNum; i++){
            depth++;
            WalkingFamily(tree->children[i]);
            depth--;
        }
    }
}
