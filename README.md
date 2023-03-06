# Hello World BeagleBone
Test your reaction time with joystick and LED light on the BeagleBone Zencape. Score your best time!

## Installation
1. Clone the repository
```bash
(host)$ git clone https://github.com/Tooo/Hello-World-BeagleBone.git
```

2. Make excutable file on the host
```bash
make
```

3. Run excutable on the BeagleBone
```bash
(bbg)$ ./hello
```

## How to play?
Hello world is a game where the player test their reaction time with a joystick and LED lights
After a random amount of time, either the top or bottom LED light will turn on.
Hit the joystick up or down, depending on which lights turns on.
Your reaction time in miliseconds will be displayed with your best time. 

### Quiting the game
- Press left or right on the joystick. (User Quit)

or
- Don't give joystick inputs for 5 seconds. (Timeout)


## Features
- Test your reaction time with the LED and joystick.
- See different LED flashes, depending if you win or lose.
- Displays your best time in the current session.
- Warns players "too soon" if they are holding a joystick direction.