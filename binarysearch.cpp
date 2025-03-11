#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"

using namespace std;

void insert(Node* &current, int a);
void print(Node* current, int depth);

int main() {
  Node* root;
  bool active = true;
  while(active) {
    cout << "Enter INSERT, REMOVE, PRINT, SEARCH, or QUIT" << endl << "> ";
    char action[10];
    cin.get(action, 11);
    cin.ignore();
    if (strcmp(action, "INSERT") == 0) {
      //ask either by console or file
      cout << "Insert by console ('c') or file ('f')?" << endl << "> ";
      char in;
      cin >> in;
      cin.ignore();
      if (in == 'c') {
	//insert by console
	cout << "Enter a number" << endl << "> ";
	int a;
	cin >> a;
	cin.ignore();
	if (root->getValue() == 0) {
	  root->setValue(a);
	} else {
	  insert(root, a);
	}
      } else if (in == 'f') {
	//insert by file
	ifstream numbers;
	numbers.open("numbers.txt");
	int x;
	while (numbers >> x) {
	  //insert x into tree
	  if (root->getValue() == 0) {
	    root->setValue(x);
	  } else {
	    insert(root, x);
	  }
	}
      }
    } else if (strcmp(action, "REMOVE") == 0) {
      //remove a number covering the three cases + deleting root
      
    } else if (strcmp(action, "PRINT") == 0) {
      //visualization of tree
      print(root, 0);
    } else if (strcmp(action, "SEARCH") == 0) {
      //see if tree has a number
      
    } else if (strcmp(action, "QUIT") == 0) {
      //terminate program
      active = false;
    }
  }
  return 0;
}

void insert(Node* &current, int a) {
  if (a >= current->getValue()) {
    //go to right if greater/equal to current
    if (current->getRight() != NULL) {
      current = current->getRight();
      insert(current, a);
    } else {
      current->setRight(new Node(a));
    }
  } else if (a < current->getValue()) {
    //go to left!
    if (current->getLeft() != NULL) {
      current = current->getLeft();
      insert(current, a);
    } else {
      current->setLeft(new Node(a));
    }
  }
}

void print(Node* current, int depth) {
  if (current->getRight() != NULL) {
    print(current->getRight(), depth + 1);
  }
  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  cout << current->getValue() << endl;
  if (current->getLeft() != NULL) {
    cout << "worked";
    print(current->getLeft(), depth + 1);
  }
}
