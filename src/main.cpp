#include <chrono>
#include <thread>
#include "../include/motor_controller.h"
#include "../../motor_driver/motor.h"

MOTOR_STATUS motorStatus;
Motor engine1;


int main ()
{
    motorStatus = IDLE;
    while (true) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
