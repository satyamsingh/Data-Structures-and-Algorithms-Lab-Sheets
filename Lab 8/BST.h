#ifndef ELEMENT_H

#define ELEMENT_H
struct element{
int value;
};
typedef struct element* Element;
#endif

#define BST_H

struct bst;
typedef struct bst* Bst;
struct bst{
Bst left;
Bst right;
Element e;
int height;
};

Bst addB(Bst b, Element e);
Bst create(Element e);
Bst deleteB(Bst b, Element e);
Element find(Bst b, Element e);
int getHeight(Bst b);
void visualizeBst(Bst b);
