//
// Created by User on 27/08/2022.
//

#ifndef APBARILAN3_THREADCLI_H
#define APBARILAN3_THREADCLI_H


#include <pthread.h>
#include "CLI.h"

class ThreadCLI {
private:
    pthread_t _thread;
    pthread_attr_t attr;
    bool valid{};
    static void* start_function(void* obj);
    CLI cli;
    DefaultIO& dio;
public:
    ThreadCLI( DefaultIO& dio);
    bool start_thread();
    void wait_for_thread_to_exit();
    ~ThreadCLI();
};


#endif //APBARILAN3_THREADCLI_H
