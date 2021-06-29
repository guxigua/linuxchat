#include "include/project.h"

int main()
{
	struct user_info *head = NULL;
	struct user_info *tail = NULL;
	struct user_info *tmp = NULL;
	struct user_info *quit_sfd =  NULL;

	int sfd =       socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_message;
        server_message.sin_family      = AF_INET;
        server_message.sin_port        = htons(SPORT);
        server_message.sin_addr.s_addr = inet_addr(SIP);

	if( bind(sfd, (struct sockaddr *)&server_message,
                                sizeof(server_message)) == -1)
		printf("bind error\n");
	        if((listen(sfd, 50)) == -1)
			printf("listen error\n");

	while(1){
		if(head == NULL){
			head = (struct user_info *)malloc(sizeof(struct user_info));
			tmp  = tail = head;
		}else{
			tmp        = (struct user_info *)malloc(sizeof(struct user_info));
			tail->next = tmp;
			tail       = tmp;
		}
		if( (tmp->sfd = recv_connect(sfd)) < 0)
			continue;
		 quit_sfd = pthread_create(&(tail->pid_t), NULL, deal_with, tail);
	}
	return 0;
}
