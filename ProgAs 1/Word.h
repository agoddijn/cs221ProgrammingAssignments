/*
Word struct
Author - Alexander Goddijn v1c9
Date - Oct 3rd 2016
*/

#ifndef _WORD_
#define _WORD_

#include <string>
#include <vector>

struct Word {
  std::string word;
  int occurence;
  std::vector<int> listOfPages;
  Word(std::string wordInit): word(wordInit), occurence(0){};
};

//Function declarations
void addToPages(Word* pWord, int pageNum);
void incOccurence(Word* pWord);
bool isPageInList(Word* pWord, int pageNum); //returns true if page already exists

#endif