#include "include/function.h"

#define SIP 	"192.168.0.139"
#define SPORT	5006

/**
 * 动作：(0-99)
 * 	0: 连接(自动);
 *	1: 登入
 *	2: 发送信息
 *	3: 查看聊天记录
 *	4: 退出
 * 
 *
 * 全局变量:
 * */

int main(int argc, char * argv[])
{

	int sfd;
	char account[16] = "";
	int choose;
	int i=1;
	strcpy(account, argv[1]);

	/*连接*/
	sfd = connect_status(SIP, SPORT);
	if(!sfd){
		printf("\nconnect is fail, Is about to quit\n");
		return 1;
	}

	/*登入*/
	int ret = login_status(argv[1], argv[2], sfd);
	if(!ret){
		printf("the account or passwd is error\n");
	}

	while(i)
	{
		printf("2:发送信息\n3:查看信息\n4:退出\n");
		scanf("%d", &choose);
		switch(choose){
		case 2:
			send_mess(sfd, account);
			break;
		case 3:
			break;
		case 4:
			i=0;
			break;
		default:
			printf("no %d choose is\n", choose);
			break;

		}
	}
	close(sfd);
}
