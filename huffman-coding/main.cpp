#include "Stock.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

template <typename T>
struct Node
{
  T value;
  double freq;
  Node *left;
  Node *right;

  Node()
  {
    value = T();
    freq = 0.0;
    left = nullptr;
    right = nullptr;
  }

  Node(T v, double f)
  {
    value = v;
    freq = f;
    left = nullptr;
    right = nullptr;
  }

  Node(double f, Node *l, Node *r)
  {
    freq = f;
    left = l;
    right = r;
  }
};

int readStocks(const string &fileName, Stock *&stocks, double *&freqs);
Node<Stock> *createHuffmanTree(Stock stocks[], double freqs[], int size);
void printArray(int path[], int pathLen, Node<Stock> *leaf);
void printPaths(Node<Stock> *node, int path[], int pathLen, int lr);
void displayStockList(Node<Stock> *rootPtr, const string &sentence);

int readStocks(const string &fileName, Stock *&stocks, double *&freqs)
{
  ifstream fin(fileName);
  if (!fin)
  {
    cout << "File not found: " << fileName << "\n";
    return 0;
  }

  int count = 0;
  fin >> count;
  if (!fin || count <= 0)
  {
    cout << "Invalid count.\n";
    return 0;
  }

  fin.ignore(10000, '\n');

  stocks = new Stock[count];
  freqs = new double[count];

  string name,
      symbol;
  double price,
      freq;

  for (int i = 0; i < count; i++)
  {
    if (!getline(fin, name))
    {
      cout << "Error reading name at index " << i << "\n";
      return i;
    }
    if (!getline(fin, symbol))
    {
      cout << "Error reading symbol at index " << i << "\n";
      return i;
    }
    fin >> price;
    fin >> freq;
    if (!fin)
    {
      cout << "Error reading price/frequency at index " << i << "\n";
      return i;
    }
    fin.ignore(10000, '\n');

    stocks[i] = Stock(name, symbol, price);
    freqs[i] = freq;
  }

  return count;
}

Node<Stock> *createHuffmanTree(Stock stocks[], double freqs[], int size)
{
  if (size <= 0)
  {
    return nullptr;
  }

  Node<Stock> **elements = new Node<Stock> *[size];

  for (int i = 0; i < size; ++i)
  {
    elements[i] = new Node<Stock>;
    elements[i]->value = stocks[i];
    elements[i]->freq = freqs[i];
    elements[i]->left = nullptr;
    elements[i]->right = nullptr;
  }

  int index1;
  int index2;
  double freq1;
  double freq2;

  while (size > 1)
  {
    index1 = index2 = 0;
    freq1 = freq2 = numeric_limits<double>::max();
    for (int i = 0; i < size; i++)
    {
      if (elements[i]->freq < freq1)
      {
        freq2 = freq1;
        index2 = index1;
        freq1 = elements[i]->freq;
        index1 = i;
      }
      else if ((elements[i]->freq < freq2) && (i != index1))
      {
        freq2 = elements[i]->freq;
        index2 = i;
      }
    }
    Node<Stock> *newNode;
    newNode = new Node<Stock>;
    newNode->left = elements[index1];
    newNode->right = elements[index2];
    newNode->freq = freq1 + freq2;
    elements[index1] = newNode;
    for (int i = index2; i < size - 1; ++i)
    {
      elements[i] = elements[i + 1];
    }
    size--;
  }

  Node<Stock> *root = elements[0];
  delete[] elements;
  return root;
}

void printArray(int path[], int pathLen, Node<Stock> *leaf)
{

  cout << leaf->value.getSymbol() << ": ";
  {
    for (int i = 0; i < pathLen; i++)
    {
      cout << path[i];
    }
  }
  cout << '\n';
}

void printPaths(Node<Stock> *node, int path[], int pathLen, int lr)
{
  if (node != nullptr)
  {
    if (lr != -1)
    {
      path[pathLen] = lr;
      pathLen++;
    }
    if ((node->left == nullptr) && (node->right == nullptr))
    {
      printArray(path, pathLen, node);
    }
    else
    {
      printPaths(node->left, path, pathLen, 0);
      printPaths(node->right, path, pathLen, 1);
    }
  }
}

void displayStockList(Node<Stock> *rootPtr, const string &sentence)
{
  if (rootPtr)
  {
    Node<Stock> *current = rootPtr;

    for (int i = 0; i < sentence.size(); ++i)
    {
      char c = sentence[i];

      if (c == '0' || c == '1')
      {
        if (c == '0')
        {
          current = current->left;
        }
        else
        {
          current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr)
        {
          cout << current->value.getName() << '\n';
          current = rootPtr;
        }
      }
    }
  }
}

int main()
{
  Stock *stocks = nullptr;
  double *freqs = nullptr;

  int size = readStocks("HuffmanStocks.txt", stocks, freqs);
  if (size <= 0)
  {
    cout << "Nothing to process.\n";
    return 0;
  }

  Node<Stock> *root = createHuffmanTree(stocks, freqs, size);

  int path[100];
  cout << "Huffman Codes (symbol: code)\n";
  printPaths(root, path, 0, 0);

  string sentence = "";
  if (!sentence.empty())
  {
    cout << "\nStocks:\n";
    displayStockList(root, sentence);
  }

  delete[] stocks;
  delete[] freqs;

  return 0;
}

