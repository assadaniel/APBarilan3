//
// Created by User on 27/08/2022.
//

#include "ThreadCLI.h"

#include <utility>
#include <iostream>

void *ThreadCLI::start_function(void *obj) {
    ((ThreadCLI*)obj)->cli.start();
    return NULL;
}

bool ThreadCLI::start_thread() {
    valid = (pthread_create(&_thread, &attr, start_function, this) == 0);
    return valid;
}

void ThreadCLI::wait_for_thread_to_exit() const {
    pthread_join(_thread, NULL);
}

ThreadCLI::ThreadCLI(DefaultIO& dio):  dio(dio), cli(dio), _thread(), attr() {
    pthread_attr_init(&attr);
}

ThreadCLI::~ThreadCLI() {
    if(valid) {
        pthread_join(_thread, NULL);
        valid = false;
    }
}
