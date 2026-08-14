//*****************************************************************************************************
//
//		File:					driver.cpp
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #9
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					11/17/2025
//
//		This header file defines reads stock information from a file. It displays the original list,
//    randomises the data, applies each sorting algorithm, and redisplays the results.
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include "SortedList.h"
#include "Stock.h"
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


New Randomised List
NVDA - NVIDIA : 548.58
MSFT - Microsoft Corp. : 28.11
TSLA - Tesla : 564.33
AMD - Advanced Micro Devices : 84.51
MOT - Motorola Inc. : 17.49
AAPL - Apple : 121.73
INTC - Intel : 60.78
SNE - Sony : 105.81


The list after Selection Sort Ascending
AAPL - Apple : 121.73
AMD - Advanced Micro Devices : 84.51
INTC - Intel : 60.78
MOT - Motorola Inc. : 17.49
MSFT - Microsoft Corp. : 28.11
NVDA - NVIDIA : 548.58
SNE - Sony : 105.81
TSLA - Tesla : 564.33


New Randomised List
NVDA - NVIDIA : 548.58
TSLA - Tesla : 564.33
SNE - Sony : 105.81
MSFT - Microsoft Corp. : 28.11
MOT - Motorola Inc. : 17.49
INTC - Intel : 60.78
AAPL - Apple : 121.73
AMD - Advanced Micro Devices : 84.51


The list after Selection Sort Descending
TSLA - Tesla : 564.33
SNE - Sony : 105.81
NVDA - NVIDIA : 548.58
MSFT - Microsoft Corp. : 28.11
MOT - Motorola Inc. : 17.49
INTC - Intel : 60.78
AMD - Advanced Micro Devices : 84.51
AAPL - Apple : 121.73


New Randomised List
AAPL - Apple : 121.73
MOT - Motorola Inc. : 17.49
SNE - Sony : 105.81
AMD - Advanced Micro Devices : 84.51
INTC - Intel : 60.78
NVDA - NVIDIA : 548.58
TSLA - Tesla : 564.33
MSFT - Microsoft Corp. : 28.11


The list after Quick Sort Descending
AAPL - Apple : 121.73
AMD - Advanced Micro Devices : 84.51
INTC - Intel : 60.78
MOT - Motorola Inc. : 17.49
MSFT - Microsoft Corp. : 28.11
NVDA - NVIDIA : 548.58
SNE - Sony : 105.81
TSLA - Tesla : 564.33


New Randomised List
INTC - Intel : 60.78
AAPL - Apple : 121.73
TSLA - Tesla : 564.33
AMD - Advanced Micro Devices : 84.51
SNE - Sony : 105.81
MOT - Motorola Inc. : 17.49
NVDA - NVIDIA : 548.58
MSFT - Microsoft Corp. : 28.11


The list after Quick Sort Descending
TSLA - Tesla : 564.33
SNE - Sony : 105.81
NVDA - NVIDIA : 548.58
MSFT - Microsoft Corp. : 28.11
MOT - Motorola Inc. : 17.49
INTC - Intel : 60.78
AMD - Advanced Micro Devices : 84.51
AAPL - Apple : 121.73

*/
