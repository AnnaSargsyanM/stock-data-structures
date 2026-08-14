//*****************************************************************************************************
//
//		File:					Stock.h
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
//		This is a .cpp file for defining the functions of "Stock" class.
//
//*****************************************************************************************************

#include "Stock.h"
#include <iostream>
using namespace std;

//*****************************************************************************************************

ostream &operator<<(ostream &out, const Stock &s)
{
  out << s.getSymbol() << " - " << s.getName() << " : " << s.getPrice();

  return out;
}

//*****************************************************************************************************

inline istream &operator>>(istream &in, Stock &s)
{
  string name, symbol;
  double price;

  if (in >> symbol >> name >> price)
  {
    s = Stock(name, symbol, price);
  }

  return in;
}

//*****************************************************************************************************

Stock::Stock(string name, string symbol, double price)
{
  n = name;
  s = symbol;
  p = price;
}

//*****************************************************************************************************

Stock::Stock(const Stock &copy)
{
  n = copy.n;
  s = copy.s;
  p = copy.p;
}

//*****************************************************************************************************

void Stock::display() const
{
  cout << "Name: " << n << ", Symbol: " << s << ", Price: " << p << '\n';
}

//*****************************************************************************************************

string Stock::getName() const { return n; }

//*****************************************************************************************************

string Stock::getSymbol() const { return s; }

//*****************************************************************************************************

double Stock::getPrice() const { return p; }

//*****************************************************************************************************

bool Stock::operator==(const Stock &rhs) const { return s == rhs.s; }

//*****************************************************************************************************

bool Stock::operator!=(const Stock &rhs) const { return !(*this == rhs); }

//*****************************************************************************************************

bool Stock::operator<(const Stock &rhs) const { return s < rhs.s; }

//*****************************************************************************************************

bool Stock::operator>(const Stock &rhs) const { return s > rhs.s; }

//*****************************************************************************************************
