//
// Created by User on 27/08/2022.
//

#include "ThreadCLI.h"

#include <utility>
#include <iostream>

/**
 * @brief Starting the function.
 * 
 * @param obj Obj is being changed into ThreadCLI pointer and used to access the start function.
 * @return void* Returning null.
 */
void *ThreadCLI::start_function(void *obj) {
    ((ThreadCLI*)obj)->cli.start();
    return NULL;
}

/**
 * @brief Starting a thread.
 * 
 * @return true Checking if starting the thread worked.
 * @return false Checking if starting the thread worked.
 */
bool ThreadCLI::start_thread() {
    valid = (pthread_create(&_thread, &attr, start_function, this) == 0);
    return valid;
}

/**
 * @brief Waiting for the thread to exit.
 * 
 */
void ThreadCLI::wait_for_thread_to_exit() const {
    pthread_join(_thread, NULL);
}

/**
 * @brief Construct a new ThreadCLI:: ThreadCLI object.
 * 
 * @param dio The defaultIO.
 */
ThreadCLI::ThreadCLI(DefaultIO& dio):  dio(dio), cli(dio), _thread(), attr() {
    pthread_attr_init(&attr);
}

/**
 * @brief Destroy the ThreadCLI:: ThreadCLI object.
 * 
 */
ThreadCLI::~ThreadCLI() {
    if(valid) {
        pthread_join(_thread, NULL);
        valid = false;
    }
}
