#ifndef PROJECT_H_
#define PROJECT_H_
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
	int  action;	  /* --->1: login in, 2: login out, 3: send message*/
	char obj_act[11]; /* object account			           */
	char data[256];   /* main data				           */
};


int login_in(char *obj_act, char *passwd, int cfd);
/* 登入, 成功返回值0, 失败返回值 < 0*/

int login_out(int cfd);
/* 退出登入, 成功返回0, 失败返回值 < 0*/

int send_mess(){}


#endif
