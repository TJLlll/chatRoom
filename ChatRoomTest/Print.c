#include <stdio.h>
#include "Func.h"

static void Init_Print();
static void menue_print();
static int after_LogOn(int sockfd, char* ID);

static void Init_Print()
{
    printf("--------------------\n");
    printf("|      1.登录      |\n");
    printf("|      2.注册      |\n");
    printf("--------------------\n");
    printf("输入选项:");
}

static void menue_print()
{
    printf("-------------------------------\n");
    printf("|      1.私聊                 |\n");
    printf("|      2.群聊                 |\n");
    printf("|      3.加好友               |\n");
    printf("|      4.查看他人好友请求      |\n");
    printf("|      5.发出的好友请求处理结果 |\n");
    printf("|      6.加群                 |\n");
    printf("|      7.建群                 |\n");
    printf("|      8.退出                 |\n");
    printf("-------------------------------\n");
    printf("输入选项:");
}

static int after_LogOn(int sockfd, char* ID)
{
    while(1)
    {
        system("clear");
        menue_print();
        int Choice = 0;
        scanf("%d", &Choice);
        switch (Choice)
        {
        case 1:
            privateChat(sockfd);
            break;
        case 2:
            GroupChat(sockfd);
            break;
        case 3:
            AddFriend(sockfd, ID);
            break;
        case 4:
            system("clear");
            viewOtherInvite(sockfd);
            break;
        case 5:
            system("clear");
            viewMyInvite(sockfd);
            break;
        case 6:
            system("clear");
            AddGroup(sockfd);
            break;
        case 7:
            system("clear");
            createGroup(sockfd);
            break;
        case 8:
            system("clear");
            logOut(sockfd);
            exit(0);
            break;  
        default:
            break;
        }

    }
    
}

void choice(int sockfd)
{
    while(1)
    {
        Init_Print();

        char buf[COMMUNICATION_SIZE];
        memset(buf, 0, sizeof(buf));

        int choice = 0;
        scanf("%d", &choice);
        userData Mydata;
        switch (choice)
        {
        case 1:
            logon(sockfd, &Mydata);
            after_LogOn(sockfd, Mydata.ID);
            break;
        case 2:
            Register(sockfd, buf);
            break;
        default:
            break;
        }
    }
}