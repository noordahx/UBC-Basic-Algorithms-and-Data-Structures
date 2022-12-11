/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file, as well as binarytree.h.
 */

#include <iostream>

using namespace std;

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function, with an additional
 * Node* parameter to allow for recursive calls. NOTE: use this as an example
 * for writing your own private helper functions.
 * @param subRoot
 * @return The height of the subtree.
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Your code here
    if (root != NULL)
      printLeftToRightHelper(root);
    // Do not remove this line - used for correct print output
    cout << endl;
}

template <typename T>
void BinaryTree<T>::printLeftToRightHelper(const Node *subRoot) const{
  if (subRoot != NULL) {
    printLeftToRightHelper(subRoot->left);
    cout << to_string(subRoot->elem) << " ";
    printLeftToRightHelper(subRoot->right);
  }
}

template <typename T>
void BinaryTree<T>::invert(Node* subRoot) const {
  if (subRoot != NULL) {
    invert(subRoot->left);
    invert(subRoot->right);

    struct Node* temp = subRoot->left;
    subRoot->left = subRoot->right;
    subRoot->right = temp; 
  }
}

template <typename T>
void BinaryTree<T>::paths(Node* subRoot, T arr[], int height) const {
  if (subRoot != NULL) {
    arr[height] = subRoot->elem;
    height++;

    if (subRoot->left == NULL && subRoot->right == NULL) {
      printArr(arr, height);
    }
    else {
      paths(subRoot->left, arr, height);
      paths(subRoot->right, arr, height);
    }
  }
}
template <typename T>
int BinaryTree<T>::sumDistances(Node * subRoot, int depth) const {
  if (subRoot == NULL) {
    return 0;
  } else {
  return depth + sumDistances(subRoot->left, depth+1) + sumDistances(subRoot->right, depth+1);
  }
}


template <typename T>
void BinaryTree<T>::printArr(T arr[], int height) const{
  cout << "Path: ";
  for (int i = 0; i < height; i++) {
    cout << to_string(arr[i]) << " ";
  }
  cout << endl;
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 * (i.e. not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    // Your code here
    invert(root);
}

/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards,
 * ending at a leaf node. Paths ending in a left node should be printed before
 * paths ending in a node further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
  // Your code here
  T arr[1000];
  int height = 0;
  paths(root,arr,height);

}

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root.
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
  // Your code here
  return sumDistances(root, 0);
}

/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
  // Your code here
  vector<T> result;
  vectorize(root, result);
  
  return is_sorted(result.begin(), result.end());
}

template <typename T>
void BinaryTree<T>::vectorize(Node * subRoot, vector<T> &result) const {
  if (!subRoot) {
    vectorize(subRoot->left, result);
    result.push_back(subRoot->elem);
    vectorize(subRoot->right, result);
  }
}