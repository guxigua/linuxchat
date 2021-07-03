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

	lcsize == read(cfd, &tmp, sizeof(struct mess));
	if(lcsize == -1)
		return -2;

	/*如果成功，那么data里面第一个字符为y*/
	if((tmp.action == 1 || tmp.action == 2) && tmp.data[0] == 'y') 
		return 0;
	else
		return -3;
}
void send_mess(){}
