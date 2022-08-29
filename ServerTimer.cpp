//
// Created by User on 29/08/2022.
//

#include "ServerTimer.h"
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
typedef struct argst {
    void* object;
    int& cs;
} argst;


ServerTimer::ServerTimer(SocketFileServer &SFS): SFS(SFS){
    pthread_attr_init(&attr);
}

void *ServerTimer::accept(void *obj) {
    argst* par = (argst*)obj;
    ServerTimer * s = (ServerTimer*)(par->object);
    par->cs = (s->SFS).accept();
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

bool ServerTimer::start(int &cs) {
    argst obj = {NULL, cs};
    obj.object = this;
    pthread_create(&t1, &attr, accept, &obj);
    pthread_mutex_lock(&mutex);
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    t.tv_sec+=seconds;
    int wait_r = pthread_cond_timedwait(&condition, &mutex, &t);
    if(wait_r == ETIMEDOUT) {
        cs = -1;
        pthread_cancel(t1);
        pthread_mutex_unlock(&mutex);
        return false;
    }
    pthread_mutex_unlock(&mutex);
    pthread_join(t1,0);
    return true;



}

int ServerTimer::getSeconds() const {
    return seconds;
}
