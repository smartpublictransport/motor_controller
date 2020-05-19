#include <iostream>
#include <string>
#include <chrono>
#include <mqueue.h>
#include <unistd.h>
#include "../include/motor_controller.h"
#include "../../motor_driver/motor.h"


#define PMODE 0665

MOTOR_STATUS motorStatus;
Motor engine1;


int main ()
{
    motorStatus = IDLE;

    int status;
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize   = 20;
    char buffer[1024] = {0};
    std::string hello = "Hello from server \n";

    //while (true) 
    //{
       mqd_t mqfd = mq_open("/mcontrol", O_RDWR|O_CREAT, PMODE, &attr);
    if (mqfd == -1){
        perror("mq open error");
        exit(0);
    }
    status = mq_receive (mqfd, buffer, 100, 0);
    if (status == -1) {
        perror("mq_send failure\n");
    }
    else {
        std::cout << buffer << std::endl;
        status = mq_send (mqfd, hello.c_str(), hello.length(), 0);
        if (status == -1) {
            perror ("mq_receive failure");
        }
    }
    mq_close(mqfd);
    mq_unlink("/mcontrol");
 

    //}
    return 0;
}
