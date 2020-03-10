#include <iostream>
#include "../include/motor_controller.h"
#include "../../motor_driver/motor.h"

extern MOTOR_STATUS motorStatus;
extern Motor engine1;



MOTOR_STATUS get_motor_status ()
{
    return motorStatus;
}

int init_aceleration ()
{

    if (motorStatus != IDLE) {
        return  -1;
    }
    engine1.set_acceleration(3);
    engine1.set_speed(10);
    motorStatus = RUNNING;
    return 0;
}

int increase_speed( int speed, int acceleration)
{
    engine1.set_acceleration(acceleration);
    engine1.set_speed(speed);
    return 0;
}

int decrease_speed( int speed, int acceleration)
{
    engine1.set_acceleration(acceleration);
    engine1.set_speed(speed);
    return  0;
}

int start_parking ()
{
    engine1.soft_stop();
    return 0;
}

int hard_break()
{
    engine1.hard_stop();
    return 0;
}
