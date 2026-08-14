//*****************************************************************************************************
//
//		File:					SortedList.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #10
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					11/24/2025
//
//    This header file defines a template class SortedList, which stores values in a dynamic array
//    and provides functions for inserting, randomising, displaying, and sorting the data.
//
//*****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

//*****************************************************************************************************

template <typename T>
class SortedList
{
private:
  T *value;
  int capacity;
  int count;

  void quickSort(T arr[], int low, int high, bool ascending);
  int partition(T arr[], int low, int high, bool ascending);
  void heapifyMax(int n, int i);
  void heapifyMin(int n, int i);

public:
  SortedList(int size = 10);
  ~SortedList() { delete[] value; };

  void insert(const T &item);
  void randomise();
  void selectionSortA();
  void selectionSortD();
  void quickSortA();
  void quickSortD();
  void heapSortA();
  void heapSortD();
  void display() const;
};

//*****************************************************************************************************

template <typename T>
inline SortedList<T>::SortedList(int size)
{
  size = 10;
  capacity = size;
  count = 0;
  value = new T[capacity];

  std::srand(static_cast<unsigned>(std::time(nullptr)));
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::insert(const T &item)
{
  if (count == capacity)
  {
    int newCapacity = capacity + 10;
    T *newValue = new T[newCapacity];

    for (int i = 0; i < count; ++i)
    {
      newValue[i] = value[i];
    }

    delete[] value;
    value = newValue;
    capacity = newCapacity;
  }

  value[count++] = item;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::randomise()
{
  if (count > 1)
  {
    for (int i = 0; i < count; ++i)
    {
      int j = std::rand() % count;
      std::swap(value[i], value[j]);
    }
  }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::selectionSortA()
{
  for (int i = 0; i < count - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < count; j++)
    {
      if (value[j] < value[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      std::swap(value[i], value[minIndex]);
    }
  }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::selectionSortD()
{
  for (int i = 0; i < count - 1; i++)
  {
    int maxIndex = i;
    for (int j = i + 1; j < count; ++j)
    {
      if (value[j] > value[maxIndex])
      {
        maxIndex = j;
      }
    }
    if (maxIndex != i)
    {
      std::swap(value[i], value[maxIndex]);
    }
  }
}

//*****************************************************************************************************

template <typename T>
inline void SortedList<T>::quickSortA()
{
  if (count > 1)
  {
    quickSort(value, 0, count - 1, true);
  }
}

//*****************************************************************************************************

template <typename T>
inline void SortedList<T>::quickSortD()
{
  if (count > 1)
  {
    quickSort(value, 0, count - 1, false);
  }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSort(T arr[], int low, int high, bool ascending)
{
  if (low < high)
  {
    int pivotLoc = partition(arr, low, high, ascending);
    quickSort(arr, low, pivotLoc - 1, ascending);
    quickSort(arr, pivotLoc + 1, high, ascending);
  }
}

//*****************************************************************************************************

template <typename T>
int SortedList<T>::partition(T arr[], int low, int high, bool ascending)
{
  T pivot = arr[(low + high) / 2];
  std::swap(arr[low], arr[(low + high) / 2]);
  int smallIndex = low;

  for (int i = low + 1; i <= high; ++i)
  {
    bool condition = ascending ? (arr[i] < pivot) : (arr[i] > pivot);

    if (condition)
    {
      ++smallIndex;
      std::swap(arr[smallIndex], arr[i]);
    }
  }

  std::swap(arr[low], arr[smallIndex]);
  return smallIndex;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapifyMax(int n, int root)
{
  int largest = root;
  int l = 2 * root + 1;
  int r = 2 * root + 2;

  if ((l < n) && (value[l] > value[largest]))
  {
    largest = l;
  }

  if ((r < n) && (value[r] > value[largest]))
  {
    largest = r;
  }

  if (largest != root)
  {
    std::swap(value[root], value[largest]);
    heapifyMax(n, largest);
  }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapifyMin(int n, int root)
{
  int smallest = root;
  int l = 2 * root + 1;
  int r = 2 * root + 2;

  if ((l < n) && (value[l] < value[smallest]))
  {
    smallest = l;
  }

  if ((r < n) && (value[r] < value[smallest]))
  {
    smallest = r;
  }

  if (smallest != root)
  {
    std::swap(value[root], value[smallest]);
    heapifyMin(n, smallest);
  }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortA()
{
  int n = count;
  if (n <= 1)
    return;

  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapifyMax(n, i);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    std::swap(value[0], value[i]);
    heapifyMax(i, 0);
  }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::heapSortD()
{
  int n = count;
  if (n <= 1)
    return;

  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapifyMin(n, i);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    std::swap(value[0], value[i]);
    heapifyMin(i, 0);
  }
}

//*****************************************************************************************************

template <typename T>
inline void SortedList<T>::display() const
{
  for (int i = 0; i < count; ++i)
  {
    std::cout << value[i] << std::endl;
  }
}

//*****************************************************************************************************

#endif
