#ifndef FUNCTION_H_
#define FUNCTION_H_
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
struct send_data
{
	int action;   	    	/*动作标志*/
	int flag;		/*是否传输完毕, 0未完，1完成*/
	char account[11];	/*账号*/
	char obj_account[11];   /*对方账号*/
	char data[256];         /*数据*/
};

int connect_status(const char *ip, unsigned short port);
/*判断是否能连接上服务器, 成功返回0, 失败 > 0 */

int login_status(char *account, char *passwd, int cfd);
/*判断账号密码是否正确, 成功返回0, 失败 > 0 */

int send_mess(int cfd, char *account);
/*发送信息*/

#endif
