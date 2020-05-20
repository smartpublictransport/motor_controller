#include "motor_controller.h"
#include <iostream>
#include <string.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <unistd.h>
#include "../../motor_driver/motor.h"

#define PMODE 0665
MOTOR_STATUS motorStatus;
Motor engine1;

int start_aceleration ()
{
#ifdef MSGQ
    int status;
    struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize   = 20;
    std::string hello = "Hello from client";
    char buffer[100] = {0};

    //write/create - attr needed because of O_CREAT
    mqd_t mqfd = mq_open("/mcontrol", O_RDWR|O_CREAT, PMODE, &attr);
    if (mqfd == -1){
        perror("mq open error");
        exit(0);
    }
    status = mq_send (mqfd, hello.c_str(), hello.length(), 0);
    if (status == -1) {
        perror("mq_send failure\n");
    }
    else {
        std::cout << "mq_send successful \n";
        status = mq_receive (mqfd, buffer, 100, 0);
        if (status == -1) {
            perror ("mq_receive failure");
        }
        else { 
            std::cout << buffer << std::endl;
        }
    }
    mq_close(mqfd);
    mq_unlink("/mcontrol");
    return 0;
#endif


    engine1.set_acceleration(3);
    engine1.set_speed(10);
    motorStatus = RUNNING;
    return 0;

}
