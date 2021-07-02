#include "include/project.h"

int main()
{
	signal(SIGINT, close_fun);
	pthread_mutex_t  *mutex   = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_t  *mutexrw = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex, NULL);
	pthread_mutex_init(mutexrw, NULL);

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
	int i=1;
	int sfd_tmp=0;

	while(1){
		if( (sfd_tmp = recv_connect(sfd)) < 0)
			continue;
		if(head == NULL){
			head = (struct user_info *)malloc(sizeof(struct user_info));
			head->pre   = NULL;
			head->next  = NULL;
			head->mutex = &mutex;
			head->mutexrw = mutexrw;
			head->sfd   = sfd_tmp;
			tmp  = tail = head;
		}else{
			pthread_mutex_lock(mutex);
			tmp        = (struct user_info *)malloc(sizeof(struct user_info));
			tmp->next  = NULL;
			tmp->sfd   = sfd_tmp;
			tmp->pre   = tail;
			tmp->mutex = &mutex;
			tmp->mutexrw = mutexrw;
			tail->next = tmp;
			tail       = tmp;
			pthread_mutex_unlock(mutex);
		}
		pthread_create(&(tail->pid_t), NULL, deal_with, tail);
	}
	return 0;
}
