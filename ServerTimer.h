//
// Created by User on 29/08/2022.
//

#ifndef APBARILAN3_SERVERTIMER_H
#define APBARILAN3_SERVERTIMER_H


#include <atomic>
#include "Sockets/Server/SocketFileServer.h"
extern pthread_mutex_t mutex;
extern pthread_cond_t condition;
class ServerTimer {
private:
    pthread_t t1{};
    pthread_attr_t attr{};
    SocketFileServer& SFS;
    int seconds = 60;
public:
    ServerTimer(SocketFileServer& SFS);
    static void* accept(void* obj);
    bool start(int&cs);

    int getSeconds() const;

};


#endif //APBARILAN3_SERVERTIMER_H
