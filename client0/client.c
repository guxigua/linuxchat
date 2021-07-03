#include "project.h"

int main(int argc, char * argv[])
{
	char mar[16]="1";
	int cfd;
	int ret;

	if(argc != 3){
		printf("Enter the account and password for termail");
		exit(1);
	}

	/*连接*/
	cfd = connect_status(SIP, SPORT);
	if(!cfd){
                printf("\nconnect is fail, Is about to quit\n");
                return 1;
        }
	

	while(mar[0]){
		printf("0: quit\n1: login\n2: login out\n3: send message\n");
		scanf("%[^\n]", mar);
		switch(mar[0]){
		case '0':
			mar[0] = 0;
			break;
		case '1':
			ret = login_action(argv[1], argv[2], cfd, 'i');
			if(ret < 0)
				printf("login in fail\n");
			else
				printf("login successful\n");
			break;
		case '2':
			ret = login_action(NULL, NULL, cfd, 'o');
			if(ret < 0)
				printf("login out fail\n");
			else
				printf("login out successful\n");
			break;
		case '3':
			send_mess();
			break;
		default:
			printf("Enter the Correct instruction!\n");
			break;
		}
	}
	close(cfd);
	return 0;
}
