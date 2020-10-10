//
//  c_error.c
//  Multithreading
//
//  Created by Efrain Astudillo on 10/10/20.
//

#include "c_error.h"
#include <iostream>
#include <cstdarg>
void throw_runtime_error_message(const char* const msg, ...){
    char message[512];
    va_list args;
    
    va_start(args, msg);
    
    sprintf(message, msg, args);
//    while (*msg != '\0') {
//
//    }
    
    va_end(args);
    throw std::runtime_error(message);
}
