#ifndef HTELEMENT_H
#define HTELEMENT_H
#include <iostream>
#include <string>

template <typename T>
struct HTElement
{
  T item;
  int status;

  HTElement();
  HTElement(const T &newItem, int st = 1);
};

template <typename T>
HTElement<T>::HTElement()
{
  status = 0;
}

template <typename T>
HTElement<T>::HTElement(const T &newItem, int st)
{
  item = newItem;
  status = st;
}

#endif
