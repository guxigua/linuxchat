#include "include/project.h"

void local_action_login(struct send_data *data,struct user_info **info)
{
	MYSQL_RES *res_ptr;
        MYSQL_ROW sqlrow;                               //char **
        MYSQL mysql_con;                                //数据库fd，连接描述符
        mysql_init(&mysql_con);                         //初始化
	char arr_query[64] = "select * from data0 where id = '";
	strcat(arr_query, data->account);
	strcat(arr_query, "'");

        if(!mysql_real_connect(&mysql_con, "localhost", "root", "guxigua159708", "test0", 0, NULL, 0))  //连接数据库
        {
                fprintf(stderr, "Failed to connect databases Error is %s \n", mysql_error(&mysql_con));
                mysql_error(&mysql_con);
        }
        mysql_set_character_set(&mysql_con, "utf8");                                                    //设置utf8编码，防止中文乱码



        if(mysql_query(&mysql_con, arr_query))                          /*连接好数据库之后执行mysql语句*/
        {
                fprintf(stderr, "mysql_query error %s\n", mysql_error(&mysql_con));
        }
        else
        {
                res_ptr =       mysql_use_result(&mysql_con);
                if(res_ptr)
                {
                        sqlrow = mysql_fetch_row(res_ptr);               //返回储存结果的结构
			struct send_data temp;
			if( !(strcmp(sqlrow[0], data->account) || strcmp(data->data, sqlrow[1])) ){
				temp.data[0] = 'y';
				strcpy((*info)->account, sqlrow[0]);
				printf("the %s is login successful\n", sqlrow[0]);
			}else{
				temp.data[0] = 'n';
				printf("the %s is login error!\n", sqlrow[0]);
			}
				temp.action = 1;
				write((*info)->sfd, &temp, sizeof(struct send_data));
                }
                mysql_free_result(res_ptr);
        }
}

void local_action_forward(struct send_data *data, struct user_info **info)
{
	pthread_mutex();
}
void local_action(struct send_data *data, struct user_info **info)
{
	switch(data->action){
	case 0:
		break;
		/*连接服务器*/
	case 1:
		local_action_login(data, info);
		break;
		/*登入*/
	case 2:
		local_action_forward(data, info);
		break;
		/*发送信息*/
	case 3:
		/*查看聊天记录*/
		break;
	default:
		break;
	}
}
/*
 * 本地函数依赖函数local_action*
 */


int recv_connect(int sfd)
{
	int acc_fd;
	if(sfd == -1)
		return -1;

	struct sockaddr_in server_message;
	server_message.sin_family      = AF_INET;
	server_message.sin_port	       = htons(SPORT);
	server_message.sin_addr.s_addr = inet_addr(SIP);

	if((acc_fd = accept(sfd, NULL, NULL)) == -1)
		return -4;

	return acc_fd;
}

void *deal_with(void *args)
{
	struct user_info *tmp = (struct user_info *)args;
	struct send_data user_data;
	while(1){
		memset(&user_data, 0, sizeof(struct send_data));
		if(read(tmp->sfd, &user_data, sizeof(struct send_data)) > 0){
			if(user_data.action == 4){  				/*从信息链表中删除自己的节点*/
				pthread_mutex_lock(*(tmp->mutex));
				printf("the %s is quit\n", tmp->account);
				if(tmp->pre == NULL && tmp->next == NULL)
					/*no nothing to do*/;
				else if(tmp->pre == NULL)
					tmp->next->pre =NULL;
				else if(tmp->next == NULL)
					tmp->pre->next = NULL;
				else{
				tmp->next->pre = tmp->pre;
				tmp->pre->next = tmp->next;
				}
				free(tmp);
				pthread_mutex_unlock(*(tmp->mutex));
				return NULL;
			}
			local_action(&user_data, &tmp);
		}
	}
	return NULL;
}

void close_fun(int signo)
{
        if(SIGINT == signo)
        {
		printf("\nbye!\n");
                exit(0);
        }
}
