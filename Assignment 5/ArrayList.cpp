//*****************************************************************************************************
//
//		File:					ArrayList.cpp
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #5
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/29/2025
//
//
//    This driver tests the functionality of ArrayList.h and Stock.h files.
//
//*****************************************************************************************************

#include "ArrayList.h"
#include "Stock.h"

#include <iostream>
#include <fstream>
using namespace std;

//*****************************************************************************************************

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

//*****************************************************************************************************
/*
The number of Stocks is: 8
Initial Stock List:
[0] AAPL - Apple : 121.73       [1] AMD - Advanced Micro Devices : 84.51        [2] INTC - Intel : 60.78        [3] MOT - Motorola Inc. : 17.49      [4] MSFT - Microsoft Corp. : 28.11      [5] NVDA - NVIDIA : 548.58      [6] SNE - Sony : 105.81      [7] TSLA - Tesla : 564.33
MSFT found at index 4

Removing MSFT...
Removed successfully
[0] AAPL - Apple : 121.73       [1] AMD - Advanced Micro Devices : 84.51        [2] INTC - Intel : 60.78        [3] MOT - Motorola Inc. : 17.49      [4] NVDA - NVIDIA : 548.58      [5] SNE - Sony : 105.81 [6] TSLA - Tesla : 564.33

Removing indices 1 to 2...
Removed range successfully
[0] AAPL - Apple : 121.73       [1] MOT - Motorola Inc. : 17.49 [2] NVDA - NVIDIA : 548.58      [3] SNE - Sony : 105.81      [4] TSLA - Tesla : 564.33
 */
