#include "include/project.h"

int main()
{
	struct user_info *head = NULL;
	struct user_info *tail = NULL;
	struct user_info *tmp = NULL;


		if(head == NULL){
			head = (struct user_info *)malloc(sizeof(struct user_info));
			tmp  = tail = head;
		}
		tmp->sfd = recv_connect();
		pthread_create(&(tail->pid_t), NULL, deal_with, tail);
		while(1);
	return 0;
}
