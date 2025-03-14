#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"

using namespace std;

void insert(Node* &current, int a);
void print(Node* current, int depth);
void search(Node* current, int x);
void remove(Node* current, Node* root, int x);

int main() {
  Node* root = new Node();
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
	  insert(root, x);
	}
      }
    } else if (strcmp(action, "REMOVE") == 0) {
      //remove a number covering the three cases + deleting root
      cout << "What number would you like to remove?" << endl << "> ";
      int x;
      cin >> x;
      cin.ignore();
      remove(root, root, x);
    } else if (strcmp(action, "PRINT") == 0) {
      //visualization of tree
      print(root, 0);
    } else if (strcmp(action, "SEARCH") == 0) {
      //see if tree has a number
      cout << "What number would you like to search for?" << endl << "> ";
      int x;
      cin >> x;
      cin.ignore();
      search(root, x);
    } else if (strcmp(action, "QUIT") == 0) {
      //terminate program
      active = false;
    }
  }
  return 0;
}

void insert(Node* &current, int a) {
  if (current->getValue() == 0) {
    current->setValue(a);
  } else if (a >= current->getValue()) {
    //go to right if greater/equal to current
    if (current->getRight() != NULL) {
      Node* right = current->getRight();
      insert(right, a);
    } else {
      Node* temp = new Node();
      temp->setValue(a);
      current->setRight(temp);
    }
  } else if (a < current->getValue()) {
    //go to left!
    if (current->getLeft() != NULL) {
      Node* left = current->getLeft();
      insert(left, a);
    } else {
      Node* temp = new Node();
      temp->setValue(a);
      current->setLeft(temp);
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
    print(current->getLeft(), depth + 1);
  }
}

void search(Node* current, int x) {
  if (current != NULL) { 
    if (current->getValue() == x) {
      cout << "Number found" << endl;
    } else if (x >= current->getValue()) {
      search(current->getRight(), x);
    } else if (x < current->getValue()) {
      search(current->getLeft(), x);
    }
  } else {
    cout << "Number not found" << endl;
  }
}

void remove(Node* &current, Node* root, int x) {
  if (current != NULL) {
    if (current->getValue() == x) {
      if (current == root) { //replace root with next highest

      } else if (current->getRight() != NULL && current->getLeft() != NULL) { //two children!

      } else { //one child
        if (current->getRight() != NULL) {
          current = current->getRight();
        }
      } 
    } else if (x >= current->getValue()) {
      remove(current->getRight(), x);
    } else if (x < current->getValue()) {
      search(current->getLeft(), x);
    }
  } else {
    cout << "Number not found" << endl;
  }
}
