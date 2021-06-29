#include "include/project.h"

int main()
{
	struct user_info *head = NULL;
	struct user_info *tail = NULL;
	struct user_info *tmp = NULL;
	while(1){
		if(head == NULL){
			head = (struct user_info *)malloc(sizeof(struct user_info));
			tmp  = tail = head;
		}else{
			tmp        = (struct user_info *)malloc(sizeof(struct user_info));
			tail->next = tmp;
			tail       = tmp;
		}
		if( (tmp->sfd = recv_connect()) < 0)
			continue;
		pthread_create(&(tail->pid_t), NULL, deal_with, tail);
	}
	return 0;
}
