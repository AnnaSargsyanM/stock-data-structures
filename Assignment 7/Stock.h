//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #7
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					11/03/2025
//
//		This header file defines the Stock class, which includes constructors, functions for returning
//    the name, the symbol and the price of the stock, display function, and also functions to
//    determine whether two stocks are equal or not.
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

class Stock
{
private:
  string n;
  string s;
  double p;

public:
  Stock(string n = "", string s = "", double p = 0);
  Stock(const Stock &s);

  void display() const;

  string getName() const;
  string getSymbol() const;
  double getPrice() const;

  friend ostream &operator<<(ostream &out, const Stock &data);
  bool operator==(const Stock &rhs) const;
  bool operator!=(const Stock &rhs) const;
  bool operator<(const Stock &rhs) const;
  bool operator>(const Stock &rhs) const;
};

//*****************************************************************************************************

#endif
