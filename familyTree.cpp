#include <iostream>
#include <fstream>
#include <string>
#include "familyTree.h"

static familyTreeT NewFamilyTree(string anster)
{
    familyTreeT tree = new familyNodeT;

    tree->name = anster;
    tree->children = NULL;
    tree->brothers = NULL;

    return tree;
}

static familyNodeT *FindNode(familyTreeT tptr, string name)
{
    if(tptr == NULL)return NULL;
    if(tptr->name == name)return tptr;
    familyNodeT *tTree;
    tTree = FindNode(tptr->children, name);
    if(tTree == NULL)
        return(FindNode(tptr->brothers, name));
    else
        return tTree;
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
        member->brothers = NULL;
        
        /*parents have children already*/
        if(paTree->children != NULL){
            familyNodeT *endBro = paTree->children;
            while(endBro->brothers != NULL) 
                endBro = endBro->brothers;
            endBro->brothers = member;
        }else{
            paTree->children = member;
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

    while(getline(ifs, line)){ string child = line.substr(0, line.find(':'));
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
        WalkingFamily(tree->brothers);
        depth++;
        WalkingFamily(tree->children);
        depth--;
    }
}
