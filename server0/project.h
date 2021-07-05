#ifndef PROJECT_H_
#define PROJECT_H_
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>

#define SIP     "192.168.0.139"
#define SPORT   5000

struct mess{
        int  action;      /* --->1: login in, 2: login out, 3: send message*/
        char obj_act[11]; /* object account                                */
        char data[256];   /* main data                                     */
};

#endif
