// joystick.h
// Module to manage joystick
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

// Joystick Directions
typedef enum {
    JOYSTICK_UP = 0,
    JOYSTICK_DOWN,
    JOYSTICK_LEFT,
    JOYSTICK_RIGHT,
    JOYSTICK_DIRECTION_COUNT,
    JOYSTICK_NO_DIRECTION
} JoystickDirection;

// Initialize/cleanup the module's data structures.
void Joystick_intialize(void);
void Joystick_cleanUp(void);

// Get direction of joystick
JoystickDirection Joystick_getDirection(void);

#endif