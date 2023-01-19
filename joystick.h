#ifndef JOYSTICK_H_
#define JOYSTICK_H_

typedef enum {
    JOYSTICK_UP = 0,
    JOYSTICK_DOWN,
    JOYSTICK_LEFT,
    JOYSTICK_RIGHT,
    JOYSTICK_NO_DIRECTION
} JoystickDirection;

void Joystick_intialize(void);

JoystickDirection Joystick_getDirection(void);

#endif