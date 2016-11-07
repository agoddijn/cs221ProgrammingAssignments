#include <iostream>
#include <fstream>
#include "codeTree.h"

// Print the Huffman code tree and list of codes for a given text file.

void usage() {
  std::cerr << "Usage: huftree text.txt" << std::endl;
  throw std::exception();
}

int main( int argc, char *argv[] ) {
  if( argc != 2 ) {
    usage();
  }

  int freq[256] = { 0 };	// array initialized to 0

  std::ifstream fin;
  fin.open("/Users/alexgoddijn/Documents/UBC/CPSC\ 221/Programming\ Assignments/ProgAs\ 2/moveover.txt");
  if( fin.is_open() ) {
    char ch;
    while (fin >> std::noskipws >> ch) {	// don't skip whitespace
      freq[(int)ch]++;
    }

    fin.close();
  } else if ( !fin.is_open()) {
    std::cout << "Could not open" << std::endl;
    exit(1);
  }

  codeTree ct = codeTree( freq, 256 );

  ct.printTree();
  ct.printCode();

  return 0;
}
