//*****************************************************************************************************
//
//		File:					ArrayList.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #3
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/15/2025
//
//    This program defines the Array List class template, which is a dynamic array-based list.
//    The ArrayList class handles operations like inserting, and printing elements in the list.
//    It also provides methods for checking whether the list is empty or full.
//
//		Other files required:
//			1.	Stock.h
//      2.  ArrayList.cpp
//
//*****************************************************************************************************

#ifndef ALIST_H
#define ALIST_H
#include <iostream>
using namespace std;

//*****************************************************************************************************

template <typename T>
class ArrayList
{
private:
  T *list;
  int s;
  int numValues;

  int binarySearchRec(int first, int last, const T &item) const;

public:
  ArrayList(int size = 10);
  ~ArrayList();
  ArrayList(const ArrayList<T> &a);
  void insert(const T &a);
  bool isFull() const;
  bool isEmpty() const;
  int listSize() const;
  void print() const;
  int binarySearch(const T &item) const;
};

//*****************************************************************************************************

template <typename T>
int ArrayList<T>::binarySearchRec(int first, int last, const T &item) const
{
  int result = -1;

  if (first <= last)
  {
    int loc = (first + last) / 2;

    if ((item == list[loc]))
    {
      result = loc;
    }
    else if (list[loc] < item)
    {
      result = binarySearchRec(first, loc - 1, item);
    }
    else
    {
      result = binarySearchRec(loc + 1, last, item);
    }
  }

  return result;
}

//*****************************************************************************************************

template <typename T>
ArrayList<T>::ArrayList(int size)
{
  s = size;
  numValues = 0;
  list = new T[size];
}

//*****************************************************************************************************

template <typename T>
ArrayList<T>::~ArrayList()
{
  delete[] list;
  s = 0;
  numValues = 0;
}

//*****************************************************************************************************

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &a)
{
  s = a.s;
  numValues = a.numValues;
  list = new T[s];
  for (int i = 0; i < numValues; i++)
  {
    list[i] = a.list[i];
  }
}

//*****************************************************************************************************

template <typename T>
void ArrayList<T>::insert(const T &a)
{
  if (numValues == s)
  {
    T *newList;
    int newSize;
    newSize = s + 10;
    newList = new T[newSize];

    for (int i = 0; i < numValues; i++)
    {
      newList[i] = list[i];
    }

    delete[] list;
    list = newList;
    s = newSize;
  }

  int i = numValues - 1;
  while (i >= 0 && list[i] < a)
  {
    list[i + 1] = list[i];
    i--;
  }
  list[i + 1] = a;
  numValues++;
}

//*****************************************************************************************************

template <typename T>
int ArrayList<T>::listSize() const
{
  return numValues;
}

//*****************************************************************************************************
template <typename T>
bool ArrayList<T>::isFull() const
{
  return (numValues == s);
}
//*****************************************************************************************************

template <typename T>
bool ArrayList<T>::isEmpty() const
{
  return (numValues == 0);
}

//*****************************************************************************************************

template <typename T>
void ArrayList<T>::print() const
{
  if (isEmpty())
  {
    cout << "The list is empty\n";
  }
  else
  {
    for (int i = 0; i < numValues; i++)
    {
      cout << "[" << i << "] " << list[i] << "\t";
    }
    cout << endl;
  }
}

//*****************************************************************************************************
template <typename T>
int ArrayList<T>::binarySearch(const T &item) const
{
  int result = binarySearchRec(0, numValues - 1, item);
  return result;
}

//*****************************************************************************************************

#endif
