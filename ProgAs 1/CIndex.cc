/*
CIndex class
Author - Alexander Goddijn v1c9
Date - Oct 3rd 2016
*/

#include "CIndex.h"
#include <iostream>

//Constructor
CIndex::CIndex(){
    std::vector<Word*> wordList;
}

//Binary search algorithm of vector
Word* CIndex::find(std::string toFind){
    int r = wordList.size() - 1;
    int l = 0;
    int m;

    while(l <= r) {
        m = l + (r - l)/2;
        std::string wordAtMid = wordList.at(m)->word;
        if(wordAtMid.compare(toFind) == 0) {
            return wordList.at(m);
        } else if(wordAtMid > toFind) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return NULL;
}

/*
Insert given word into index
If word exists, increase its occurence and add the page number
If not, insert it into the list in the appropriate place then increase
    its occurence and add the page number
*/
void CIndex::insert(std::string wordToInsert, int pageNum){
    Word* inList = find(wordToInsert);
    //Word to insert is not in the list
    if(!inList) {
        inList = new Word(wordToInsert); //Create the new word
        //wordList is not empty
        if(wordList.size() != 0) {
            Word* pWord;
            for(auto it = wordList.begin(); it != wordList.end(); ++it){ //Iterate through wordList
                pWord = *it; //pWord is pointer to the word in the list
                //Found next word that is alphabetically larger
                if(pWord->word > wordToInsert) {
                    wordList.insert(it, inList); //Insert alphabetically smaller word before larger one
                    break;
                }
                //We are at the end of the list without having found a larger word
                if((it+1) == wordList.end()){
                    wordList.push_back(inList); //Put this word at the end of the list
                    break;
                }
            }
        }
        //wordList is empty
        else {
            wordList.push_back(inList); //Add word to empty list
        }
    }
    //Word is now in the list
    incOccurence(inList); //Increment occurence
    addToPages(inList, pageNum); //Add page number
}

//Print all in order
void CIndex::printInOrder(){
    for(int i = 0; i < wordList.size(); i++){
        Word* toPrint = wordList.at(i);
        std::string pages = formatPages(toPrint); //Format the pages vector
        std::cout << toPrint->word << " (" << toPrint->occurence << ") " << pages << std::endl;
    }
}

//Format the page numbers correctly
std::string CIndex::formatPages(Word* pWord) {
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
