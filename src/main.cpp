#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../include/motor_controller.h"
#include "../../motor_driver/motor.h"


#define PORT 8080

MOTOR_STATUS motorStatus;
Motor engine1;


int main ()
{
    motorStatus = IDLE;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    std::string hello = "Hello from server \n";
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    while (true) 
    {
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cout << "socket failure \n";
        return -1;
    }
    
    //Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        std::cout << "setsocketopt error \n";
        return -1;
    }


    // Forcefully binding
    if (bind(server_fd, (struct sockaddr *)&address, sizeof (address)) < 0)
    {
        std::cout << "bind failed \n";
        return -1;
    }
    if (listen (server_fd, 3 ) < 0)
    {
        std::cout << "listen failed \n";
        return -1;
    }
    if ((new_socket = accept (server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
    {
        std::cout << "accept failed \n";
        return -1;
    }
       valread = read (new_socket, buffer, 1024);
       std::cout << buffer;
       send(new_socket, (void*)hello.c_str(), hello.length(), 0);
       std::cout << "Hello message sent \n";
       return 0;    std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
