/*
wordNode Class
Author - Alex Goddijn v1c9
Date - Oct 13th 2016
*/

#ifndef _WORD_NODE_
#define _WORD_NODE_

#include "Word.h"

const int MAX_HEIGHT = 20;

struct wordNode
{
  wordNode** next; //Next list
  Word* data; //Word
  int height;
  wordNode(void); //Creates dummy node
  wordNode(std::string wordInit); //Creates node with wordInit
};

//Function declarations
int randBit(void);
int genHeight(void);
void setArray(wordNode* next[], int height);

#endif