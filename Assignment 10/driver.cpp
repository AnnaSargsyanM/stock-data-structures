//*****************************************************************************************************
//
//		File:					driver.cpp
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
//		This header file defines reads stock information from a file. It displays the original list,
//    randomises the data, applies each sorting algorithm, and displays the sorting times.
//
//*****************************************************************************************************

#include "SortedList.h"
#include "Stock.h"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

//*****************************************************************************************************

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

/*

Original List
MOT - Motorola Inc. : 17.49
MSFT - Microsoft Corp. : 28.11
TSLA - Tesla : 564.33
INTC - Intel : 60.78
SNE - Sony : 105.81
AMD - Advanced Micro Devices : 84.51
NVDA - NVIDIA : 548.58
AAPL - Apple : 121.73


Selection Sort Ascending Time: 0.002167 ms

Selection Sort Descending Time: 0.001833 ms

Quick Sort Ascending Time: 0.001875 ms

Quick Sort Descending Time: 0.001917 ms

Heap Sort Ascending Time: 0.002541 ms

Heap Sort Descending Time: 0.002458 ms


*/
