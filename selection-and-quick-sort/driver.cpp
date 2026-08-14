#include <iostream>
#include <fstream>
#include "SortedList.h"
#include "Stock.h"
using namespace std;

int main()
{
  SortedList<Stock> stockList;

  ifstream fin("Stock.txt");
  if (!fin)
  {
    cout << "Could not open Stock.txt.\n";
  }
  else
  {
    string name,
        symbol;
    double price;

    while (true)
    {
      if (!getline(fin, name))
      {
        break;
      }

      if (!getline(fin, symbol))
      {
        break;
      }

      if (!(fin >> price))
      {
        break;
      }

      fin.ignore(1000, '\n');
      stockList.insert(Stock(name, symbol, price));
    }
  }

  cout << "Original List\n";
  stockList.display();
  cout << "\n\n";

  cout << "New Randomised List\n";
  stockList.randomise();
  stockList.display();
  cout << "\n\n";

  cout << "The list after Selection Sort Ascending\n";
  stockList.selectionSortA();
  stockList.display();
  cout << "\n\n";

  cout << "New Randomised List\n";
  stockList.randomise();
  stockList.display();
  cout << "\n\n";

  cout << "The list after Selection Sort Descending\n";
  stockList.selectionSortD();
  stockList.display();
  cout << "\n\n";

  cout << "New Randomised List\n";
  stockList.randomise();
  stockList.display();
  cout << "\n\n";

  cout << "The list after Quick Sort Descending\n";
  stockList.quickSortA();
  stockList.display();
  cout << "\n\n";

  cout << "New Randomised List\n";
  stockList.randomise();
  stockList.display();
  cout << "\n\n";

  cout << "The list after Quick Sort Descending\n";
  stockList.quickSortD();
  stockList.display();
  cout << "\n\n";

  return 0;
}
