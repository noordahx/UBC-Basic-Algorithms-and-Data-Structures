#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    /* YOUR CODE HERE */
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
    /* YOUR CODE HERE */
    
    Node* curr = head_;
    while(curr->next != head_) {
        curr = curr->next;
    }

    Node* ins = new Node(ndata);
    curr->next = ins;
    ins->next = head_;
    length_++;

}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
/* YOUR CODE HERE */
    Node* pre_i = walk(head_,i-1);
    Node* pre_j = walk(head_,j-1);
    Node* temp;
    temp = pre_i->next;
    pre_i->next = pre_j->next;
    pre_j->next =temp;
    pre_i = pre_i->next;
    pre_j = pre_j->next;
    temp = pre_i->next;
    pre_i->next = pre_j->next;
    pre_j->next =temp;
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
/* YOUR CODE HERE */
    Node* prev = head_;
    Node* curr = head_->next;
    Node* next = head_->next->next;
    
    while (curr != head_) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    
    head_->next = prev;
}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
           b a c d e
           b c a d e
           b c d a e

*/
void Chain::rotate(int k)
{
/* YOUR CODE HERE */
    int idx = 1;
    for (int i = 1; i <= length_; i++) {
        if (idx < k) {
            swap(i, i+1);
            idx++;
        } else  {
            idx = 1;
            if (length_ - i < k) 
                {break;}
        }
    }
}

/**
 * Destroys ALL dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    /* YOUR CODE HERE */
    Node* curr = head_;
    while (curr->next != head_) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete curr;
    head_ = NULL;
    length_ = 0;
    height_ = 0;
    width_ = 0;


}

/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
/* YOUR CODE HERE */
    length_ = other.length_;
    width_ = other.width_;
    height_ = other.height_;
    head_ = new Node();
    head_->next = head_;
    Node * curr = other.head_->next;
    while (curr != other.head_) {
        insertBack(curr->data);
        curr = curr->next;
    }


}
