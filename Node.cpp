#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
  value = 0;
  left = NULL;
  right = NULL;
}

Node::~Node() {
  value = 0;
  left = NULL;
  right = NULL;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

int Node::getValue() {
  return value;
}

void Node::setLeft(Node* node) {
  left = node;
}

void Node::setRight(Node* node) {
  right = node;
}

void Node::setValue(int a) {
  value = a;
}
