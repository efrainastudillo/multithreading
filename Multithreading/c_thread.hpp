//
//  c_thread.hpp
//  Multithreading
//
//  Created by Efrain Astudillo on 10/5/20.
//

#ifndef c_thread_hpp
#define c_thread_hpp
#include <time.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "linkedlist.hpp"
/**
 \brief Interface to inherit from this and implment the run virtual method.
 */
class c_runnable {
public:
    virtual void* run() = 0;
    virtual ~c_runnable(){}
};

/**
 \brief c_thread implements runnable interface to be able to customize any thread object
 */
class c_thread {

public:
    c_thread(c_runnable *); // to force to use a runnable instead of using an empty ocnstructor
    virtual ~c_thread();
    
    //!< Start the thread
    void start();
    void* join();
    
private:
    c_runnable* runnable;
    pthread_t thread_id; // id of the thread
    void* result; // stores return value of run()
    bool detached; // true if thread created in detached state; false otherwise pthread_attr_t threadAttribute;
//    auto_ptr<Runnable> runnable;
    c_thread(const c_thread&);
    const c_thread& operator= (const c_thread&);
//    virtual void* run() { return nullptr; }
//    static void* start_thread(void* pVoid);
    
    void set_completed();
    static void* start_thread_runnable(void* pVoid);
    void print_error(const std::string& _msg, int _status, const std::string& _filename, int _linenumber);
};

#endif /* c_thread_hpp */
