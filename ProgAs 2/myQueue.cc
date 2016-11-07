/*
* Author: Alex Goddijn
* Date: Nov 6th 2016
* File: cpp file for myQueue
*/

#include "myQueue.h"
#include <assert.h>

// Put node pointer into queue
void myQueue::push( node* n ) {
  // Put node pointer into vector then heapify vector
  vec.push_back(n);
  heapify();
}

// Deletes highest priority node and deletes it, returning pointer to it
node* myQueue::pop() {
  // Vector is heapified. highest priority is root (in min heap)
  node* toReturn = vec.front();
  // Swap front and back, makes it easier to delete using pop_back() method
  std::swap(vec.front(), vec.back());
  // remove node pointer from vec
  vec.pop_back();
  // Make sure vector is heap afterwards
  heapify();
  return toReturn;
}

// Turn vector into min heap
void myQueue::heapify() {
  int size = vec.size();
  for (int i = (size - 2) / 2; i >= 0; i--) {
    swapDown(i);
  }
}

// Recursive swapdown algorithm given in class
void myQueue::swapDown( int i ) {
  int size = vec.size();
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;
  int min = i;
  if (leftChild < size && vec.at(leftChild)->freq < vec.at(min)->freq)
    min = leftChild;
  if (rightChild < size && vec.at(rightChild)->freq < vec.at(min)->freq)
    min = rightChild;
  if (min != i) {
    std::swap(vec.at(i), vec.at(min));
    swapDown(min);
  }
}

// Returns size of queue
int myQueue::size() {
  return vec.size();
}