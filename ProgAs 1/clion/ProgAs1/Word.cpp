/*
Word class definitions
Author - Alexander Goddijn v1c9
Date - Oct 3rd 2016
*/

#include "Word.h"

/*
Add pageNum to pWord->listOfPages
Must be added in order without duplicates
*/
void addToPages(Word* pWord, int pageNum) {
  std::vector<int>* list = &pWord->listOfPages;
  //List is empty
  if(list->size() == 0) {
    list->push_back(pageNum);
    return;
  }
  //List is not empty and pageNum is not in list
  if(!isPageInList(pWord, pageNum)) {
    //Same insert algorithm as CIndex.cc
    for(auto it = list->begin(); it != list->end(); ++it){
      if(*it > pageNum){
        list->insert(it,pageNum);
        break;
      }
      if((it+1) == list->end()){
        list->push_back(pageNum);
        break;
      }
    }
  }
}

/*
Search for pageNum in pWord->listOfPages
If the page exists returns true
Otherwise returns false
Binary search algorithm
*/
bool isPageInList(Word* pWord, int pageNum) {
  std::vector<int>* list = &pWord->listOfPages;
  int l = 0;
  int r = list->size() - 1;
  int mid;
  while(l <= r) {
    mid = l + (r-l)/2;
    int num = list->at(mid);
    if(num == pageNum) {
      return true;
    } else if (pageNum < num) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return false;
}

//Increase pWord->occurence
void incOccurence(Word* pWord) {
  pWord->occurence = pWord->occurence + 1;
  return;
}