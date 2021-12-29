#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<chrono>


using std::cout; 
using std::endl;

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;

using std::chrono::seconds;
using std::chrono::system_clock;
#define BUFSIZE 512
#define PORT 8001

int main(void){
    
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
        auto nanosec_since_epoch = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        cout << "second since epoch: " << nanosec_since_epoch << endl;
    }


    return 0;
    
}
/*
    auto nanosec_since_epoch = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    auto sec_since_epoch = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    cout << "second since epoch: " << sec_since_epoch << endl;

    cout << "milliseconds since epoch: " << nanosec_since_epoch << endl;
    cout << std::to_string(nanosec_since_epoch * 10e-10);
    
*/