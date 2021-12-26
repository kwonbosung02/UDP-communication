#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>

#define BUFSIZE 512
#define PORT 8080

using namespace std;


int main(){
    //init socket
    int sock = socket(AF_INET,SOCK_DGRAM,0);
    int retval;

    //biniding socket
    sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    

    retval = bind(sock,(sockaddr*)&serveraddr, sizeof(serveraddr));
    if(-1 == retval){
        printf("ERROR");
        exit(1);
    }
    sockaddr_in clientaddr;
    int addrlen;
    char buf[BUFSIZE+1];

    while(1)
    {
        addrlen = sizeof(clientaddr);
        retval = recvfrom(sock, buf, BUFSIZE, 0, (sockaddr*)&clientaddr,(socklen_t*)&addrlen);
        buf[retval] = '\0';

        cout << "[UDP/" << inet_ntoa(clientaddr.sin_addr) << ":" << ntohs(clientaddr.sin_port) << "]" << buf <<endl;
        

    }
}