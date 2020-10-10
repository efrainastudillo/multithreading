//
//  c_consumer.hpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/10/20.
//

#ifndef c_consumer_hpp
#define c_consumer_hpp

#include <stdio.h>
#include "c_thread.hpp"
#include "linkedlist.hpp"

class Consumer : public c_runnable {
public:
    Consumer(LinkedList* _list);
    virtual ~Consumer();
    int consume();
    virtual void* run();
    
private:
    LinkedList* buffer;
};


#endif /* c_consumer_hpp */
