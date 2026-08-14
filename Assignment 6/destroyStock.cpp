//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #6 Part III
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					10/06/2025
//
//		This is a .cpp file for destroying Binary Search Tree.
//
//*****************************************************************************************************

#include <iostream>
#include <cstdlib>
#include "Stock.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
  BinarySearchTree<int> intTree;

  for (int i = 0; i < 10; ++i)
  {
    int value = (rand() % 5000) + 1;
    intTree.insert(value);
  }

  cout << "Integer Binary Search Tree Traversals" << endl;
  cout << "Inorder: " << endl;
  intTree.inorder();
  cout << "Preorder: " << endl;
  intTree.preorder();
  cout << "Postorder: " << endl;
  intTree.postorder();
  cout << endl;

  cout << "Height of integer Binary Search Tree: " << intTree.height() << endl
       << endl;

  intTree.destroy();
  cout << "Integer Binary Search Tree destroyed." << endl
       << endl;

  return 0;
}

//*****************************************************************************************************

/*
Integer Binary Search Tree Traversals
Inorder:
1523
2394
3114
3346
3755
3926
3929
4367
4407
4819
Preorder:
4407
3926
1523
3114
2394
3346
3755
3929
4367
4819
Postorder:
2394
3755
3346
3114
1523
4367
3929
3926
4819
4407

Height of integer Binary Search Tree: 6

Integer Binary Search Tree destroyed.
*/
