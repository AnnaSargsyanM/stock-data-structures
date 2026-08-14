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
