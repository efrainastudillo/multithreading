//
//  c_producer.hpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/10/20.
//

#ifndef c_producer_hpp
#define c_producer_hpp

#include <stdio.h>
#include "c_thread.hpp"
#include "linkedlist.hpp"

class Producer : public c_runnable {
public:
    Producer(LinkedList* _list);
    ~Producer(){}
    
private:
    LinkedList* buffer;
    
    int produce();
    virtual void* run();
};
#endif /* c_producer_hpp */
