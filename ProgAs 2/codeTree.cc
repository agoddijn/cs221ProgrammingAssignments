/*
* Author: Alex Goddijn
* Date: Nov 6th 2016
* File: cpp file for codeTree
*/

#include <iostream>
#include "codeTree.h"

// Create a code tree given frequency array and size of said array
codeTree::codeTree( int freq[], int size ) {
  // Double check that array pointer is not null and size is not 0
  if(freq == NULL || size == 0) return;
  for (int i = 0; i < size; i++) {
    // Only create node if frequency is greater than 0
    if(freq[i] > 0) {
      // Create a new node with correct frequency and character, but no children
      node *n = new node(freq[i], i, NULL, NULL);
      // Push node into priority queue
      q.push(n);
    }
  }
  // One all nodes are in priority queue, make the tree
  root = makeTree();
}

// Creates code tree and return pointer to root of tree
node* codeTree::makeTree() {
  // While there are at least 2 nodes in the priority queue
  while (q.size() >= 2) {
    // Get the top two nodes (highest priority means lowest frequency)
    node* n1 = q.pop();
    node* n2 = q.pop();
    // Create a parent node with frequency sum of childrens frequencies
    // Set character to -1 (could use to show this isn't a leaf)
    // Set the children of the node to the two nodes from priority queue
    node* parent = new node(n1->freq + n2->freq, -1, n1, n2);
    // Push parent back into queue
    q.push(parent);
  }
  // Only one node left on queue, must be root node. return root node
  return q.pop();
}

// Given printChar method
void codeTree::printChar( int ch ) {
  if( ch < 16 ) {
    std::cout << "x0" << std::hex << ch;
  } else if( ch < 32 || ch > 126 ) {
    std::cout << "x" << std::hex << ch;
  } else {
    std::cout << "\"" << (char)ch << "\"";
  }
}

// Prints the code for each letter
void codeTree::printCode() {
  // Makes call to recursive implementation of printCode
  printCodeRecur(root, "");
}

// Recursive printCode implementation
void codeTree::printCodeRecur( node* root, std::string path) {
  // Base case, root is a leaf node and so has a character
  if(root->leftChild == NULL && root->rightChild == NULL) {
    printChar(root->character);
    std::cout << ":" << path << std::endl;
    return;
  }
  // Check left child and add 0 to code
  printCodeRecur(root->leftChild, path+="0");
  // Extra 0 on end of code, remove
  path = path.substr(0, path.length()-1);
  // Check right child and add 1 to code
  printCodeRecur(root->rightChild, path+="1");
}

// Prints the code tree
void codeTree::printTree() {
  // Call to recursive print tree implementation
  printTreeRecur(root, "");
}

// Recursive print tree implementation
void codeTree::printTreeRecur( node* root, std::string path) {
  // Base case, root is a leaf and so has a character
  if(root->leftChild == NULL && root->rightChild == NULL) {
    printChar(root->character);
    std::cout << "\n";
    return;
  }
  // Print so it looks like tree in pdf
  std::cout << ".\n" + path + "|'1-";
  // Check right child and add "|   " to path
  printTreeRecur(root->rightChild, path += "|   ");
  // To make it pretty
  std::cout << path + "\n";
  // Remove the extra 4 characters
  path = path.substr(0, path.length() - 4);
  // Print so it looks like tree in pdf
  std::cout << path + "'-0-";
  // Checl left child and add "    " to path
  printTreeRecur(root->leftChild, path += "    ");
}
