//*****************************************************************************************************
//
//		File:					LList.h
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #2 Part II
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/08/2025
//
//		Other files required:
//			1. LList.h
//      2. Stock.h
//
//*****************************************************************************************************

#include <iostream>
#include "Stock.h"
#include "LList.h"
using namespace std;

int main()
{
  LList<Stock> stockList;

  stockList.insertDesc(Stock("Palantir", "PLTR", 153.1));
  stockList.insertDesc(Stock("Microsoft", "MSFT", 495.0));
  stockList.insertDesc(Stock("CoreWeave", "CRWV", 89.0));

  cout << "Stocks in descending order by symbol:\n";
  stockList.display();

  cout << "\nDeleting MSFT...\n";
  stockList.deleteItem(Stock("", "MSFT", 0));

  cout << "Updated stock list:\n";
  stockList.display();

  return 0;
}

//*****************************************************************************************************
/*
PLTR - Palantir : 153.1
MSFT - Microsoft : 495
CRWV - CoreWeave : 89

Deleting MSFT...
Updated stock list:
PLTR - Palantir : 153.1
CRWV - CoreWeave : 89
*/
