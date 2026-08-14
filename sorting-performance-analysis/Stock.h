#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>

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
  friend std::istream &operator>>(std::istream &in, Stock &data);
  bool operator==(const Stock &rhs) const;
  bool operator!=(const Stock &rhs) const;
  bool operator<(const Stock &rhs) const;
  bool operator>(const Stock &rhs) const;
};

#endif
