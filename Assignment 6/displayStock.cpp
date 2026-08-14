//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #6 Part III
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					10/06/2025
//
//		This is a .cpp file to display the stocks from Stock.txt, search for the name by symbol, and
//    also insert new stocks.
//
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "Stock.h"
#include "BinarySearchTree.h"

using namespace std;

//*****************************************************************************************************

int main()
{
  BinarySearchTree<Stock> stockTree;

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
      stockTree.insert(Stock(name, symbol, price));
    }
  }

  bool done = false;
  while (!done)
  {
    cout << "\nStock Menu\n";
    cout << "a) Display a stock's name given its symbol\n";
    cout << "b) Display a stock's price given its symbol\n";
    cout << "c) Insert a new stock\n";
    cout << "d) Display all stocks (in-order)\n";
    cout << "e) Quit\n";
    cout << "Enter choice: ";

    char choice;
    if (!(cin >> choice))
    {
      break;
    }

    cin.ignore(1000, '\n');

    if (choice == 'a' || choice == 'A')
    {
      cout << "Enter symbol: ";
      string sym;
      getline(cin, sym);

      Stock key("", sym, 0.0);
      Stock *found = stockTree.search(key);
      if (found)
      {
        cout << "Name: " << found->getName() << "\n";
      }
      else
      {
        cout << "Symbol not found.\n";
      }
    }

    else if (choice == 'b' || choice == 'B')
    {
      cout << "Enter symbol: ";
      string sym;
      getline(cin, sym);

      Stock key("", sym, 0.0);
      Stock *found = stockTree.search(key);
      if (found)
      {
        cout << "Price: " << found->getPrice() << "\n";
      }
      else
      {
        cout << "Symbol not found.\n";
      }
    }

    else if (choice == 'c' || choice == 'C')
    {
      string name,
          sym;
      double price;

      cout << "Enter name: ";
      getline(cin, name);
      cout << "Enter symbol: ";
      getline(cin, sym);
      cout << "Enter price: ";
      cin >> price;
      cin.ignore(1000, '\n');

      stockTree.insert(Stock(name, sym, price));
      cout << "Stock inserted.\n";
    }

    else if (choice == 'd' || choice == 'D')
    {
      cout << "\nAll Stocks (in-order):\n";
      stockTree.inorder();
    }

    else if (choice == 'e' || choice == 'E')
    {
      ofstream fout("Stock.txt");
      if (!fout)
      {
        cout << "Could not write to Stock.txt\n";
      }
      else
      {
        stockTree.inorder(fout);
        cout << "Saved to Stock.txt.\n";
      }
      done = true;
    }
    else
    {
      cout << "Invalid choice. Try again.\n";
    }
  }

  return 0;
}

//*****************************************************************************************************

/*
Stock Menu
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks (in-order)
e) Quit
Enter choice: d

All Stocks (in-order):
AAPL - Apple : 121.73
AMD - Advanced Micro Devices : 84.51
INTC - Intel : 60.78
MOT -  - Motorola Inc. : 17.49
MSFT - Microsoft Corp. : 28.11
NVDA - NVIDIA : 548.58
SNE - Sony : 105.81
TSLA - Tesla : 564.33

Stock Menu
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks (in-order)
e) Quit
Enter choice: a
Enter symbol: MOT
Name:  - Motorola Inc.

Stock Menu
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks (in-order)
e) Quit
Enter choice: e
Saved to Stock.txt.
*/
