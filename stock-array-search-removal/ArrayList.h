#ifndef ALIST_H
#define ALIST_H
#include <iostream>
using namespace std;

template <typename T>
class ArrayList
{
private:
  T *list;
  int s;
  int numValues;

  int binarySearchDescRec(int first, int last, const T &item) const;
  int binarySearchAscRec(int first, int last, const T &item) const;

public:
  ArrayList(int size = 10);
  ~ArrayList();
  ArrayList(const ArrayList<T> &a);
  void insert(const T &a);
  bool isFull() const;
  bool isEmpty() const;
  int listSize() const;
  void print() const;
  void print(ostream &out) const;
  int binarySearch(const T &item) const;
  bool remove(const T &s);
  bool removeRange(int a, int b);
};

template <typename T>
int ArrayList<T>::binarySearchDescRec(int first, int last, const T &item) const
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
      result = binarySearchDescRec(first, loc - 1, item);
    }
    else
    {
      result = binarySearchDescRec(loc + 1, last, item);
    }
  }

  return result;
}

template <typename T>
int ArrayList<T>::binarySearchAscRec(int first, int last, const T &item) const
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
      result = binarySearchAscRec(loc + 1, last, item);
    }
    else
    {
      result = binarySearchAscRec(first, loc - 1, item);
    }
  }

  return result;
}

template <typename T>
ArrayList<T>::ArrayList(int size)
{
  s = size;
  numValues = 0;
  list = new T[size];
}

template <typename T>
ArrayList<T>::~ArrayList()
{
  delete[] list;
  s = 0;
  numValues = 0;
}

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
  while (i >= 0 && list[i] > a) // updated, inserts in ascending order now
  {
    list[i + 1] = list[i];
    i--;
  }
  list[i + 1] = a;
  numValues++;
}

template <typename T>
int ArrayList<T>::listSize() const
{
  return numValues;
}

template <typename T>
bool ArrayList<T>::isFull() const
{
  return (numValues == s);
}

template <typename T>
bool ArrayList<T>::isEmpty() const
{
  return (numValues == 0);
}

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

template <typename T>
void ArrayList<T>::print(ostream &out) const
{
  if (isEmpty())
  {
    out << "The list is empty\n";
  }
  else
  {
    for (int i = 0; i < numValues; i++)
    {
      out << "[" << i << "] " << list[i] << "\t";
    }
    out << endl;
  }
}

template <typename T>
int ArrayList<T>::binarySearch(const T &item) const
{
  int result = binarySearchAscRec(0, numValues - 1, item);
  return result;
}

template <typename T>
bool ArrayList<T>::remove(const T &val)
{
  if (isEmpty())
    return false;

  int idx = binarySearch(val);
  if (idx < 0)
    return false;

  for (int i = idx; i < numValues - 1; ++i)
  {
    list[i] = list[i + 1];
  }
  numValues--;
  return true;
}

template <typename T>
bool ArrayList<T>::removeRange(int a, int b)
{
  if (isEmpty())
    return false;
  if (a > b)
  {
    return false;
  }

  if (a < 0 || b >= numValues)
  {
    return false;
  }

  int count = b - a + 1;
  for (int i = b + 1; i < numValues; i++)
  {
    list[i - count] = list[i];
  }
  numValues -= count;
  return true;
}

#endif
