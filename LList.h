//*****************************************************************************************************
//
//		File:					LList.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #2 Part II
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/08/2025
//
//		Other files required:
//			1. LList.cpp
//      2. Stock.h
//
//*****************************************************************************************************
#ifndef LLIST_H
#define LLIST_H

#include <iostream>

//*****************************************************************************************************

template <typename T>
class LList
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node(const T &item);
  };
  Node *first;

  Node *insertRec(Node *node, const T &item);
  Node *deleteRec(Node *node, const T &item);
  void displayRec(Node *node) const;
  void clearRec(Node *node);

public:
  LList();
  ~LList();

  void insertDesc(const T &item);
  void deleteItem(const T &item);
  void display() const;
};

//*****************************************************************************************************

template <typename T>
LList<T>::Node::Node(const T &item)
{
  data = item;
  next = nullptr;
}

//*****************************************************************************************************

template <typename T>
LList<T>::LList()
{
  first = nullptr;
}

//*****************************************************************************************************

template <typename T>
LList<T>::~LList()
{
  clearRec(first);
}

//*****************************************************************************************************

template <typename T>
typename LList<T>::Node *LList<T>::insertRec(Node *node, const T &item)
{
  if (!node || node->data < item)
  {
    Node *newNode = new Node(item);
    newNode->next = node;
    return newNode;
  }
  node->next = insertRec(node->next, item);
  return node;
}

//*****************************************************************************************************

template <typename T>
typename LList<T>::Node *LList<T>::deleteRec(Node *node, const T &item)
{
  if (!node)
    return nullptr;

  if (node->data == item)
  {
    Node *next = node->next;
    delete node;
    return next;
  }
  node->next = deleteRec(node->next, item);
  return node;
}

//*****************************************************************************************************

template <typename T>
void LList<T>::displayRec(Node *node) const
{
  if (!node)
    return;
  std::cout << node->data << std::endl;
  displayRec(node->next);
}

//*****************************************************************************************************

template <typename T>
void LList<T>::clearRec(Node *node)
{
  if (!node)
  {
    return;
  }
  clearRec(node->next);
  delete node;
}

//*****************************************************************************************************

template <typename T>
void LList<T>::insertDesc(const T &item)
{
  first = insertRec(first, item);
}

//*****************************************************************************************************
template <typename T>
void LList<T>::deleteItem(const T &item)
{
  first = deleteRec(first, item);
}

//*****************************************************************************************************

template <typename T>
void LList<T>::display() const
{
  displayRec(first);
}

//*****************************************************************************************************

#endif
