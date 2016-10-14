/*
Skiplist Class
Author - Alex Goddijn v1c9
Date - October 13th 2016
*/

#ifndef _SKIPLIST_
#define _SKIPLIST_

#include "wordNode.h"
#include "Word.h"
#include <string>

class skiplist
{
public:
  skiplist(void); //Creates CIndex object
  Word* find(std::string word); //Returns a Word corresponding to the given word
  void insert(std::string wordToInsert, int pageNum); //Insert word into structure
  void printInOrder(void);

private:
  wordNode* head;
  wordNode* update[MAX_HEIGHT];
  std::string formatPages(Word* pWord);
};

#endif