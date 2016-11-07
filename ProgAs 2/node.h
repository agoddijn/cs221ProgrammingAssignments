/*
* Author: Alex Goddijn
* Date: Nov 6th 2016
* File: header file for node
*/

#ifndef _NODE_
#define _NODE_

struct node {
  node( int freq, int character, node* left, node* right ) : freq(freq), character(character), leftChild(left), rightChild(right) {};
  // Integer frequency asociated with character
  int freq;
  // Integer representation of ASCII character
  int character;
  // Left and right child of node
  node* leftChild;
  node* rightChild;
};

#endif