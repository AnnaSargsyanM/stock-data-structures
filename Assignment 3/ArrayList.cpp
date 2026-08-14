//*****************************************************************************************************
//
//		File:					ArrayList.cpp
//
//		Student:				Anna Sargsyan
//
//		Assignment:				Assignment #3
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-Z1
//
//		Due:					09/15/2025
//
//
//    This cpp file tests the functionality of ArrayList.h and Stock.h files.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

#include "ArrayList.h"
#include "Stock.h"

//*****************************************************************************************************

int main()
{

  ArrayList<int> intList(10);

  cout << "Is the list empty? ";
  if (intList.isEmpty())
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
  cout << endl;

  for (int i = 0; i < 12; i++)
  {
    intList.insert(i * 5);
  }
  intList.print();

  cout << "Size of the list: " << intList.listSize() << endl;

  cout << "Is the list full? ";
  if (intList.isFull())
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
  cout << endl;

  int search = 15;
  int index = intList.binarySearch(search);

  cout << "Binary search for " << search << ": ";
  if (index != -1)
  {
    cout << "Found at index " << index;
  }
  else
  {
    cout << "Not found";
  }
  cout << endl;

  ArrayList<int> intListCopy(intList);
  cout << "Copy of intList: ";
  intListCopy.print();

  cout << "Testing ArrayList<Stock>" << endl;
  ArrayList<Stock> stockList(5);

  stockList.insert(Stock("Palantir", "PLTR", 153.1));
  stockList.insert(Stock("Microsoft", "MSFT", 495.0));
  stockList.insert(Stock("CoreWeave", "CRWV", 89.0));

  stockList.print();

  cout << "List size: " << stockList.listSize() << endl;

  Stock searchStock("", "MSFT", 0);
  int stockIndex = stockList.binarySearch(searchStock);
  cout << "Binary search for MSFT: ";
  if (index != -1)
  {
    cout << "Found at index " << index;
  }
  else
  {
    cout << "Not found";
  }
  cout << endl;

  ArrayList<Stock> stockListCopy(stockList);
  cout << "Copy of stockList:" << endl;
  stockListCopy.print();

  return 0;
}

//*****************************************************************************************************

/*
Is the list empty? Yes
[0] 55  [1] 50  [2] 45  [3] 40  [4] 35  [5] 30  [6] 25  [7] 20  [8] 15  [9] 10  [10] 5  [11] 0
Size of the list: 12
Is the list full? No
Binary search for 15: Found at index 8
Copy of intList: [0] 55 [1] 50  [2] 45  [3] 40  [4] 35  [5] 30  [6] 25  [7] 20  [8] 15  [9] 10  [10] 5  [11] 0
Testing ArrayList<Stock>
[0] PLTR - Palantir : 153.1     [1] MSFT - Microsoft : 495      [2] CRWV - CoreWeave : 89
List size: 3
Binary search for MSFT: Found at index 8
Copy of stockList:
[0] PLTR - Palantir : 153.1     [1] MSFT - Microsoft : 495      [2] CRWV - CoreWeave : 89
*/
