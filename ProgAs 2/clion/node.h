#ifndef _NODE_
#define _NODE_

struct node {
  node( int freq, int character, node* left, node* right ) : freq(freq), character(character), leftChild(left), rightChild(right) {};
  int freq;
  int character;
  node* leftChild;
  node* rightChild;
};

#endif