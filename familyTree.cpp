#include <iostream>
#include <fstream>
#include <string>
#include "familyTree.h"

static familyTreeT NewFamilyTree(string anster)
{
    familyTreeT tree = new familyNodeT;

    tree->name = anster;
    for(int i = 0; i < MaxChildren; i++)
    {
        tree->children[i] = NULL;
    }

    return tree;
}

static familyNodeT *FindNode(familyTreeT tptr, string name)
{
    if(tptr == NULL)return NULL;
    if(tptr->name == name)return tptr;

    for(int i = 0; i < MaxChildren; i++)
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

    if((paTree = FindNode(tptr, parent)) != NULL){
        for(int i = 0; i < MaxChildren; i++){
            if(paTree->children[i] == NULL){
                member = new familyNodeT;
                member->name = name;
                for(int j = 0; j < MaxChildren; j++)
                    member->children[j] = NULL;
                paTree->children[i] = member;
                return;
            }
        }
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
        for(int i = 0; i < MaxChildren; i++){
            depth++;
            WalkingFamily(tree->children[i]);
            depth--;
        }
    }
}
