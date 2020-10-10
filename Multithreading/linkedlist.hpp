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

/**
 \brief I need that this Linked List must be thread Safe
 */
//template<typename T>
class LinkedList {

public:
    // Constructor
    LinkedList() : max_size(100){
        if( pthread_mutex_init(&mutex, NULL) )
        {
            char message[256];
            sprintf(message, "Error Initializing Mutex: [%d] > %s", errno, strerror(errno));
            throw std::runtime_error(message);
        }
        current = nullptr;
        lenght = 0;
        // it's going to be implemented later
        back = nullptr;
    }
    
    virtual ~LinkedList(){
        pthread_mutex_lock(&mutex);
        std::cout << "LinkedList is being deleted..." << std::endl;
        
        _Node* temp = current;
        while(temp){
            current = current->next;
            std::cout << "deleting: " << temp->value << " ..." << std::endl;
            delete temp;
            temp = current;
        }
        pthread_mutex_unlock(&mutex);
        pthread_mutex_destroy(&mutex);
    }
    
    /**
     \brief Append a Node to the front of the list
     \param _value Value to save in front of the list
     */
    void push(int _value){
        pthread_mutex_lock(&mutex);
        _Node* node = _createNode();
        node->value = _value;
        node->next = current;
        current = node;
        lenght++;
        std::cout << "Produced: " << _value << std::endl;
        pthread_mutex_unlock(&mutex);
    }
    /**
     \brief get the value in front of the list and remove it
     \return the value in front of the list
     */
    int pop() {
        pthread_mutex_lock(&mutex);
        _Node* temp = current;
        int value = temp->value;
        current = current->next;
        delete temp;
        lenght--;
        std::cout << "Consumed: " << value << std::endl;
        pthread_mutex_unlock(&mutex);
        return value;
    }
    bool isFull() {
        return lenght == max_size;
    }
    unsigned getLenght() const { return lenght; }
    
    void print() const {
        std::stringstream ss;
        ss << "[ ";
        _Node* temp = current;
        while(temp){
            ss << temp->value;
            temp = temp->next;
            if(temp)
                ss << ", ";
        }
        ss << " ]";
        std::cout << ss.str() << " size: "<< lenght << std::endl;
    }
    
private:
    pthread_mutex_t mutex;
    unsigned max_size;
    struct _Node {
        int value;
        _Node * next;
    };
    unsigned lenght;
    _Node* back; //going to be implemted later
    _Node* current;
    
    _Node* _createNode(){
        _Node* node = new _Node;
        node->next = nullptr;
        return node;
    }
};
#endif /* linkedlist_hpp */

