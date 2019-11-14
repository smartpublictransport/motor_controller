#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

//Types

typedef enum {
   OFF,
    IDLE,
    RUNNING,
    ERROR
} MOTOR_STATUS;

MOTOR_STATUS get_motor_status ();

/* API called when POD start moving,  assummes POD is parked*/
int start_aceleration ();


int increase_speed( int speed, int acceleration);


int decrease_speed( int speed, int acceleration);


int start_parking ();


int hard_break();

#endif
