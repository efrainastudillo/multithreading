//
//  c_thread.cpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/5/20.
//

#include "c_thread.hpp"
#include <pthread.h>
#include <iostream>
#include <exception>

#include <errno.h>

c_thread::c_thread(c_runnable* _runnable){
    c_thread::runnable = _runnable;
    assert(_runnable);
    if(runnable == nullptr){
        print_error("Runnable should not be NULL", -1, __FILE__, __LINE__);
        throw std::invalid_argument("Runnable should not be NULL");
    }
}

c_thread::~c_thread(){}

void c_thread::print_error(const std::string& _msg, int _status,const std::string& _filename, int _linenumber){
    std::cout << "Error: " << _msg << " status: " << _status << " " << _filename << ":" << _linenumber << std::endl;
}
void c_thread::start(){
    int res = pthread_create(&thread_id, NULL, c_thread::start_thread_runnable, (void*)this);
    if( res != 0 ) {
        print_error(strerror(errno), res, __FILE__, __LINE__);
    }
}

void* c_thread::start_thread_runnable(void* pVoid) {
    if(!pVoid)
    {
        throw std::invalid_argument("Argument invalid: Should not be Null.");
    }
    
    c_thread* priv = (c_thread*)pVoid;
    priv->result = priv->runnable->run(); // it's executed sync (just in case)
    return priv->result;
}

void* c_thread::join(){
    pthread_join(thread_id, &result);
    return result;
}
