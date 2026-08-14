//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #4 Part II
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/22/2025
//
//		This header file defines the HTElement struct.
//
//*****************************************************************************************************

#ifndef HTELEMENT_H
#define HTELEMENT_H
#include <iostream>
#include <string>

//*****************************************************************************************************

template <typename T>
struct HTElement
{
  T item;
  int status;

  HTElement();
  HTElement(const T &newItem, int st = 1);
};

//*****************************************************************************************************

template <typename T>
HTElement<T>::HTElement()
{
  status = 0;
}

//*****************************************************************************************************

template <typename T>
HTElement<T>::HTElement(const T &newItem, int st)
{
  item = newItem;
  status = st;
}

//*****************************************************************************************************

#endif
