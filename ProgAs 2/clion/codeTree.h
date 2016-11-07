/*
* Author: Alex Goddijn
* Date: Nov 4th 2016
* File: header file for codeTree
*/

#ifndef CODE_TREE
#define CODE_TREE

#include "node.h"
#include "myQueue.h"

class codeTree {
public:
  codeTree( int freq[], int size ); // Constructor
  void printTree( void ); // Prints the codetree
  void printCode( void ); // Prints the code for each character
private:
  void printChar( int ch ); // Given printChar method
  node* makeTree( void ); //Make the tree from priority queue
  myQueue q;
  node* root;
  void printCodeRecur( node* root, std::string path );
  void printTreeRecur( node* root, std::string path );
};

#endif
