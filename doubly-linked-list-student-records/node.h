#ifndef NODE_H
#define NODE_H

template <typename TYPE>
struct Node
{
  TYPE data;
  Node<TYPE> *next;
  Node<TYPE> *prev;
  Node();
  Node(const TYPE &dat, Node<TYPE> *nex = nullptr, Node<TYPE> *prv = nullptr);
};

template <typename TYPE>
Node<TYPE>::Node()
{
  next = nullptr;
  prev = nullptr;
}

template <typename TYPE>
Node<TYPE>::Node(const TYPE &dat, Node<TYPE> *nex, Node<TYPE> *prv)
{
  data = dat;
  next = nex;
  prev = prv;
}

#endif
