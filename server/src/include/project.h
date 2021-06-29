#ifndef PROJECT_H_
#define PROJECT_H_

#include <pthread.h>
#include <mysql/mysql.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define SIP "192.168.0.139"
#define SPORT 5000

struct send_data{
	int action;
	int flag;
	char account[11];
	char obj_account[11];
	char data[256];
};
/*数据包结构体*/

struct user_info
{
        int sfd;
        char account[11];
        char status;
	pthread_t  pid_t;
	struct user_info *next;
};
/*用户信息*/


int recv_connect();
/* return value:
 *
 * value > 0 : successful
 *
 * -1: socket error
 * -2: bind error
 * -3: listen error
 * -4: accept error
 */

void *deal_with(void *args);



#endif
