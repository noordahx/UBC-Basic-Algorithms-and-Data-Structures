/**
 *
 * shifty quadtree (pa3)
 * sqtree.cpp
 * This file will be used for grading.
 *
 */

#include "sqtree.h"

// First Node constructor, given.
SQtree::Node::Node(pair<int,int> ul, int w, int h, RGBAPixel a, double v)
  :upLeft(ul),width(w),height(h),avg(a),var(v),NW(NULL),NE(NULL),SE(NULL),SW(NULL)
{}

// Second Node constructor, given
SQtree::Node::Node(stats & s, pair<int,int> ul, int w, int h)
  :upLeft(ul),width(w),height(h),NW(NULL),NE(NULL),SE(NULL),SW(NULL) {
  avg = s.getAvg(ul,w,h);
  var = s.getVar(ul,w,h);
}

// SQtree destructor, given.
SQtree::~SQtree() {
  clear();
}

// SQtree copy constructor, given.
SQtree::SQtree(const SQtree & other) {
  copy(other);
}

// SQtree assignment operator, given.
SQtree & SQtree::operator=(const SQtree & rhs) {
  if (this != &rhs) {
    clear();
    copy(rhs);
  }
  return *this;
}

/**
 * SQtree constructor given tolerance for variance.
 */
SQtree::SQtree(PNG & imIn, double tol) {
  // Your code here.
  stats s = stats(imIn);
  root = &Node(s, make_pair(0,0), imIn.width(), imIn.height());
  // for (unsigned int i = 0; i < imIn.width(); i++) {
  //   for (unsigned int j = 0; j < imIn.height(); j++) {
  //     pair<int,int> ul = make_pair(i,j);
  //     int w = imIn.width() - i;
  //     int h = imIn.height() - j;
  //     buildTree(s, ul, w, h, tol);
  //   }
  // }Node 
}

/**
 * Helper for the SQtree constructor.
 */
SQtree::Node * SQtree::buildTree(stats & s, pair<int,int> & ul,
				 int w, int h, double tol) {
  // Your code here.
  // for (unsigned int i = 0)
}
  
/**
 * Render SQtree and return the resulting image.
 */
PNG SQtree::render() {
  // Your code here.
}

/**
 * Delete allocated memory.
 */
void SQtree::clear() {
  // Your code here.
}

void SQtree::copy(const SQtree & other) {
  // Your code here.
}

int SQtree::size() {
  // Your code here.
}

