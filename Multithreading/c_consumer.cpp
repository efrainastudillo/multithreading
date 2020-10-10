//
//  c_consumer.cpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/10/20.
//

#include "c_consumer.hpp"


Consumer::Consumer(LinkedList* _list){
    time_t t;
    srand((unsigned)time(&t));
    buffer = _list;
}
Consumer::~Consumer(){}
int Consumer::consume() {
    int number = 100 + rand() % 1000;
    buffer->pop();
    return number;
}
//    Consumer(const Consumer&) = default;
void* Consumer::run() {
    while(true){
        if( buffer->getLenght() > 0 ) {
            usleep(consume());
        }
    }
    return  nullptr;
}
