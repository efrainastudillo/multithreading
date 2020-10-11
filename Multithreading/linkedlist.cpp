//
//  linkedlist.cpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/5/20.
//

#include "linkedlist.hpp"

// Constructor
LinkedList::LinkedList() : max_size(100){
    if( pthread_mutex_init(&mutex, NULL) ) {
        throw_runtime_error_message("Error Initializing Mutex: [%d] > %s", errno, strerror(errno));
    }
    
    current = nullptr;
    lenght = 0;
    // it's going to be implemented later
    back = nullptr;
}

LinkedList::~LinkedList(){
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
void LinkedList::push(int _value) {
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
int LinkedList::pop() {
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
bool LinkedList::isFull() {
    return lenght == max_size;
}
unsigned LinkedList::getLenght() const { return lenght; }

void LinkedList::print() const {
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

LinkedList::_Node* LinkedList::_createNode(){
    _Node* node = new _Node;
    node->next = nullptr;
    return node;
}

void LinkedList::notifyAll() {
    
}
/**
 Block a thread waiting for a condition been committed
 */
void LinkedList::wait() {
    
}
