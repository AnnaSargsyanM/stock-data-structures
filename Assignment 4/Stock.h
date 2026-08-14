//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #4 Part I
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/22/2025
//
//		This header file defines the Stock class, which includes constructors, functions for returning
//    the name, the symbol and the price of the stock, display function, and also functions to
//    determine whether two stocks are equal or not.
//    Updates: includes new int hash(int size) const function and instead of using namespace std,
//    std:: is being used.
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>

//*****************************************************************************************************

class Stock
{
private:
  std::string n;
  std::string s;
  double p;

public:
  Stock(std::string n = "", std::string s = "", double p = 0);
  Stock(const Stock &s);

  void display() const;

  std::string getName() const;
  std::string getSymbol() const;
  double getPrice() const;

  friend std::ostream &operator<<(std::ostream &out, const Stock &data);
  bool operator==(const Stock &rhs) const;
  bool operator!=(const Stock &rhs) const;
  bool operator<(const Stock &rhs) const;
  bool operator>(const Stock &rhs) const;

  int hash(int size) const;
};

//*****************************************************************************************************

std::ostream &operator<<(std::ostream &out, const Stock &s)
{
  out << s.getSymbol() << " - " << s.getName() << " : " << s.getPrice();

  return out;
}

//*****************************************************************************************************

Stock::Stock(std::string name, std::string symbol, double price)
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
  std::cout << "Name: " << n << ", Symbol: " << s << ", Price: " << p << '\n';
}

//*****************************************************************************************************

std::string Stock::getName() const
{
  return n;
}

//*****************************************************************************************************

std::string Stock::getSymbol() const
{
  return s;
}

//*****************************************************************************************************

double Stock::getPrice() const
{
  return p;
}

//*****************************************************************************************************

bool Stock::operator==(const Stock &rhs) const
{
  return s == rhs.s;
}

//*****************************************************************************************************

bool Stock::operator!=(const Stock &rhs) const
{
  return !(*this == rhs);
}

//*****************************************************************************************************

bool Stock::operator<(const Stock &rhs) const
{
  return s < rhs.s;
}

//*****************************************************************************************************

bool Stock::operator>(const Stock &rhs) const
{
  return s > rhs.s;
}

//*****************************************************************************************************

int Stock::hash(int size) const
{
  int sum = 0;
  for (int i = 0; i < n.size(); i++)
  {
    sum += n[i];
  }
  return sum % size;
}

//*****************************************************************************************************

#endif
