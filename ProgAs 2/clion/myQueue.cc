#include "myQueue.h"
#include <assert.h>

void myQueue::push( node* n ) {
  vec.push_back(n);
  heapify();
}

node* myQueue::pop() {
  node* toReturn = vec.front();
  std::swap(vec.front(), vec.back());
  vec.pop_back();
  heapify();
  return toReturn;
}

void myQueue::heapify() {
  int size = vec.size();
  for (int i = (size - 2) / 2; i >= 0; i--) {
    swapDown(i);
  }
}

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

int myQueue::size() {
  return vec.size();
}