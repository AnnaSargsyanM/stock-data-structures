#include "SortedList.h"
#include "Stock.h"
#include <iostream>
#include <fstream>
#include <chrono>
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

  stockList.randomise();
  auto start = chrono::high_resolution_clock::now();
  stockList.selectionSortA();
  auto end = chrono::high_resolution_clock::now();
  cout << "Selection Sort Ascending Time: " << chrono::duration<double, milli>(end - start).count()
       << " ms\n\n";

  stockList.randomise();
  start = chrono::high_resolution_clock::now();
  stockList.selectionSortD();
  end = chrono::high_resolution_clock::now();
  cout << "Selection Sort Descending Time: " << chrono::duration<double, milli>(end - start).count()
       << " ms\n\n";

  stockList.randomise();
  start = chrono::high_resolution_clock::now();
  stockList.quickSortA();
  end = chrono::high_resolution_clock::now();
  cout << "Quick Sort Ascending Time: " << chrono::duration<double, milli>(end - start).count()
       << " ms\n\n";

  stockList.randomise();
  start = chrono::high_resolution_clock::now();
  stockList.quickSortD();
  end = chrono::high_resolution_clock::now();
  cout << "Quick Sort Descending Time: " << chrono::duration<double, milli>(end - start).count()
       << " ms\n\n";

  stockList.randomise();
  start = chrono::high_resolution_clock::now();
  stockList.heapSortA();
  end = chrono::high_resolution_clock::now();
  cout << "Heap Sort Ascending Time: " << chrono::duration<double, milli>(end - start).count()
       << " ms\n\n";

  stockList.randomise();
  start = chrono::high_resolution_clock::now();
  stockList.heapSortD();
  end = chrono::high_resolution_clock::now();
  cout << "Heap Sort Descending Time: " << chrono::duration<double, milli>(end - start).count()
       << " ms\n\n";

  return 0;
}
