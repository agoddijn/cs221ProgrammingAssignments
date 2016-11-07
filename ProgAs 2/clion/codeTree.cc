#include <iostream>
#include "codeTree.h"

codeTree::codeTree( int freq[], int size ) {
  for (int i = 0; i < size; i++) {
    if(freq[i] > 0) {
      node *n = new node(freq[i], i, NULL, NULL);
      q.push(n);
    }
  }
  root = makeTree();
}

node* codeTree::makeTree() {
  while (q.size() >= 2) {
    node* n1 = q.pop();
    node* n2 = q.pop();
    node* parent = new node(n1->freq + n2->freq, -1, n1, n2);
    q.push(parent);
  }
  return q.pop();
}

void codeTree::printChar( int ch ) {
  if( ch < 16 ) {
    std::cout << "x0" << std::hex << ch;
  } else if( ch < 32 || ch > 126 ) {
    std::cout << "x" << std::hex << ch;
  } else {
    std::cout << "\"" << (char)ch << "\"";
  }
}


void codeTree::printCode() {
  printCodeRecur(root, "");
}

void codeTree::printCodeRecur( node* root, std::string path) {
  if(root->leftChild == NULL && root->rightChild == NULL) {
    printChar(root->character);
    std::cout << ":" << path << std::endl;
    return;
  }
  printCodeRecur(root->leftChild, path+="0");
  path = path.substr(0, path.length()-1);
  printCodeRecur(root->rightChild, path+="1");
}

void codeTree::printTree() {
  printTreeRecur(root, "");
}

void codeTree::printTreeRecur( node* root, std::string path) {
  if(root->leftChild == NULL && root->rightChild == NULL) {
    printChar(root->character);
    std::cout << "\n";
    return;
  }
  std::cout << ".\n" + path + "|'1-";
  printTreeRecur(root->rightChild, path += "|   ");
  std::cout << path + "\n";
  path = path.substr(0, path.length() - 4);
  std::cout << path + "'-0-";
  printTreeRecur(root->leftChild, path += "    ");
}
