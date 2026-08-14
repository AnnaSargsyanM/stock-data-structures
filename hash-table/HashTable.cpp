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
