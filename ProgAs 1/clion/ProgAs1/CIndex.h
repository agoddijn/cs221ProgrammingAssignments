/*
CIndex class
Author - Alexander Goddijn v1c9
Date - Oct 3rd 2016
*/

#ifndef _C_INDEX_
#define _C_INDEX_

#include "Word.h"
#include <string>
#include <vector>

class CIndex
{
public:
    CIndex(void); //Creates CIndex object
    void insert(std::string word, int pageNum); //Insert word into structure
    Word* find(std::string word); //Returns a Word corresponding to the given word
    void printInOrder();

private:
    std::vector<Word*> wordList;
    std::string formatPages(Word* pWord);

};

#endif