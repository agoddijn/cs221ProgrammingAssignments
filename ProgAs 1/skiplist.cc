/*
skiplist class
Author - Alex Goddijn v1c9
Date - Oct 13th 2016
*/

#include "skiplist.h"
#include <iostream>

skiplist::skiplist() {
  head = new wordNode();
}

Word* skiplist::find(std::string word) {
  wordNode* node = head;
  int h = (node->height) - 1;
  while(h >= 0) {
    while((node->next[h] != NULL) && (node->next[h]->data->word < word)) {
      node = node->next[h];
    }
    if ((node->next[h] != NULL) && (node->next[h]->data->word.compare(word) == 0)) return node->next[h]->data;
    update[h] = node;
    h--;
  }
  return NULL;
}

void skiplist::insert(std::string wordToInsert, int pageNum) {
  Word* inList = find(wordToInsert);
  //Word is not in list
  if(!inList) {
    wordNode* node = new wordNode(wordToInsert);
    inList = node->data;
    for (int h = 0; h < node->height; ++h) {
      node->next[h] = update[h]->next[h];
      update[h]->next[h] = node;
    }
  }
  //Word is now in the list
  incOccurence(inList);
  addToPages(inList, pageNum);
}

void skiplist::printInOrder() {
  wordNode* node = head->next[0];
  while(node) {
    Word* toPrint = node->data;
    std::string pages = formatPages(toPrint); //Format the pages vector
    std::cout << toPrint->word << " (" << toPrint->occurence << ") " << pages << std::endl;
    node = node->next[0];
  }
}

//Format the page numbers correctly
std::string skiplist::formatPages(Word* pWord) {
  std::vector<int> list = pWord->listOfPages; //Copy of the listOfPages vector
  std::string toReturn = std::to_string(list.at(0)); //Initialize new string with first page number
  for(int i = 1; i < list.size(); i++){
      int prevPage = list.at(i-1); //Previous page number
      int curPage = list.at(i); //Current page number
      //These two pages are consecutive
      if(curPage == (prevPage + 1)){
          if(toReturn.back() != '-') toReturn.append("-"); //If - is not already there put one in
          if(i == list.size() - 1) toReturn.append(std::to_string(curPage)); //We are at the end
      }
      //These two pages are not consecutive
      else {
          if(i == 1) toReturn.append(", " + std::to_string(curPage));
          else toReturn.append(std::to_string(prevPage) + ", " + std::to_string(curPage)); //Next non consec page
      }
  }
  return toReturn;
}