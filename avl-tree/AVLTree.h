#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

template <typename T>
struct Node
{
  T value;
  int bFactor;
  Node<T> *left;
  Node<T> *right;
  Node(const T &v);
};

template <typename T>
Node<T>::Node(const T &v)
{
  value = v;
  bFactor = 0;
  left = nullptr;
  right = nullptr;
}

template <typename T>
class AVLTree
{
private:
  Node<T> *root;

  int height(Node<T> *r) const;
  int getBalance(Node<T> *r) const;
  void updatebFactors(Node<T> *r);
  void rotateLeft(Node<T> *&k1);
  void rotateRight(Node<T> *&k1);
  void insert(Node<T> *&r, const T &item);
  void destroy(Node<T> *&r);
  void inorder(Node<T> *r) const;
  void preorder(Node<T> *r) const;
  void postorder(Node<T> *r) const;
  T *search(Node<T> *r, const T &item) const;
  void inorder(Node<T> *r, std::ostream &out) const;

public:
  AVLTree();
  ~AVLTree();
  void destroy();
  void insert(const T &item);
  void inorder() const;
  void preorder() const;
  void postorder() const;
  int height() const;
  T *search(const T &item) const;

  void inorder(std::ostream &out) const;
};

template <typename T>
int AVLTree<T>::height(Node<T> *r) const
{
  int h = 0;

  if (r)
  {
    int lh = height(r->left);
    int rh = height(r->right);

    if (lh >= rh)
    {
      h = 1 + lh;
    }
    else
    {
      h = 1 + rh;
    }
  }

  return h;
}

template <typename T>
int AVLTree<T>::getBalance(Node<T> *r) const
{
  int balance;
  if (r == nullptr)
  {
    balance = 0;
  }
  else
  {
    balance = height(r->left) - height(r->right);
  }

  return balance;
}

template <typename T>
void AVLTree<T>::updatebFactors(Node<T> *r)
{
  if (r != nullptr)
  {
    r->bFactor = getBalance(r);
    updatebFactors(r->left);
    updatebFactors(r->right);
  }
}

template <typename T>
void AVLTree<T>::rotateLeft(Node<T> *&k1)
{
  Node<T> *k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1 = k2;
}

template <typename T>
void AVLTree<T>::rotateRight(Node<T> *&k1)
{
  Node<T> *k2 = k1->left;
  k1->left = k2->right;
  k2->right = k1;
  k1 = k2;
}

template <typename T>
void AVLTree<T>::insert(Node<T> *&r, const T &item)
{
  if (r == nullptr)
  {
    r = new Node<T>(item);
    r->value = item;
    r->left = nullptr;
    r->right = nullptr;
  }
  else
  {
    if (item < r->value)
    {
      insert(r->left, item);
    }
    else
    {
      insert(r->right, item);
    }
  }
  r->bFactor = getBalance(r);
  if (r->bFactor > 1)
  {
    if (r->left->bFactor > 0)
    {
      rotateRight(r);
    }
    else
    {
      rotateLeft(r->left);
      rotateRight(r);
    }
    updatebFactors(r);
  }
  else if (r->bFactor < -1)
  {
    if (r->right->bFactor < 0)
    {
      rotateLeft(r);
    }
    else
    {
      rotateRight(r->right);
      rotateLeft(r);
    }
    updatebFactors(r);
  }
}

template <typename T>
void AVLTree<T>::destroy(Node<T> *&r)
{
  if (!r)
    return;
  destroy(r->left);
  destroy(r->right);
  delete r;
  r = nullptr;
}

template <typename T>
void AVLTree<T>::inorder(Node<T> *r) const
{
  if (r)
  {
    inorder(r->left);
    std::cout << r->value << " (bf=" << r->bFactor << ")\n";
    inorder(r->right);
  }
}

template <typename T>
void AVLTree<T>::preorder(Node<T> *r) const
{
  if (r)
  {
    std::cout << r->value << " (bf=" << r->bFactor << ")\n";
    preorder(r->left);
    preorder(r->right);
  }
}

template <typename T>
void AVLTree<T>::postorder(Node<T> *r) const
{
  if (r)
  {
    postorder(r->left);
    postorder(r->right);
    std::cout << r->value << " (bf=" << r->bFactor << ")\n";
  }
}

template <typename T>
T *AVLTree<T>::search(Node<T> *r, const T &item) const
{
  T *found = nullptr;

  if (r)
  {
    if (item == r->value)
    {
      found = &r->value;
    }
    else if (item < r->value)
    {
      found = search(r->left, item);
    }
    else
    {
      found = search(r->right, item);
    }
  }

  return found;
}

template <typename T>
void AVLTree<T>::inorder(Node<T> *r, std::ostream &out) const
{
  if (r)
  {
    inorder(r->left, out);
    out << r->value << " (bf=" << r->bFactor << ")\n";
    inorder(r->right, out);
  }
}

template <typename T>
AVLTree<T>::AVLTree()
{
  root = nullptr;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
  destroy();
}

template <typename T>
void AVLTree<T>::destroy()
{
  destroy(root);
}

template <typename T>
void AVLTree<T>::insert(const T &item)
{
  insert(root, item);
}

template <typename T>
void AVLTree<T>::inorder() const
{
  inorder(root);
}

template <typename T>
void AVLTree<T>::preorder() const
{
  preorder(root);
}

template <typename T>
void AVLTree<T>::postorder() const
{
  postorder(root);
}

template <typename T>
int AVLTree<T>::height() const
{
  return height(root);
}

template <typename T>
T *AVLTree<T>::search(const T &item) const
{
  return search(root, item);
}

template <typename T>
void AVLTree<T>::inorder(std::ostream &out) const
{
  inorder(root, out);
}

#endif
