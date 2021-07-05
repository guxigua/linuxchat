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
	int  action;	  /* --->1: login in, 2: login out, 3: send message*/
	char obj_act[11]; /* object account			           */
	char data[256];   /* main data				           */
};

int login_action(char *obj_act, char *passwd, int cfd, char action);
/* action: 'i': login in, 'o': login out
 * 
 * 成功返回值0, 失败返回值 < 0*/

int connect_status(const char *ip, unsigned short port);
/*连接状态*/

void *recv_svr(void *cfd);
/*接受服务器数据现线程函数*/

void send_mess();


#endif
