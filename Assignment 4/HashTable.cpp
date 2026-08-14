//*****************************************************************************************************
//
//		File:					HashTable.cpp
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #4 Part IV
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/22/2025
//
//		This driver tests the functionality of HashTable.
//
//*****************************************************************************************************

#include <iostream>
#include "Stock.h"
#include "HTElement.h"
#include "HashTable.h"

using namespace std;

int main()
{
  HashTable<Stock> stockTable(10);

  Stock s1("Palantir", "PLTR", 153.1);
  Stock s2("Microsoft", "MSFT", 495.0);
  Stock s3("CoreWeave", "CRWV", 89.0);

  stockTable.insert(s1);
  stockTable.insert(s2);
  stockTable.insert(s3);

  cout << "Display after insertions: " << endl;
  stockTable.display();
  cout << endl;

  cout << "Searching for MSFT..." << endl;
  Stock searching("Microsoft", "MSFT", 0);
  Stock *found = stockTable.search(searching);

  if (found != nullptr)
  {
    cout << "Found: ";
    found->display();
    delete found;
  }
  else
  {
    cout << "MSFT not found." << endl;
  }
  cout << endl;

  cout << "Removing CRWA..." << endl;
  Stock removeStock("CoreWeave", "CRWV", 0);
  stockTable.remove(removeStock);

  cout << "Display after removal: " << endl;
  stockTable.display();
  cout << endl;

  cout << "Searching for CRWA..." << endl;
  Stock *removedSearch = stockTable.search(removeStock);

  if (removedSearch != nullptr)
  {
    cout << "Error: the stock should have been removed" << endl;
    delete removedSearch;
  }
  else
  {
    cout << "Stock not found." << endl;
  }
  cout << endl;

  return 0;
}

//*****************************************************************************************************
/*
Display after insertions:
Name: Microsoft, Symbol: MSFT, Price: 495
Name: Palantir, Symbol: PLTR, Price: 153.1
Name: CoreWeave, Symbol: CRWV, Price: 89

Searching for MSFT...
Found: Name: Microsoft, Symbol: MSFT, Price: 495

Removing CRWA...
Display after removal:
Name: Microsoft, Symbol: MSFT, Price: 495
Name: Palantir, Symbol: PLTR, Price: 153.1

Searching for CRWA...
Stock not found, as expected.
*/
