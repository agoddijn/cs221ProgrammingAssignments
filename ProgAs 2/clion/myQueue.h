#ifndef MY_QUEUE
#define MY_QUEUE

#include <vector>
#include "node.h"

class myQueue {
public:
  myQueue() {};
  node* pop( void );
  void push( node* n );
  int size( void );
private:
  std::vector<node*> vec;
  void heapify( void );
  void swapDown( int i );
};

#endif