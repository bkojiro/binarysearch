#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  ~Node();
  Node* getLeft();
  Node* getRight();
  int getValue();
  void setLeft(Node* node);
  void setRight(Node* node);
  void setValue(int a);
 private:
  int value;
  Node* left;
  Node* right;
};

#endif
