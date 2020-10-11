//
//  linkedlist.hpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/5/20.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <iostream>
#include <sstream>
#include <string>
#include <pthread.h>
#include <exception>
#include "c_error.h"

/**
 \brief I need that this Linked List must be thread Safe
 */
//template<typename T>
class LinkedList {
public:
    // Constructor
    LinkedList();
    virtual ~LinkedList();
    
    /**
     \brief Append a Node to the front of the list
     \param _value Value to save in front of the list
     */
    void push(int _value);
    /**
     \brief Get the value in front of the list and remove it
     \return the value in front of the list
     */
    int pop() ;
    /**
     \brief Check whether the buffer has reached the max_size of the list
     \return true if max_size == lenght
     */
    bool isFull() ;
    
    /**
     \return lenght of the list. Should not be greater than max_size
     */
    unsigned getLenght() const;
    
    /**
     \brief Print list
     */
    void print() const;
    /**
     Awake all thread have been blocked by condition variable
     */
    void notifyAll();
    /**
     Block a thread waiting for a condition been committed
     */
    void wait();
    
private:
    pthread_mutex_t mutex;          //!< Sincronize access to the list by threads
    pthread_mutex_t m_mutex_full;   //!< Mutex to block the buffer when full limit is reached.
    pthread_cond_t  m_cond_full;    //!< The condition to unlock m_mutex_full is when 5 nodes have removed from the list at least
    
    unsigned max_size; //!< Max size of the Nodes in the list
    
    struct _Node {
        int value;
        _Node * next;
    };
    unsigned lenght; //!< current lenght of the nodes in the list
    _Node* back; //going to be implemted later
    _Node* current;

    /**
     \brief Create a new Node to be added to the list
     \return the New node just created
     */
    _Node* _createNode();
};
#endif /* linkedlist_hpp */

