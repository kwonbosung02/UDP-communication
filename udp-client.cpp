#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
#include<chrono>
#include<unistd.h>
using namespace std;

#define BUFSIZE 512
#define PORT 8001

int main(void){
        int sock = socket(AF_INET, SOCK_DGRAM, 0);

        sockaddr_in serveraddr;
        memset(&serveraddr, 0, sizeof(serveraddr));

        serveraddr.sin_family = AF_INET;
        serveraddr.sin_port = htons(PORT);
        serveraddr.sin_addr.s_addr = inet_addr("192.168.7.11");
        //serveraddr.sin_addr.s_addr = inet_addr("192.168.7.7");

        int addrlen;
        char buf[BUFSIZE + 1];
        int len;
        int cnt = 0;
        float ch[1];
        ch[0] = 0;
        while(1){
            cout << endl << "[send data]" << endl;

            /*if(fgets(buf, BUFSIZE + 1, stdin) == NULL)
                break;*/
            auto nanosec_since_epoch = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
            
            strncpy(buf,to_string(nanosec_since_epoch).c_str(),sizeof(buf));
            len = strlen(buf);
            if(buf[len-1] == '\n')
                buf[len-1] = '\0';

            if(len == 0)
                break;
            
            int retval;
            std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
            retval = sendto(sock, buf, strlen(buf), 0, (sockaddr*)&serveraddr, sizeof(serveraddr));
            std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
            std::cout << "Data: " << buf << "\n" ;
            std::cout << "Length: " << strlen(buf) << std::endl;
            std::cout << "Delay: " << sec.count() << std::endl;
            
           /*
           int retval;
           
           retval = sendto(sock, ch, 1, 0, (sockaddr*)&serveraddr, sizeof(serveraddr));
           ch[0] += 0.0001;*/
           /*
           if (ch[0] == 0){
               ch[0] = 1;
           }
           else{
               ch[0] = 0;
           }
           */
           //std::cout << "Data: " << ch[0] << "\n" ;
            //sleep(5);
        }

}