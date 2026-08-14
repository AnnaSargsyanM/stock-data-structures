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
