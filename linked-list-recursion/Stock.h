#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>
using namespace std;

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

ostream &operator<<(ostream &out, const Stock &s)
{
  out << s.getSymbol() << " - " << s.getName() << " : " << s.getPrice();

  return out;
}

Stock::Stock(string name, string symbol, double price)
{
  n = name;
  s = symbol;
  p = price;
}

Stock::Stock(const Stock &copy)
{
  n = copy.n;
  s = copy.s;
  p = copy.p;
}

void Stock::display() const
{
  cout << "Name: " << n << ", Symbol: " << s << ", Price: " << p << '\n';
}

string Stock::getName() const
{
  return n;
}

string Stock::getSymbol() const
{
  return s;
}

double Stock::getPrice() const
{
  return p;
}

bool Stock::operator==(const Stock &rhs) const
{
  return s == rhs.s;
}

bool Stock::operator!=(const Stock &rhs) const
{
  return !(*this == rhs);
}

bool Stock::operator<(const Stock &rhs) const
{
  return s < rhs.s;
}

bool Stock::operator>(const Stock &rhs) const
{
  return s > rhs.s;
}

#endif
