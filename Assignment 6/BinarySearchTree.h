//*****************************************************************************************************
//
//		File:					BinarySearchTree.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					10/06/2025
//
//    This header file defines the template class of Binary Search Tree.
//
//*****************************************************************************************************

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
struct Node
{
  T value;
  Node<T> *left;
  Node<T> *right;
};

//*****************************************************************************************************

template <typename T>
int max(int a, int b)
{
  return (a > b) ? a : b;
}

//*****************************************************************************************************

template <typename T>
class BinarySearchTree
{
private:
  Node<T> *root;
  int height(Node<T> *r) const;
  void destroy(Node<T> *&r);
  void insert(Node<T> *&r, const T &item);
  void inorder(Node<T> *r, std::ostream &os) const;
  void preorder(Node<T> *r, std::ostream &os) const;
  void postorder(Node<T> *r, std::ostream &os) const;
  T *search(Node<T> *r, const T &item) const;

public:
  BinarySearchTree();
  ~BinarySearchTree();
  int height() const;
  void destroy();
  void insert(const T &item);
  void inorder() const;
  void preorder() const;
  void postorder() const;
  T *search(const T &item) const;

  void inorder(std::ostream &os) const { inorder(root, os); }
};

//*****************************************************************************************************

template <typename T>
int BinarySearchTree<T>::height(Node<T> *root) const
{
  if (root == nullptr)
  {
    return 0;
  }
  else
  {
    return 1 + max(height(root->left), height(root->right));
  }
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::destroy(Node<T> *&r)
{
  if (r != nullptr)
  {
    destroy(r->left);
    destroy(r->right);
    delete r;
    r = nullptr;
  }
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::insert(Node<T> *&r, const T &item)
{
  if (r == nullptr)
  {
    r = new Node<T>;
    r->value = item;
    r->left = nullptr;
    r->right = nullptr;
  }

  //*****************************************************************************************************

  else if (item < r->value)
  {
    insert(r->left, item);
  }
  else if (item > r->value)
  {
    insert(r->right, item);
  }
  else
  {
    std::cout << "Duplicate";
  }
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::inorder(Node<T> *r, std::ostream &os) const
{
  if (r != nullptr)
  {
    inorder(r->left, os);
    os << r->value << std::endl;
    inorder(r->right, os);
  }
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::preorder(Node<T> *r, std::ostream &os) const
{
  if (r != nullptr)
  {
    os << r->value << std::endl;
    preorder(r->left, os);
    preorder(r->right, os);
  }
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::postorder(Node<T> *r, std::ostream &os) const
{
  if (r != nullptr)
  {
    postorder(r->left, os);
    postorder(r->right, os);
    os << r->value << std::endl;
  }
}

//*****************************************************************************************************

template <typename T>
T *BinarySearchTree<T>::search(Node<T> *r, const T &item) const
{
  T *result;
  if (r == nullptr)
  {
    result = nullptr;
  }
  else if (item < r->value)
  {
    result = search(r->left, item);
  }
  else if (item > r->value)
  {
    result = search(r->right, item);
  }
  else
  {
    result = new T(r->value);
  }
  return result;
}

//*****************************************************************************************************

// public functions

template <typename T>
int BinarySearchTree<T>::height() const
{
  return height(root);
}

//*****************************************************************************************************

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
  root = nullptr;
}

//*****************************************************************************************************

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
  destroy(root);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::destroy()
{
  destroy(root);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::insert(const T &item)
{
  insert(root, item);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::inorder() const
{
  inorder(root, std::cout);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::preorder() const
{
  preorder(root, std::cout);
}

//*****************************************************************************************************

template <typename T>
void BinarySearchTree<T>::postorder() const
{
  postorder(root, std::cout);
}

//*****************************************************************************************************

template <typename T>
T *BinarySearchTree<T>::search(const T &item) const
{
  return search(root, item);
}

//*****************************************************************************************************

#endif
