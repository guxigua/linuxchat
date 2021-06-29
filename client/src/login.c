#include "include/function.h" 

int login_status(char *account,char *passwd, int cfd)
{
	struct send_data login_data;
	login_data.action = 1;
	strcpy(login_data.account, account);
	strcpy(login_data.data,    passwd);

	if(write(cfd, &login_data, sizeof(login_data)) == -1)
		return 1;
	memset(&login_data, 0, sizeof(struct send_data));
	while(1){
		if(read(cfd, &login_data, sizeof(struct send_data)) > 0){
			if(login_data.action == 1 && login_data.data[0] == 'y')
				return 0;
			else
				return 1;
		}
	}
	return 1;
}

int connect_status(const char *ip, unsigned short port)
{
	int sfd;

	if((sfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("the function of socket is:");
		return 0;
	}

	struct sockaddr_in client_mess;
	client_mess.sin_family = AF_INET;
	client_mess.sin_port = htons(port);
	client_mess.sin_addr.s_addr = inet_addr(ip);

	if(connect(sfd, (struct sockaddr *)&client_mess,
				sizeof(client_mess)) == -1){
		perror("the function of connect is:");
		return 0;
	}
	return sfd;
}
int send_mess(int cfd, char *account)
{
	struct send_data mess;
	mess.action = 2;
	strcpy(mess.account, account);
	memset(mess.obj_account, 0, 11);
	memset(mess.data, 0, 256);
	printf("Enter the account to which you want to send data\n");
	scanf("%s", mess.obj_account);
	printf("Enter the message\n");
	scanf("%[^\n]", mess.data);
	if(write(cfd, &mess, sizeof(mess)) == -1)
		return 1;
	return 0;
}

int login_out(int cfd)
{
	struct send_data tmp;
	tmp.action = 4;
	return write(cfd, &tmp, sizeof(struct send_data)) == -1 ?  -1 : 0;
}
