#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <error.h>
#include <json-c/arraylist.h>
#include <json-c/json.h>
#include "Func.h"
#include "Print.h"




int main()
{
    int sockfd = 0;
    /* 创建客户端文件描述符 */
    clnSocket(&sockfd, SERVER_PORT, SERVER_IP);
    choice(sockfd);
    close(sockfd);
    return 0;
}