//
//  c_producer.cpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/10/20.
//

#include "c_producer.hpp"

Producer::Producer(LinkedList* _list){
    time_t t;
    srand((unsigned)time(&t));
    buffer = _list;
}
int Producer::produce() {
    int number = 200 + rand() % 1000;
    buffer->push(number);
    return number;
}
void* Producer::run() {
   while(true){
       if(buffer->isFull())
       {}
       else{}
       usleep(produce());
   }
   return nullptr;
}
