#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

template <typename T>
class SortedList
{
private:
  T *value;
  int capacity;
  int count;

  void quickSort(T arr[], int low, int high, bool ascending);
  int partition(T arr[], int low, int high, bool ascending);

public:
  SortedList(int size = 10);
  ~SortedList() { delete[] value; };

  void insert(const T &item);
  void randomise();
  void selectionSortA();
  void selectionSortD();
  void quickSortA();
  void quickSortD();
  void display() const;
};

template <typename T>
SortedList<T>::SortedList(int size)
{
  size = 10;
  capacity = size;
  count = 0;
  value = new T[capacity];

  std::srand(static_cast<unsigned>(std::time(nullptr)));
}

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

template <typename T>
void SortedList<T>::quickSortA()
{
  if (count > 1)
  {
    quickSort(value, 0, count - 1, true);
  }
}

template <typename T>
void SortedList<T>::quickSortD()
{
  if (count > 1)
  {
    quickSort(value, 0, count - 1, false);
  }
}

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

template <typename T>
void SortedList<T>::display() const
{
  for (int i = 0; i < count; ++i)
  {
    std::cout << value[i] << std::endl;
  }
}

#endif
