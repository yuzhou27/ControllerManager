//
//  controller.c
//  Controller
//
//  Created by yuzhou on 16/4/10.
//  Copyright © 2016年 edu.self. All rights reserved.
//

#include "controller.h"
#include <pthread.h>
#include <unistd.h>
#include <poll.h>

static int pipe_fds[2];

static void *eventLoop(void *arg) {
    FUNCTION_ENTER;
    
    while(1) {
        
    }
    return NULL;
}

static void createControllerThread() {
    int err;
    pthread_t pid;
    err = pthread_create(&pid, NULL, eventLoop, NULL);
    if (err == 0) {
        pthread_join(pid, NULL);
    } else {
        printf("Thread cant create\n");
    }
}

static void createPipe() {
    int result = pipe(pipe_fds);
    if (result < 0) {
        printf("Create pipe failure\n");
    }
}

int *getReadFd() {
    return &pipe_fds[0];
}

int *getWriteFd() {
    return &pipe_fds[1];
}

static void closePipe() {
    close(pipe_fds[0]);
    close(pipe_fds[1]);
}

void createController() {
    FUNCTION_ENTER;
    
    createPipe();
    createControllerThread();
    
    FUNCTION_EXIT;
}