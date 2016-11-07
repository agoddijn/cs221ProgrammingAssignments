/*
* Author: Alex Goddijn
* Date: Nov 6th 2016
* File: header file for myQueue
*/

#ifndef MY_QUEUE
#define MY_QUEUE

#include <vector>
#include "node.h"

class myQueue {
public:
  myQueue() {}; // Constructor
  node* pop( void ); // Deletes highest priority node and deletes it, returning pointer to it
  void push( node* n ); // Put node in queue
  int size( void ); // Return size of the queue
private:
  std::vector<node*> vec; // Underlying data structure
  void heapify( void ); // Heapify algorithm for min heap
  void swapDown( int i ); // recursive swapdown implementation
};

#endif