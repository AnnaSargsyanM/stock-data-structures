#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;
#include "stack.h"
#include "queue.h"

bool testNdisplayPal(Stack<char> &s1, Queue<char> &q1);
char getPalType(bool hasPunct, bool hasSpace);
void displayPalResults(bool isValid, char palType);

int main()
{
  Stack<char> s1;
  Queue<char> q1;

  bool hasPunct,
      hasSpace,
      isValid;

  char palType,
      pal[80];

  int len;

  ifstream palFile("palindromes.txt");

  while (palFile.getline(pal, 80, '#'))
  {
    hasPunct = false;
    hasSpace = false;
    isValid = true;

    len = int(strlen(pal));

    for (int i = 0; i < len; i++)
    {
      if (isalpha(pal[i]))
      {
        pal[i] = tolower(pal[i]);
        s1.push(pal[i]);
        q1.enqueue(pal[i]);
      }
      else if (ispunct(pal[i]))
      {
        hasPunct = true;
      }
      else if (isspace(pal[i]))
      {
        hasSpace = true;
      }
    }

    isValid = testNdisplayPal(s1, q1);
    palType = getPalType(hasPunct, hasSpace);
    displayPalResults(isValid, palType);
  }

  palFile.close();

  return 0;
}

bool testNdisplayPal(Stack<char> &s1, Queue<char> &q1)
{
  bool isValid = true;
  char temp1,
      temp2;

  while (s1.pop(temp1) && q1.dequeue(temp2))
  {
    if (temp1 != temp2)
    {
      isValid = false;
    }

    cout << temp1;
  }

  cout << "\t\t";

  return isValid;
}

char getPalType(bool hasPunct, bool hasSpace)
{
  char palType = '1';

  if (hasPunct)
  {
    palType = '3';
  }
  else if (hasSpace)
  {
    palType = '2';
  }

  return palType;
}

void displayPalResults(bool isValid, char palType)
{
  if (isValid)
  {
    cout << "type " << palType;
  }

  else
  {
    cout << "invalid";
  }

  cout << endl;
}
