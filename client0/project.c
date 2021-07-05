#include "project.h"

int connect_status(const char *ip, unsigned short port)
{
        int cfd;

        if((cfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
                perror("the function of socket is:");
                return 0;
        }

        struct sockaddr_in client_mess;
        client_mess.sin_family = AF_INET;
        client_mess.sin_port = htons(port);
        client_mess.sin_addr.s_addr = inet_addr(ip);

        if(connect(cfd, (struct sockaddr *)&client_mess,
                                sizeof(client_mess)) == -1){
                perror("the function of connect is:");
                return 0;
        }
        return cfd;
}

int login_action(char *obj_act, char *passwd, int cfd, char action)
{
	struct mess tmp;
	if(action == 'i'){
		tmp.action = 1;
		strcpy(tmp.obj_act, obj_act);
		strcpy(tmp.data, passwd);
	}else{
		tmp.action = 2;
	}

	int lcsize = write(cfd, &tmp, sizeof(struct mess));
	if(lcsize  == -1)
		return -1;
	return 0;

}
void *recv_svr(void *cfd)
{
	struct mess localms;
	int *fd = (int*)cfd;
	int cotrd = 0;

	while(1){
		cotrd = read(*fd, &localms, sizeof(struct mess));
		if(cotrd  ==  -1){
			perror("Read failure");
		}else{
			switch(localms.action){
			case 1:{
				if(localms.data[0] == 'y')
					printf("\nLogin successful\n");
				else
					printf("\nlogin failed\n");
				break;
				}
			case 2:{
					if(localms.data[0] == 'y')
					printf("\nLogin out successful\n");
				else
					printf("\nlogin out failed\n");
				break;
				}
			case 3:{
				printf("\n%s sent a message to you,\
					       	the content is \n");
				break;
			       }
			default:{
			       break;
				}
			}
		}
	}
	return NULL;
}

void send_mess(){}
