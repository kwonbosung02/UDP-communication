#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>

using namespace std;

#define BUFSIZE 512
#define PORT 8001

int main(void){
        int sock = socket(AF_INET, SOCK_DGRAM, 0);

        sockaddr_in serveraddr;
        memset(&serveraddr, 0, sizeof(serveraddr));

        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port = htons(PORT);
        serveraddr.sin_addr.s_addr = inet_addr("192.168.48.128");

        int addrlen;
        char buf[BUFSIZE + 1];
        int len;

        while(1){
            cout << endl << "[send data]";
            if(fgets(buf, BUFSIZE + 1, stdin) == NULL)
                break;
            len = strlen(buf);
            if(buf[len-1] == '\n')
                buf[len-1] = '\0';

            if(len == 0)
                break;
            
            int retval;
            retval = sendto(sock, buf, strlen(buf), 0, (sockaddr*)&serveraddr, sizeof(serveraddr));

        }

}