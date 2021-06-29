#include "include/function.h"

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
	if(!ret)
		printf("login successful!\n");
	else
		printf("the account or passwd is error\n");

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
			if(login_out(sfd))
				printf("error quit\n");
			else
				i=0;
			break;
		default:
			printf("no %d choose is\n", choose);
			break;

		}
	}
	close(sfd);
	return 0;
}
