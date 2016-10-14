/*
wordNode Class
Author - Alex Goddijn v1c9
Date - Oct 13th 2016
*/

#include "wordNode.h"
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX

//Return a random bit
int randBit(void) {
  srand(time(0));
  static int bitsUpperBd=0;
  static int bits;
  if( bitsUpperBd == 0 ) {
    bitsUpperBd = RAND_MAX;
    bits = rand();
  }
  int b = bits & 1;
  bits >>= 1;
  bitsUpperBd >>= 1;
  return b;
}

//Generate random height between 1 and MAX_HEIGHT
int genHeight(void) {
    int i;
  for( i=1; i<MAX_HEIGHT; ++i ) {
    if( randBit() == 1 ) break;
  }
  return i;
}

//Create dummy node
wordNode::wordNode(void) {
  data = NULL;
  next = new wordNode* [MAX_HEIGHT];
  height = MAX_HEIGHT;
  setArray(next, height);
}

//Create word node
wordNode::wordNode(std::string wordInit) {
  data = new Word(wordInit);
  int h = genHeight();
  next = new wordNode* [h];
  height = h;
  setArray(next, height);
}

//Set all elements of next to null
void setArray(wordNode* next[], int height) {
  for(int h = 0; h < height; h++) {
    next[h] = NULL;
  }
}