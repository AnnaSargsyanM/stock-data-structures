#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "stack.h"

void outputToken(char token[], ofstream &resultsFile);
void processNumber(char token[], Stack<int> &rpnStack, ofstream &resultsFile);
bool processOperator(char opr, Stack<int> &rpnStack, ofstream &resultsFile);
void displayResult(bool isValid, Stack<int> &rpnStack, ofstream &resultsFile);
void resetFlagStack(bool &isValid, Stack<int> &rpnStack);

int main()
{
  Stack<int> rpnStack;

  bool isValid = true;

  char token[5];
  char operand;

  ifstream expFile("expressions.txt");
  ofstream resultsFile("results.txt");

  while (expFile >> token)
  {
    outputToken(token, resultsFile);

    if (token[0] == ';')
    {
      displayResult(isValid, rpnStack, resultsFile);
      resetFlagStack(isValid, rpnStack);
      resultsFile << endl;
    }

    else if (isValid && isdigit(token[0]))
    {
      processNumber(token, rpnStack, resultsFile);
    }

    else if (isValid && ispunct(token[0]))
    {
      isValid = processOperator(token[0], rpnStack, resultsFile);
    }
  }

  expFile.close();
  resultsFile.close();

  return 0;
}

void outputToken(char token[], ofstream &resultsFile)
{
  resultsFile << "( Token: " << token << ") \t\t";

  if (token[0] != ';')
    cout << token << " ";
}

void processNumber(char token[], Stack<int> &rpnStack, ofstream &resultsFile)
{
  int num;
  num = atoi(token);
  rpnStack.push(num);
  resultsFile << "Push \t" << num << endl;
}

bool processOperator(char opr, Stack<int> &rpnStack, ofstream &resultsFile)
{
  bool isValid = true;
  int op1,
      op2,
      result;

  if ((rpnStack.pop(op2)) && (rpnStack.pop(op1)))
  {
    switch (opr)
    {
    case '+':
      result = op1 + op2;
      break;
    case '-':
      result = op1 - op2;
      break;
    case '*':
      result = op1 * op2;
      break;
    case '/':
      result = (op2 != 0) ? (op1 / op2) : (isValid = false);
      break;
    case '%':
      result = (op2 != 0) ? (op1 % op2) : (isValid = false);
      break;
    default:
      isValid = false;
      break;
    }

    if (isValid)
    {
      rpnStack.push(result);
      resultsFile << "Pop\t\t" << op2 << "\t\tPop\t\t" << op1 << "\t\tPush\t" << result << endl;
    }
  }

  return isValid;
}

void displayResult(bool isValid, Stack<int> &rpnStack, ofstream &resultsFile)
{
  int result,
      extraOpr;

  if (!isValid)
  {
    cout << "\t\tInvalid RPN expression: not enough operands" << endl;
    resultsFile << "\t\tInvalid RPN expression: not enough operands" << endl;
  }
  else if (rpnStack.pop(result))
  {
    resultsFile << "Pop\t" << result << endl;

    if (rpnStack.pop(extraOpr))
    {
      cout << "\t\tInvalid RPN expression: too many operands" << endl;
      resultsFile << "\t\tInvalid RPN expression: too many operands" << endl;
    }
    else
    {
      cout << "= " << result << endl;
      resultsFile << "\t\tValid: result = " << result << endl;
    }
  }
}

void resetFlagStack(bool &isValid, Stack<int> &rpnStack)
{
  int temp;
  isValid = true;

  while (!rpnStack.isEmpty())
  {
    rpnStack.pop(temp);
  }
}
