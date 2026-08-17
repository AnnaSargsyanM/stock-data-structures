#ifndef DLLIST_H
#define DLLIST_H
#include <new>
#include "node.h"

template <typename TYPE>
class DLList
{
private:
  Node<TYPE> *front;
  Node<TYPE> *rear;

public:
  DLList();
  ~DLList();
  bool insert(const TYPE &dataIn);
  bool remove(TYPE &dataOut);
  bool retrieve(TYPE &dataIO) const;
  bool viewFront(TYPE &dataOut) const;
  bool viewRear(TYPE &dataOut) const;
  void display() const;
  void displayReverse() const;
  int getNumValues() const;
  bool isEmpty() const;
  bool isFull() const;
  bool insertBefore(const TYPE &dataIn, const TYPE &dataAfter);
};

template <typename TYPE>
DLList<TYPE>::DLList()
{
  front = nullptr;
  rear = nullptr;
}

template <typename TYPE>
DLList<TYPE>::~DLList()
{
  Node<TYPE> *pTemp;

  while (front)
  {
    pTemp = front;
    front = front->next;
    delete pTemp;
  }

  rear = nullptr;
}

template <typename TYPE>
bool DLList<TYPE>::insert(const TYPE &dataIn)
{
  bool success = false;
  Node<TYPE> *pBefore = nullptr;
  Node<TYPE> *pAfter = front;
  Node<TYPE> *pNew;

  while ((pAfter) && (pAfter->data) < dataIn)
  {
    pAfter = pAfter->next;
  }

  if (pAfter)
  {
    pBefore = pAfter->prev;
  }
  else
  {
    pBefore = rear;
  }

  pNew = new (std::nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

  if (pNew)
  {
    if (pBefore)
    {
      pBefore->next = pNew;
    }
    else
    {
      front = pNew;
    }

    if (pAfter)
    {
      pAfter->prev = pNew;
    }
    else
    {
      rear = pNew;
    }

    success = true;
  }

  return success;
}

template <typename TYPE>
bool DLList<TYPE>::remove(TYPE &dataOut)
{
  bool success = false;
  Node<TYPE> *pDel = front;

  while ((pDel) && (pDel->data < dataOut))
  {
    pDel = pDel->next;
  }

  if ((pDel) && (pDel->data == dataOut))
  {
    dataOut = pDel->data;

    if (pDel->prev)
    {
      pDel->prev->next = pDel->next;
    }
    else
    {
      front = pDel->next;
    }

    if (pDel->next)
    {
      pDel->next->prev = pDel->prev;
    }
    else
    {
      rear = pDel->prev;
    }

    delete pDel;
    success = true;
  }

  return success;
}

template <typename TYPE>
bool DLList<TYPE>::retrieve(TYPE &dataIO) const
{
  bool success = false;
  Node<TYPE> *pTemp = front;

  while ((pTemp) && (pTemp->data < dataIO))
  {
    pTemp = pTemp->next;
  }

  if (pTemp && (pTemp->data == dataIO))
  {
    dataIO = pTemp->data;
    success = true;
  }

  return success;
}

template <typename TYPE>
bool DLList<TYPE>::viewFront(TYPE &dataOut) const
{
  bool success = false;

  if (front)
  {
    dataOut = front->data;
    success = true;
  }

  return success;
}

template <typename TYPE>
bool DLList<TYPE>::viewRear(TYPE &dataOut) const
{
  bool success = false;

  if (rear)
  {
    dataOut = rear->data;
    success = true;
  }

  return success;
}

template <typename TYPE>
void DLList<TYPE>::display() const
{
  Node<TYPE> *pTemp = front;

  while (pTemp)
  {
    cout << pTemp->data << "\t";
    pTemp = pTemp->next;
  }
}

template <typename TYPE>
void DLList<TYPE>::displayReverse() const
{
  Node<TYPE> *pTemp = rear;

  while (pTemp)
  {
    cout << pTemp->data << "\t";
    pTemp = pTemp->prev;
  }
}

template <typename TYPE>
int DLList<TYPE>::getNumValues() const
{
  int numValues = 0;
  Node<TYPE> *pTemp = front;

  while (pTemp != nullptr)
  {
    numValues++;
    pTemp = pTemp->next;
  }

  return numValues;
}

template <typename TYPE>
bool DLList<TYPE>::isEmpty() const
{
  return (front == nullptr);
}

template <typename TYPE>
bool DLList<TYPE>::isFull() const
{
  bool full = true;
  Node<TYPE> *pNew;

  pNew = new (std::nothrow) Node<TYPE>;

  if (pNew)
  {
    full = false;
    delete pNew;
  }

  return full;
}

template <typename TYPE>
bool DLList<TYPE>::insertBefore(const TYPE &dataIn, const TYPE &dataAfter)
{
  bool success = false;
  Node<TYPE> *pBefore = nullptr;
  Node<TYPE> *pAfter = front;

  while (pAfter && pAfter->data != dataAfter)
  {
    pBefore = pAfter;
    pAfter = pAfter->next;
  }

  if ((pAfter) && (pAfter->data == dataAfter))
  {
    Node<TYPE> *pNew = new (std::nothrow) Node<TYPE>(dataIn, pAfter, pBefore);

    if (pNew)
    {
      if (pBefore)
      {
        pBefore->next = pNew;
      }
      else
      {
        front = pNew;
      }

      pAfter->prev = pNew;

      success = true;
    }
  }

  return success;
}

#endif
