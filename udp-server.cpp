#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<chrono>

#define BUFSIZE 512
#define PORT 8002

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

    int option = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    retval = bind(sock,(sockaddr*)&serveraddr, sizeof(serveraddr));
    if(-1 == retval){
        printf("ERROR");
        exit(1);
    }
    sockaddr_in clientaddr;
    int addrlen;
    char buf[BUFSIZE+1];
    int cnt = 0;
    while(1)
    {
        addrlen = sizeof(clientaddr);
        retval = recvfrom(sock, buf, BUFSIZE, 0, (sockaddr*)&clientaddr,(socklen_t*)&addrlen);
        //auto nanosec_since_epoch_e = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();

        //buf[retval] = '\0';
        
        cout << "[UDP/" << inet_ntoa(clientaddr.sin_addr) << ":" << ntohs(clientaddr.sin_port) << "]" <<endl;
        cout << "Data["<< cnt << "]" << buf << endl;
        cnt++;
        //cout << "Delay: " << nanosec_since_epoch_e << "\n" << endl;
        
    }
}

