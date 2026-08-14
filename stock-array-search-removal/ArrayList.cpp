#include "ArrayList.h"
#include "Stock.h"

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ArrayList<Stock> stockList(10);

  ifstream fin("Stock.txt");
  if (!fin)
  {
    cout << "Could not open Stock.txt\n";
    return 1;
  }

  string name,
      symbol;
  double price;
  int numStocks = 0;

  for (int i = 0; i < 8; i++)
  {
    if (!getline(fin, name))
    {
      break;
    }

    if (!(fin >> symbol))
    {
      break;
    }

    if (!(fin >> price))
    {
      break;
    }

    fin.ignore(10000, '\n');

    stockList.insert(Stock(name, symbol, price));
    numStocks++;
  }

  cout << "The number of Stocks is: " << numStocks << endl;
  cout << "Initial Stock List:\n";
  stockList.print();

  Stock searchStock("", "MSFT", 0);
  int idx = stockList.binarySearch(searchStock);
  if (idx != -1)
  {
    cout << "MSFT found at index " << idx << endl;
  }
  else
  {
    cout << "MSFT not found\n";
  }

  cout << "\nRemoving MSFT...\n";
  if (stockList.remove(searchStock))
  {
    cout << "Removed successfully\n";
  }
  else
  {
    cout << "Not found\n";
  }
  stockList.print();

  cout << "\nRemoving indices 1 to 2...\n";
  if (stockList.removeRange(1, 2))
  {
    cout << "Removed range successfully\n";
  }
  else
  {
    cout << "Range invalid\n";
  }
  stockList.print();

  return 0;
}
