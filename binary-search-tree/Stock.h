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

#endif
