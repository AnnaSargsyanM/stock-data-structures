#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HTElement.h"
#include <iostream>

template <typename T>
class HashTable
{
private:
  int s;
  HTElement<T> *table;
  int numValues;

public:
  HashTable(int size = 10);
  ~HashTable();

  void insert(const T &item);
  void remove(const T &item);
  void display() const;
  T *search(const T &item) const;
};

template <typename T>
HashTable<T>::HashTable(int size)
{
  s = size;
  numValues = 0;
  table = new HTElement<T>[s];
}

template <typename T>
HashTable<T>::~HashTable()
{
  delete[] table;
  table = nullptr;
  s = 0;
  numValues = 0;
}

template <typename T>
void HashTable<T>::insert(const T &item)
{
  int h = item.hash(s);
  int i = 0;
  int pos;

  while (i < s)
  {
    pos = (h + i * i) % s;

    if (table[pos].status == 0)
    {
      table[pos].item = item;
      table[pos].status = 1;
      numValues++;
      return;
    }

    i++;
  }

  std::cout << "HashTable is full; insert failed.\n";
}

template <typename T>
void HashTable<T>::remove(const T &item)
{
  int h = item.hash(s);
  int i = 0;

  while (i < s)
  {
    int pos = (h + i * i) % s;

    if (table[pos].status == 0)
    {
      return;
    }
    else if (table[pos].status == 1 && table[pos].item == item)
    {
      table[pos].status = -1;
      numValues--;
      return;
    }

    i++;
  }
}

template <typename T>
void HashTable<T>::display() const
{
  for (int i = 0; i < s; ++i)
  {
    if (table[i].status == 1)
    {
      table[i].item.display();
    }
  }
}

template <typename T>
T *HashTable<T>::search(const T &item) const
{

  int h = item.hash(s);
  int i = 0;

  while (i < s)
  {
    int pos = (h + i * i) % s;

    if (table[pos].status == 0)
    {
      return nullptr;
    }
    else if (table[pos].status == 1 && table[pos].item == item)
    {
      return new T(table[pos].item);
    }

    i++;
  }

  return nullptr;
}

#endif
