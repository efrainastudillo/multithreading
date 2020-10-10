//
//  main.cpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/3/20.
//

#include <iostream>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#include "linkedlist.hpp"
#include "c_thread.hpp"
#include "c_producer.hpp"
#include "c_consumer.hpp"

pthread_mutex_t _mutex;

LinkedList list;

void * execute(void* args){
    pthread_mutex_lock(&_mutex);
    std::cout << "Running Thread...." << std::endl;
    pthread_mutex_unlock(&_mutex);
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    // TODO: it should validate when buffer is empty DON'T allow consume    ::: DONE
    // TODO: Need Synchronization. mutex? semaphoro? condition variable?    ::: DONE
    // TODO: What happen if added more consumers?                           ::: DONE
    
    
    // TODO: Allow to produce until a value has reached (Check wheter is FUll buffer)  :::
    // TODO: Main thread print all data in buffer when elements are multiple of 5. i.e 5, 10, 15, 20...
    
    c_thread thread1( new Consumer(&list) );
    c_thread thread2( new Producer(&list) );
    c_thread thread3( new Producer(&list) );
    thread1.start();
    thread2.start();
    thread3.start();
    
    while(list.getLenght() < 200 )
    {
    // wait for condition variable that when there are 5 elements in the buffer print them in the console
        list.print();
    }
    
    thread1.join();
    thread2.join();
    thread3.join();
    
    std::cout << "Hello, World!\n";
    return 0;
}
