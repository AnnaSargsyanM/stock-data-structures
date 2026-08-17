#ifndef NODE_H
#define NODE_H

template <typename TYPE>
struct Node
{
  TYPE data;
  Node<TYPE> *next;
  Node();
  Node(const TYPE &dat, Node<TYPE> *nex = nullptr);
};

template <typename TYPE>
Node<TYPE>::Node()
{
  next = nullptr;
}

template <typename TYPE>
Node<TYPE>::Node(const TYPE &dat, Node<TYPE> *nex)
{
  data = dat;
  next = nex;
}

#endif
